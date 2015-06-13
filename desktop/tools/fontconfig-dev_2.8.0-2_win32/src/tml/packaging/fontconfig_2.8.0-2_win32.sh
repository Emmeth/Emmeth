# This is a shell script that calls functions and scripts from
# tml@iki.fi's personal work environment. It is not expected to be
# usable unmodified by others, and is included only for reference.

MOD=fontconfig
VER=2.8.0
REV=2
ARCH=win32

THIS=${MOD}_${VER}-${REV}_${ARCH}

RUNZIP=${MOD}_${VER}-${REV}_${ARCH}.zip
DEVZIP=${MOD}-dev_${VER}-${REV}_${ARCH}.zip

# We use a string of hex digits to make it more evident that it is
# just a hash value and not supposed to be relevant at end-user
# machines.
HEX=`echo $THIS | md5sum | cut -d' ' -f1`
TARGET=c:/devel/target/$HEX

usestable
usemsvs6

(

set -x

EXPAT=`latest --arch=${ARCH} expat`
FREETYPE=`latest --arch=${ARCH} freetype`

# Don't let libtool do its relinking dance. Don't know how relevant
# this is, but it doesn't hurt anyway.

sed -e 's/need_relink=yes/need_relink=no # no way --tml/' <ltmain.sh >ltmain.temp && mv ltmain.temp ltmain.sh

patch -p0 <<\EOF &&
--- src/Makefile.in
+++ src/Makefile.in
@@ -620,6 +620,7 @@
 # gcc import library install/uninstall
 
 @OS_WIN32_TRUE@install-libtool-import-lib: 
+@OS_WIN32_TRUE@	$(mkdir_p) $(DESTDIR)$(libdir)
 @OS_WIN32_TRUE@	$(INSTALL) .libs/libfontconfig.dll.a $(DESTDIR)$(libdir)
 @OS_WIN32_TRUE@	$(INSTALL) fontconfig.def $(DESTDIR)$(libdir)/fontconfig.def
 
EOF

lt_cv_deplibs_check_method='pass_all' \
CC='gcc -mthreads' \
LDFLAGS='-Wl,--enable-auto-image-base' \
CFLAGS=-O2 \
./configure \
--with-expat="/devel/dist/${ARCH}/${EXPAT}" \
--with-freetype-config="/devel/dist/${ARCH}/${FREETYPE}/bin/freetype-config" \
--prefix=c:/devel/target/$HEX  \
--with-confdir=c:/devel/target/$HEX/etc/fonts \
--disable-static &&

PATH="/devel/dist/${ARCH}/${EXPAT}/bin:$PATH" make install &&

(cd /devel/target/$HEX/lib && lib.exe -machine:IX86 -def:fontconfig.def -out:fontconfig.lib) &&

sed -e "s/@VERSION@/$VER/" <fontconfig-zip.in >fontconfig-zip.in.tem && mv fontconfig-zip.in.tem fontconfig-zip.in &&

./config.status --file=fontconfig-zip &&
./fontconfig-zip &&

mv /tmp/$MOD-$VER.zip /tmp/$RUNZIP &&
mv /tmp/$MOD-dev-$VER.zip /tmp/$DEVZIP

cd /devel/target/$HEX &&
zip /tmp/$DEVZIP bin/fc-cat.exe
zip /tmp/$DEVZIP lib/fontconfig.lib

) 2>&1 | tee /devel/src/tml/packaging/$THIS.log

(cd /devel && zip /tmp/$DEVZIP src/tml/packaging/$THIS.{sh,log}) &&
manifestify /tmp/$RUNZIP /tmp/$DEVZIP
