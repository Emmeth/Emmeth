
cd ../../libs/13_libxml2
tar xfvz libxml2-2.8.0.tar.gz
cd libxml2-2.8.0


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared --with-python=no --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/13_libxml2-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/13_libxml2-makeinstall.log


cd ..
rm -rf libxml2-2.8.0
