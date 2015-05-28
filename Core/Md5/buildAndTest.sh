sh modify.sh
./configure
make
echo "* *begin test"
echo "test md5Tools result:"
./md5Tool md5Tool
echo "end test"
sh clean.sh

