LLVM_PROJECT_PATH=$(shell pwd)

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
uname_M := $(shell sh -c 'uname -m 2>/dev/null || echo not')
LATTE_OBJS=

ifeq ($(uname_S),Linux)
	LATTE_OBJS=libcxx
endif

./deps/gcc/latte/install/bin/gcc:
	cd deps && $(MAKE) gcc
	
gcc: 
	echo "build gcc"

./deps/dragonegg: ./deps/gcc/latte/install/bin/gcc
	cd deps && $(MAKE) dragonegg 

libcxx/latte/install/libcxx.a: gcc 
	mkdir -p libcxx/latte/build libcxx/latte/install 
	cd libcxx/latte/build && CC=$(LLVM_PROJECT_PATH)/llvm/latte/install/bin/clang CXX=$(LLVM_PROJECT_PATH)/llvm/latte/install/bin/clang++ cmake -DLIBCXX_CXX_ABI=libstdc++ -DLIBCXX_LIBSUPCXX_INCLUDE_PATHS="$(LLVM_PROJECT_PATH)/deps/gcc/latte/install/include/c++/4.7.4;$(LLVM_PROJECT_PATH)/deps/gcc/latte/install/include/c++/4.7.4/x86_64-unknown-linux-gnu" -DCMAKE_INSTALL_PREFIX="$(LLVM_PROJECT_PATH)/libcxx/latte/install" ../../ && make

libcxx: libcxx/latte/install/libcxx.a
	echo "build libcxx"

./llvm/latte/install/bin/clang: $(LATTE_OBJS)
	mkdir -p llvm/latte/build llvm/latte/install
	cd llvm/latte/build && ../../configure --disable-optimized --prefix=$(LLVM_PROJECT_PATH)/llvm/latte/install && $(MAKE) && $(MAKE) install 



all: ./llvm/latte/install/bin/clang
	echo "build llvm"