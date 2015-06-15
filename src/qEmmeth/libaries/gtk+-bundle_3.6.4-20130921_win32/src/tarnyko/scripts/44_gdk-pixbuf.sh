
cd ../../libs/44_gdk-pixbuf
tar xfvJ gdk-pixbuf-2.26.5.tar.xz
cd gdk-pixbuf-2.26.5


echo Putting some needed utilies in the right place, do not make clean

cp ../../../z_Install/cache/gdk-pixbuf-query-loaders ./gdk-pixbuf/


echo Compile...

./configure --host=i686-pc-mingw32 --with-included-loaders --enable-static --enable-shared --disable-glibtest --prefix="$PREFIX"
#make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/44_gdk-pixbuf-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/44_gdk-pixbuf-makeinstall.log


cd ..
rm -rf gdk-pixbuf-2.26.5
