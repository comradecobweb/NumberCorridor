mkdir -p build-linux
cd ..
cmake -S ./NumberCorridor -B ./NumberCorridor/build-linux
cd ./NumberCorridor
cmake --build ./build-linux --config Release
chmod +x ./out/NumberCorridor