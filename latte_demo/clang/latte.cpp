extern "C" {
    #include "clang-c/Index.h"
}
#include "llvm/Support/CommandLine.h"
#include <iostream>

using namespace llvm;

//第2个参数是文件名？
static cl::opt<std::string>
FileName(cl::Positional, cl::desc("Input file"), cl::Required);

int main(int argc, char** argv) {
    //解析程序命令行参数 （--help）
    cl::ParseCommandLineOptions(argc, argv, "Diagnostics Example");
    //建立索引 使用的顶层上下文结构
    //第一个参数  如果要从预编译头文件（PCH）中排除声明(不懂)
    //第二个参数  如果要显示诊断
        //如果设置为true 会显示出`/usr/include/stdio.h:33:10: fatal error: 'stddef.h' file not found`
    //由于我们想要自己显示诊断信息 所以2个参数都设置为false（0,0）
    CXIndex index = clang_createIndex(0, 0);
    const char *args[] = {
        "-I/usr/include",
        "-I."
    };
    //解析翻译单元 接受要解析的元文件的名称作为参数
    //参数1 上下文
    //参数2 文件名
    //参数3 依赖引入文件
    //参数4 args的长度
    //官方 https://clang.llvm.org/doxygen/group__CINDEX__TRANSLATION__UNIT.html#ga2baf83f8c3299788234c8bce55e4472e
    //检查完了
    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, FileName.c_str(), args, 2, NULL, 0, CXTranslationUnit_None);
    
    //检索解析此文件时生成的诊断信息的数目，并确定循环边界
    unsigned diagnosticCount = clang_getNumDiagnostics(translationUnit);
    for(unsigned i = 0; i < diagnosticCount; ++i) {
        //检索当前的诊断
        CXDiagnostic diagnostic = clang_getDiagnostic(translationUnit, i);
        //读取诊断类型的字符串
        CXString category = clang_getDiagnosticCategoryText(diagnostic);
        //检索要向用户展示的信息
        CXString message = clang_getDiagnosticSpelling(diagnostic);
        //检索表示诊断严重性的各种情况（NOTE，WARNING，EXTENSION，EXTWARN，ERROR）
        unsigned serverity = clang_getDiagnosticSeverity(diagnostic);
        //检索诊断发生时准确的代码位置
        CXSourceLocation loc = clang_getDiagnosticLocation(diagnostic);
        CXString fName;
        unsigned line = 0, col = 0;
        //解析出文件名，第几行，第几个
        clang_getPresumedLocation(loc, &fName, &line, &col);
        std::cout << "Severity: " << serverity << " File: "
                    << clang_getCString(fName) << " Line: "
                    << line << " Col: " << col << " Category: \""
                    << clang_getCString(category) << "\" Message: "
                    << clang_getCString(message) << std::endl;
        //释放字符串
        clang_disposeString(fName);
        clang_disposeString(message);
        clang_disposeString(category);
        clang_disposeDiagnostic(diagnostic);
    }
    //释放解析单元
    clang_disposeTranslationUnit(translationUnit);
    //释放上下文
    clang_disposeIndex(index);
    return 0;
}