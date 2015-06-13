
cd ../../libs/32_libfreetype
tar xfvj freetype-2.4.11.tar.bz2
cd freetype-2.4.11


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/32_libfreetype-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/32_libfreetype-makeinstall.log


cd ..
rm -rf freetype-2.4.11
