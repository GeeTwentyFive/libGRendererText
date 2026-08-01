c++ -O2 -march=x86-64-v2 -I ../libs -c ../libGRendererText.cpp
for /r "../libs" %%i in (*_windows.a) do ar x %%i
for %%i in (*.o) do ar rcs libGRendererText_windows.a %%i
del *.o