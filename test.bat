@echo off
cl.exe /nologo /std:c11 /permissive /W4 /TC test.c cmt.c /Fe"test.exe"
test.exe
del *.obj
del test.exe
