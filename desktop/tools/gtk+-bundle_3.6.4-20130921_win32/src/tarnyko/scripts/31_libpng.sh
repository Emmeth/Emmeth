
cd ../../libs/31_libpng
tar xfvJ libpng-1.5.14.tar.xz
cd libpng-1.5.14


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/31_libpng-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/31_libpng-makeinstall.log


cd ..
rm -rf libpng-1.5.14
