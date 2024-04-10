1. 把clang-tools-extra移到clang/tools
2. 把clang移动到llvm/tools
3. 在llvm中mkdir latte和 mkdir latte/build  和latte/install
4. cd latte/build 中 /home/dong/Documents/github/llvm-project/llvm/configure --disable-optimized --prefix=/home/dong/Documents/github/llvm-project/llvm/latte/install