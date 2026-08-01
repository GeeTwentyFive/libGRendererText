setlocal EnableDelayedExpansion
set "LIBS="
for /r "../libs" %%i in (*_windows.a) do set "LIBS=!LIBS! "%%i""
c++ -O2 -march=x86-64-v2 -I ../libs ../_EXAMPLE.cpp -o _EXAMPLE.exe !LIBS!