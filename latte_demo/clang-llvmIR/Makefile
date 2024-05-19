LLVM_PROJECT_DIR := $(shell sh -c 'readlink -f ../../')
LLVM_CONFIG?=$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/llvm-config 
CXX=$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/clang++
CC=$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/clang

ifndef VERBOSE
QUIET:=@
endif 

SRC_DIR?=$(PWD)
LDFLAGS+=$(shell $(LLVM_CONFIG) --ldflags)
COMMON_FLAGS= 
#-Wall -Wextra
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags) -fno-rtti
CPPFLAGS+=$(shell $(LLVM_CONFIG) --cppflags) -I$(SRC_DIR)
# SYSLIBS=$(shell $(LLVM_CONFIG) --cflags )

CLANGLIBS = \
	-Wl,--start-group\
	-lclang\
	-lclangFrontend\
	-lclangDriver\
	-lclangSerialization\
	-lclangParse\
	-lclangSema\
	-lclangAnalysis\
	-lclangEdit\
	-lclangAST\
	-lclangLex\
	-lclangBasic\
	-Wl,-rpath=$(LLVM_PROJECT_DIR)/llvm/latte/install/lib\
	-Wl,--end-group
LLVMLIBS=$(shell $(LLVM_CONFIG) --libs)
SYSTEMLIBS=$(shell $(LLVM_CONFIG) --system-libs)

PROJECT=latte
PROJECT_OBJECTS=latte.o 

default: $(PROJECT)

%.o: $(SRC_DIR)/%.cpp
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

$(PROJECT): $(PROJECT_OBJECTS)
	@echo Linking $@
	@echo "$(QUIET)$(CXX)  -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(CLANGLIBS) $(LLVMLIBS) $(SYSTEMLIBS)"
	$(QUIET)$(CXX)  -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(CLANGLIBS) $(LLVMLIBS) $(SYSTEMLIBS)

clean:
	$(QUIET)rm -f $(PROJECT) $(PROJECT_OBJECTS)

test:
	@echo $(LDFLAGS)
	$(CXX) -cc1  -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -g   -I/home/dong/Documents/github/llvm-project/llvm/latte/install/include test.cpp -o test

min:
	$(CC) -cc1 -dump-tokens min.c

lex:$(PROJECT)
	./latte ./lex.c