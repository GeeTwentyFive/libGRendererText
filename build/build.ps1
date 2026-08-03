c++ -O2 -march=x86-64-v2 -I ../libs -c ../libGRendererText.cpp -o libGRendererText.o
@"
CREATE libGRendererText_windows.a
ADDMOD libGRendererText.o
$((Get-ChildItem -Path ../libs -Filter "*_windows.a" -Recurse | ForEach-Object {"ADDLIB $($_.FullName)"}) -join "`n")
SAVE
END
"@ | ar -M
rm libGRendererText.o