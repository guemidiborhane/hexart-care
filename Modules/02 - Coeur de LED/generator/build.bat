@echo off
gcc main.c menu.c generateCode.c -o ../../RunTool.exe
echo Executable generated in the root folder
TIMEOUT 1