
cd ../../libs/61_libcroco
tar xfvJ libcroco-0.6.8.tar.xz
cd libcroco-0.6.8


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/61_libcroco-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/61_libcroco-makeinstall.log


cd ..
rm -rf libcroco-0.6.8
