echo copy_dll.bat
if %Configuration%==Debug (
    echo -^> copy "%third_part%\bin\" to "%SolutionDir%%Configuration%\"
    copy /Y %third_part%\bin\test_d.dll %SolutionDir%%Configuration%\ >nul
) else if %Configuration%==Release (
    echo -^> copy "%third_part%\bin\" to "%SolutionDir%%Configuration%\"
    copy /Y %third_part%\bin\test.dll %SolutionDir%%Configuration%\ >nul
) else (
    echo Error
)