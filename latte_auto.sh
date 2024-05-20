LLVM_PROJECT_PATH=$(pwd)
echo $LLVM_PROJECT_PATH
mkdir -p llvm/latte/build llvm/latte/install
cd llvm/latte/build
$LLVM_PROJECT_PATH/llvm/configure --disable-optimized --prefix=$LLVM_PROJECT_PATH/llvm/latte/install
make  VERBOSE=1 && make install
mkdir -p llvm/latte/install/include/llvm/Support/Unix
cp llvm/lib/Support/Unix/Host.inc llvm/latte/install/include/llvm/Support/Unix
cp llvm/lib/Support/Unix/Unix.h llvm/latte/install/include/llvm/Support/Unix