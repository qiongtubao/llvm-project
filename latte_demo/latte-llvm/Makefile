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

LATTE=latte
LATTE_OBJECTS=latte.o 
default: $(LATTE)

$.o : $(SRC_DIR)/%.cpp 
	@echo Compiling $*.cpp 
	$(QUIET) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(LATTE): $(LATTE_OBJECTS)
	@echo Linking $@
	$(QUIET) $(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ `$(LLVM_CONFIG) --libs bitreader core support` 

clean:
	$(QUIET) rm $(LATTE) $(LATTE_OBJECTS) *.bc

test:$(LATTE)
	$(LLVM_PROJECT_DIR)/llvm/latte/install/bin/clang -c -emit-llvm test.c -o test.bc
	./latte test.bc