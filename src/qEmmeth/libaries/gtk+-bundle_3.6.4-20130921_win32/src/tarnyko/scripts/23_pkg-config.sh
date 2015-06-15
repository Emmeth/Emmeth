
cd ../../libs/23_pkg-config
tar xfvz pkg-config-0.28.tar.gz
cd pkg-config-0.28


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/23_pkg-config-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/23_pkg-config-makeinstall.log


cd ..
rm -rf pkg-config-0.28
