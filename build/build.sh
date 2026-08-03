c++ -O2 -march=x86-64-v2 -I ../libs -c ../libGRendererText.cpp -o libGRendererText.o &&
ar -M <<EOF
CREATE libGRendererText_linux.a
ADDMOD libGRendererText.o
$(for lib in $(find ../libs -name "*_linux.a"); do echo "ADDLIB $lib"; done)
SAVE
END
EOF
rm libGRendererText.o