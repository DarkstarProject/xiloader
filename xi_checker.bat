@ECHO OFF

CLS

:: Exit Codes
:: -1 - variable used for server not found
:: -2 - DirectPlay not installed
:: -3 - POL path not found
:: -4 - xiloader not in POL path

IF %1.==. (
    @ECHO Server not provided:
    @ECHO xiloader dankstar.server.biz
    EXIT /B -1
)

SETLOCAL ENABLEEXTENSIONS

:: Find DirectPlay
FOR /F "usebackq skip=2 tokens=3*" %%A IN (`REG QUERY "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Component Based Servicing\Notifications\OptionalFeatures\DirectPlay" /v Selection 2^>nul`) DO (
    SET DIRECT_PLAY=%%A
)

IF NOT DEFINED DIRECT_PLAY (
    @ECHO DirectPlay not installed, install via Turning On/Off Windows Features
    EXIT /B -2
)

:: Find and set POL_PATH
SET POL_PATH_REGKEYS=(HKEY_LOCAL_MACHINE\SOFTWARE\PlayOnlineUS HKEY_LOCAL_MACHINE\SOFTWARE\PlayOnlineEU HKEY_LOCAL_MACHINE\SOFTWARE\PlayOnlineJP HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\PlayOnlineUS HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\PlayOnlineEU HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\PlayOnlineJP)
SET INSTALL_FOLDER=\InstallFolder
set POL_PATH_VALUE=1000
SET POL_PATH=

FOR %%I IN %POL_PATH_REGKEYS% DO (
    FOR /F "usebackq skip=2 tokens=3*" %%A IN (`REG QUERY "%%I%INSTALL_FOLDER%" /v %POL_PATH_VALUE% 2^>nul`) DO (
        SET POL_PATH=%%A
        GOTO PATH_FOUND
    )
)

:PATH_FOUND
IF DEFINED POL_PATH (
    IF EXIST "%POL_PATH%\xiloader.exe" (
        START /d "%POL_PATH%" xiloader --server %1
    ) ELSE (
        @ECHO xiloader.exe not found in POL path
        @ECHO Copy xiloader.exe to %POL_PATH%
        EXIT /B -4
    )
) ELSE (
    @ECHO POL path not found.
    EXIT /B -3
)
