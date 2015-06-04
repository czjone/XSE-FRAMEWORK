tar -xf fltk-1.3.3-source.tar.gz
cd fltk-1.3.3
mkdir fltk
cd fltk
mkdir include
mkdir libs
mkdir demo
cd ..
./configure --enable-threads --libdir=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/libs --includedir=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/include --prefix=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/demo 
make
make install
