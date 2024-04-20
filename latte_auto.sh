LLVM_PROJECT_PATH=$(pwd)
echo $LLVM_PROJECT_PATH
mkdir -p llvm/latte/build llvm/latte/install
cd llvm/latte/build
$LLVM_PROJECT_PATH/llvm/configure --disable-optimized --prefix=$LLVM_PROJECT_PATH/llvm/latte/install
make && make install