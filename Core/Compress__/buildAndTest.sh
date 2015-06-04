sh modify.sh
tar xf zlib-1.2.8.tar
cd zlib-1.2.8
./configure
make
cd ..
./configure
make
mkdir build

cp -rf zlib-1.2.8/libz.a build/compress
cp -rf include build/include
#cp -rf zlib-1.2.8/zlib.h build/include/zlib.h
#cp -rf zlib-1.2.8/zconf.h build/include/zconf.h

echo "* *begin test"
echo "test compress result:"
./Compress compress
echo "end test"


cp -rf Compress build/Compress
sh clean.sh

