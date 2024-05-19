#include "llvm/IR/LLVMContext.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/system_error.h"
#include <iostream>

using namespace llvm;
static cl::opt<std::string> FileName(cl::Positional, cl::desc("Bitcodefile"), cl::Required);

int main(int argc, char** argv) {
    cl::ParseCommandLineOptions(argc, argv, "LLVM hello world\n");
    LLVMContext context;
    std::string error;
    OwningPtr<MemoryBuffer> mb;
    MemoryBuffer::getFile(FileName, mb);
    Module *m = ParseBitcodeFile(mb.get(), context, &error);
    if (m == 0) {
        std::cerr << "Error reading bitcode: " << error << std::endl;
        return -1;
    }
    raw_os_ostream O(std::cout);
    for (Module::const_iterator i = m -> getFunctionList().begin(), e = m->getFunctionList().end(); i != e; ++i) {
        if(!i -> isDeclaration()) {
            O << i->getName() << " has " << i->size() << " basic block(s).\n";
        }
    }
    return 0;
}