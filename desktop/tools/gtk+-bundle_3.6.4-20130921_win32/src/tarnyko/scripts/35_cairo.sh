
cd ../../libs/35_cairo
tar xfvz cairo-1.10.2.tar.gz
cd cairo-1.10.2


echo Patching source to avoid build problem and to correct images flickering problem on Win32

cd ..
patch -p0 < cairo-1.10.2-win32_ffs.patch
patch -p0 < cairo-1.10.2-win32_surfaces.patch
cd cairo-1.10.2

echo Compile...

./configure --host=i686-pc-mingw32 --enable-win32=yes --enable-win32-font=yes --enable-png=yes --enable-ft=yes --enable-fc=yes --enable-xlib=no --enable-static --enable-shared --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/35_cairo-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/35_cairo-makeinstall.log

echo Manually copying cairo.def to its intended location...

cp src/cairo.def "$PREFIX/lib"


cd ..
rm -rf cairo-1.10.2
