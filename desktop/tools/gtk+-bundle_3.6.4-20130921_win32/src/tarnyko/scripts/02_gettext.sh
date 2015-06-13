
cd ../../libs/02_gettext
tar xfvz gettext-0.18.2.1.tar.gz
cd gettext-0.18.2.1


echo Patching source for multiple definition of towlover and other problems

cd ..
patch -p0 < gettext-towlower.patch
cd gettext-0.18.2.1

echo Save current compiler flags for later restoration

CFLAGS_SAVE="$CFLAGS"
CPPFLAGS_SAVE="$CPPFLAGS"
LDFLAGS_SAVE="$LDFLAGS"

echo Add compiler flag needed to export needed po_lex_iconv symbol

export CFLAGS="$CFLAGS -DHAVE_ICONV"
export CPPFLAGS="$CPPFLAGS -DHAVE_ICONV"

echo Add compiler flag needed to avoid some undefined references while linking

export CFLAGS="$CFLAGS -O2"
export CPPFLAGS="$CPPFLAGS -O2"

echo Add linker flag needed to avoid some undefined references while linking

export LDFLAGS="$LDFLAGS -liconv"


echo Compile...

./configure --host=i686-pc-mingw32 --without-libxml2-prefix --enable-static --enable-shared --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/02_gettext-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/02_gettext-makeinstall.log

echo Restore original compiler flags

export CFLAGS="$CFLAGS_SAVE"
export CPPFLAGS="$CPPFLAGS_SAVE"
export LDFLAGS="$LDFLAGS_SAVE"
unset CFLAGS_SAVE
unset CPPFLAGS_SAVE
unset LDFLAGS_SAVE


cd ..
rm -rf gettext-0.18.2.1
