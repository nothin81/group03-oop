@echo off
setlocal
cd /D "%~dp0"

set "FILE1=data\movies.txt"
set "FILE2=data\cinemas.txt"
set "FILE3=data\bookings.txt"

echo Kiem tra va tao cac file du lieu can thiet...

if not exist "%FILE1%" (
    echo Tao file moi: %FILE1%
    type nul > "%FILE1%"
) else (
    echo File da ton tai: %FILE1%
)

if not exist "%FILE2%" (
    echo Tao file moi: %FILE2%
    type nul > "%FILE2%"
) else (
    echo File da ton tai: %FILE2%
)

if not exist "%FILE3%" (
    echo Tao file moi: %FILE3%
    type nul > "%FILE3%"
) else (
    echo File da ton tai: %FILE3%
)

if exist "build\online-cinema-ticket.exe" (
    .\build\online-cinema-ticket.exe
) else (
    echo LOI: Khong tim thay binary "build\online-cinema-ticket.exe".
    echo Vui long build.
)

endlocal
pause