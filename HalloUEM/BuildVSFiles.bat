rmdir /s/q Binaries
del HalloUEM.sln
"C:\Program Files\Epic Games\UE_4.19\Engine\Binaries\DotNET\UnrealBuildTool.exe" -projectfiles -project="%cd%\HalloUEM.uproject" -game -rocket -progress
