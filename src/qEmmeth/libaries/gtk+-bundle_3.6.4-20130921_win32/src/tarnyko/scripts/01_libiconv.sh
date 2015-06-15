
cd ../../libs/01_libiconv
tar xfvz libiconv-1.13.1.tar.gz
cd libiconv-1.13.1


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/01_libiconv-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/01_libiconv-makeinstall.log


cd ..
rm -rf libiconv-1.13.1
