
cd ../../libs/71_icon-naming-utils
tar xfvj icon-naming-utils-0.8.90.tar.bz2
cd icon-naming-utils-0.8.90


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/71_icon-naming-utils-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/71_icon-naming-utils-makeinstall.log


cd ..
rm -rf icon-naming-utils-0.8.90
