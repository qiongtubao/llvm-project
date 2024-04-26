
make 
会得到一个latte可执行文件

./latte -help
./latte -version

clang -c -emit-llvm test.c -o test.bc 
./latte test.bc