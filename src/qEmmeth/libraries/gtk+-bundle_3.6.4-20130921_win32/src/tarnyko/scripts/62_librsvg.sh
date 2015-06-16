
cd ../../libs/62_librsvg
tar xfvJ librsvg-2.36.4.tar.xz
cd librsvg-2.36.4


echo Warning, the main script should have taken care of putting required native
echo utils like gdk-pixbuf-query-loaders in an accessible path. Otherwise, it will fail.

echo Compile...

./configure --host=i686-pc-mingw32 --disable-gtk-theme --enable-introspection=no --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/62_librsvg-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/62_librsvg-makeinstall.log


cd ..
rm -rf librsvg-2.36.4
