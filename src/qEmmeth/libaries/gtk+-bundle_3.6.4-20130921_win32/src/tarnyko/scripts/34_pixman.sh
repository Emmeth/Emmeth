
cd ../../libs/34_pixman
tar xfvz pixman-0.26.0.tar.gz
cd pixman-0.26.0


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/34_pixman-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/34_pixman-makeinstall.log


cd ..
rm -rf pixman-0.26.0
