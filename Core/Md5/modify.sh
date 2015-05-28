sh clean.sh

# todo:: 目前src不支持更深的子目录

excName="md5Tool"
srcPath=src
srcFiles=""

function read_dir(){
    for file in `ls $1`
    do
        if [ -d $1"/"$file ]  #注意此处之间一定要加上空格，否则会报错
        then
            read_dir $1"/"$file
        else
        srcFiles=${srcFiles}" "$1"/"$file
    fi
    done
}
read_dir ${srcPath}
echo ${srcFiles}

autoscan
cp configure.scan configure.ac
#for linux
#sed -i "s/\[FULL\-PACKAGE\-NAME\]/str/g" configure.ac
#for mac x 取消备份
sed -i '' "s/\[FULL\-PACKAGE\-NAME\]/${excName}/g" configure.ac
sed -i '' "s/\[VERSION\]/1.0/g" configure.ac
sed -i '' "s/\[BUG-REPORT-ADDRESS\]/czjone@126.com/g" configure.ac
sed -i '' "s/AC_CONFIG_SRCDIR/AM_INIT_AUTOMAKE\(${excName},1\.0\) \\
AC_CONFIG_SRCDIR/g" configure.ac
sed -i '' "s/AC_OUTPUT/AC_CONFIG_FILES([Makefile]) \\
AC_OUTPUT/g" configure.ac

aclocal
echo "UTOMAKE_OPTIONS = foreign  
bin_PROGRAMS = ${excName}  
#noinst_PROGRAMS
#${excName}_SOURCES = src/main.cpp src/md5.cpp
${excName}_SOURCES = ${srcFiles}
${excName}_CPPFLAGS    = -I include/" >Makefile.am
#sleep 1
autoconf
autoheader
touch NEWS
touch README
touch AUTHORS
touch ChangeLog
Automake --add-missing