@echo off
cl.exe /nologo /std:c11 /permissive /Wall /TC cmt.h /D COMPILE_AS_TEST /Fe"test.exe"
test.exe
del *.obj
del test.exe
