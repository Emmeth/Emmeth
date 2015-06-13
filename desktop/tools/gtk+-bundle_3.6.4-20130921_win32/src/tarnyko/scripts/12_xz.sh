
cd ../../libs/12_xz
tar xfvj xz-5.0.4.tar.bz2
cd xz-5.0.4


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/12_xz-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/12_xz-makeinstall.log


cd ..
rm -rf xz-5.0.4
