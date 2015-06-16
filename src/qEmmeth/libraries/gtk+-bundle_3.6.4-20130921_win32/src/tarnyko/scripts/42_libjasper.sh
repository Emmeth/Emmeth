
cd ../../libs/42_libjasper
unzip -o jasper-1.900.1.zip
cd jasper-1.900.1


echo Patching source to avoid the undefined reference to sleep problem

cd ..
patch -p0 < jasper-1.900.1-win32_sleep.patch
cd jasper-1.900.1

echo Configure...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"

echo Fix libtool to allow undefined symbols and build the DLL

mv libtool libtool.old
cp ../libtool libtool

echo Compile...

make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/42_libjasper-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/42_libjasper-makeinstall.log


cd ..
rm -rf jasper-1.900.1
