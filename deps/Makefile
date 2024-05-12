LLVM_DEPS_PATH=$(shell pwd)

./gcc/latte/install/bin/gcc:
	cd gcc && git submodule init && git submodule update && $(MAKE) -f latte.mk all

gcc:./gcc/latte/install/bin/gcc
	echo "build gcc"


dragonegg-3.3.src/dragonegg.so: ./gcc/latte/install/bin/gcc ../llvm/latte/install/bin/llvm-config
	cd dragonegg-3.3.src && GCC=$(LLVM_DEPS_PATH)/gcc/latte/install/bin/gcc LLVM_CONFIG=$(LLVM_DEPS_PATH)/../llvm/latte/install/bin/llvm-config LATTE_INCLUDE=-I$(LLVM_DEPS_PATH)/gcc/deps/gmp/latte/install/include/ make 

dragonegg: dragonegg-3.3.src/dragonegg.so 
	echo "dragonegg build"