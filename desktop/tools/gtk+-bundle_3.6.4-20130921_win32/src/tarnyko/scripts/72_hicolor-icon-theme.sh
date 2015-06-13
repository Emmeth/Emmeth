
cd ../../libs/72_hicolor-icon-theme
tar xfvz hicolor-icon-theme-0.12.tar.gz
cd hicolor-icon-theme-0.12


echo Compile...

./configure --host=i686-pc-mingw32 --enable-static --enable-shared  --prefix="$PREFIX"
make clean
make 2>&1 | tee ../../../z_Install/win32_build/logs/71_hicolor-icon-theme-make.log
make install 2>&1 | tee ../../../z_Install/win32_build/logs/71_hicolor-icon-theme-makeinstall.log


cd ..
rm -rf hicolor-icon-theme-0.12
