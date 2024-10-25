./build.sh
cp ./out/NumberCorridor ./NumberCorridor/usr/bin
dpkg-deb --build --nocheck ./NumberCorridor ./out/NumberCorridor.deb
dpkg-deb --info ./out/NumberCorridor.deb