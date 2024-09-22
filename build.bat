mkdir build-windows
cd ..
cmake -S .\NumberCorridor -B .\NumberCorridor\build-windows
cd .\NumberCorridor
cmake --build .\build-windows --config Release
cd ..
move /Y .\NumberCorridor\Release\NumberCorridor.exe .\NumberCorridor
cd .\NumberCorridor
rmdir .\Release