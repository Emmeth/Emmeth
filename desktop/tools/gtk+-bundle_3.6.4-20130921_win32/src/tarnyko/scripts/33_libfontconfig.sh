
cd ../../libs/33_libfontconfig
tar xfvz fontconfig-2.10.2.tar.gz
cd fontconfig-2.10.2


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared --enable-libxml2 --disable-docs --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/33_libfontconfig-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/33_libfontconfig-makeinstall.log


cd ..
rm -rf fontconfig-2.10.2
