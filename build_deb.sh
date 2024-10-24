./build.sh
cp ./NumberCorridor ./DEBIAN
dpkg-deb --build --nocheck ./ NumberCorridor.deb
dpkg-deb --info ./NumberCorridor.deb