mkdir build-windows
cd ..
cmake -S .\NumberCorridor -B .\NumberCorridor\build-windows -G "MinGW Makefiles"
cd .\NumberCorridor
cmake --build .\build-windows --config Release
move /Y .\out\Release\NumberCorridor.exe .\out\NumberCorridor.exe
rmdir .\out\Release