
cd ../../libs/74_gnome-icon-theme-symbolic
tar xfvJ gnome-icon-theme-symbolic-3.6.2.tar.xz
cd gnome-icon-theme-symbolic-3.6.2


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/73_gnome-icon-theme-symbolic-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/73_gnome-icon-theme-symbolic-makeinstall.log


cd ..
rm -rf gnome-icon-theme-symbolic-3.6.2
