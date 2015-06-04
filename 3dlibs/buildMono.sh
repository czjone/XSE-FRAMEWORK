mkdir ~/Build
cd ~/Build
curl -O ftp://ftp.gnu.org/gnu/m4/m4-1.4.17.tar.gz
curl -O ftp://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.gz
curl -O ftp://ftp.gnu.org/gnu/automake/automake-1.14.tar.gz
curl -O ftp://ftp.gnu.org/gnu/libtool/libtool-2.4.2.tar.gz
for i in *.tar.gz; do tar xzvf $i; done
for i in */configure; do (cd `dirname $i`; ./configure --prefix=$PREFIX && make &&
rm -rf ~/Build
tar -xf mono-4.0.1.tar.gz
cd pkgconfig-0.17.2
./configure
make
make install
tar -xf mono-4.0.1.tar.gz
#cd fltk-1.3.3
#mkdir fltk
#cd fltk
#mkdir include
#mkdir libs
#mkdir demo
#cd ..
#./configure --enable-threads --libdir=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/libs --includedir=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/include --prefix=/Users/chenzejun/Documents/netDesk/MyCodes/XSE-PROJECT/3dlibs/fltk-1.3.3/fltk/demo 
#make
#make install
