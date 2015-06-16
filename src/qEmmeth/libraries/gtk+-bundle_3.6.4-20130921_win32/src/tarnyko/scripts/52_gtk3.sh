
cd ../../libs/52_gtk3
tar xfvJ gtk+-3.6.4.tar.xz
cd gtk+-3.6.4


echo Save current compiler flags for later restoration

export CFLAGS_SAVE="$CFLAGS"
export CPPFLAGS_SAVE="$CPPFLAGS"

echo Default Windows version on MinGW is NT4...
echo We need to redefine it as XP, as code uses XP-specific APIs

export CFLAGS="$CFLAGS -DWINVER=0x0501"
export CPPFLAGS="$CPPFLAGS -DWINVER=0x0501"

cd ..

echo Patch makefile to NOT build Unix-only gtk-launch

patch -p0 < gtk+-3.6.4-win32_gtk-launch.patch

echo Patch GtkAssistant text to be readable with gray background
echo Bugzilla 696171

patch -p0 < gtk+-3.6.4-win32_gtkassistant.patch

echo Patch GtkNotebook tabs to render correctly
echo thanks to Andy Spencer, Bugzilla 691678

patch -p0 < gtk+-3.6.4-win32_gtknotebook.patch

echo Patch GtkSpinner to animate again with win32 theme
echo thanks to Martin Schlemmer, Bugzilla 696202

patch -p0 < gtk+-3.6.4-win32_gtkspinner.patch

cd gtk+-3.6.4


echo Putting some needed utilies in the right place, do no do make clean

cp ../../../z_Install/cache/gtk-update-icon-cache ./gtk/
cp ../../../z_Install/cache/gtk-query-immodules-3.0 ./gtk/


echo Compile...

./configure --host=i686-pc-mingw32 --enable-win32-backend --with-included-immodules --disable-glibtest --enable-static --enable-shared --prefix="$PREFIX"
#make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/52_gtk3-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/52_gtk3-makeinstall.log


echo Restore original compiler flags

export CFLAGS="$CFLAGS_SAVE"
export CPPFLAGS="$CPPFLAGS_SAVE"
unset CFLAGS_SAVE
unset CPPFLAGS_SAVE


cd ..
rm -rf gtk+-3.6.4
