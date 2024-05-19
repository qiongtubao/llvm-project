#include "llvm/Support/Host.h"
#include "llvm/Support/CommandLine.h"
#include <iostream>

int main() {
    std::string result = llvm::sys::getDefaultTargetTriple();

    std::cout << result << std::endl;
    return 0;
}