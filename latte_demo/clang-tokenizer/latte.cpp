extern "C" {
    #include "clang-c/Index.h"
}

#include "llvm/Support/CommandLine.h"
#include <iostream>

using namespace llvm;

//按顺序注册到cl里用来解析命令行
static cl::opt<std::string>
FileName(cl::Positional, cl::desc("Input file"), cl::Required);

// static cl::opt<int>
// Line(cl::Positional, cl::desc("Line Number"), cl::Required);


int main(int argc, char** argv) {
    //解析程序命令行参数 （--help）
    cl::ParseCommandLineOptions(argc, argv, "tokenizer Example");
    // std::cout << FileName.c_str() << std::endl;
    // std::cout << Line << std::endl;
    CXIndex index = clang_createIndex(0, 0);
    const char *args[] = {
        "-I/usr/include",
        "-I."
    };
    //解析
    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, FileName.c_str(), args, 2, NULL, 0, CXTranslationUnit_None);
    //
    CXFile file = clang_getFile(translationUnit, FileName.c_str());
    //分析器的开始
    CXSourceLocation loc_start = clang_getLocationForOffset(translationUnit, file, 0);
    //分析器的结尾
    CXSourceLocation loc_end = clang_getLocationForOffset(translationUnit, file, 60);
    //创建范围
    CXSourceRange range = clang_getRange(loc_start, loc_end);
    unsigned numTokens = 0;
    CXToken *tokens = NULL;
    //运行词法分析器 并为我们返回一个记号流
    //返回tokens 和个数
    clang_tokenize (translationUnit, range, &tokens, &numTokens);
    for (unsigned i = 0; i < numTokens; ++i) {
        //遍历
        //获得token类型
        enum CXTokenKind kind = clang_getTokenKind(tokens[i]);
        //获得对应的字符串
        CXString name = clang_getTokenSpelling(translationUnit, tokens[i]);
        switch (kind) {
            case CXToken_Punctuation:
                std::cout << "PUNCTUATION(" << clang_getCString(name) << ") ";
                break;
            case CXToken_Keyword:
                std::cout << "KEYWORD(" << clang_getCString(name) << ") ";
                break;
            case CXToken_Identifier:
                std::cout << "IDENTIFIER(" << clang_getCString(name) << ") ";
                break;
            case CXToken_Literal:
                std::cout << "COMMENT(" << clang_getCString(name) << ") ";
                break;
            default:
                std::cout << "UNKNOWN(" << clang_getCString(name) << ") ";
                break;
        }
        clang_disposeString(name);
    }
    std::cout << std::endl;
    clang_disposeTokens(translationUnit, tokens, numTokens);
    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
    return 0;

}