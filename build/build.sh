c++ -O2 -march=x86-64-v2 -I ../libs -c ../libGRendererText.cpp &&
for lib in $(find ../libs -name "*_linux.a"); do ar x "$lib"; done &&
ar rcs libGRendererText_linux.a *.o; rm *.o