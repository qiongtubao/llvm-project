LLVM_PROJECT_DIR := $(shell sh -c 'readlink -f ../../')
LLVM_CONFIG?=$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/llvm-config 
CXX=$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/clang++

ifndef VERBOSE
QUIET:=@
endif 

SRC_DIR?=$(PWD)
LDFLAGS+=$(shell $(LLVM_CONFIG) --ldflags)
COMMON_FLAGS=-Wall -Wextra
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags)
CPPFLAGS+=$(shell $(LLVM_CONFIG) --cppflags) -I$(SRC_DIR)

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

PROJECT=latte
PROJECT_OBJECTS=latte.o 

default: $(PROJECT)

%.o: $(SRC_DIR)/%.cpp
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

$(PROJECT): $(PROJECT_OBJECTS)
	@echo Linking $@
	$(QUIET)$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(CLANGLIBS) $(LLVMLIBS)

clean:
	$(QUIET)rm -f $(PROJECT) $(PROJECT_OBJECTS)

test:$(PROJECT)
	latte ./test.c
