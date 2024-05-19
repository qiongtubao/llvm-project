``` bash

 "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/clang" "-cc1" "-triple" "x86_64-unknown-linux-gnu" "-emit-obj" "-mrelax-all" "-disable-free" "-main-file-name" "latte.c" "-mrelocation-model" "static" "-mdisable-fp-elim" "-fmath-errno" "-masm-verbose" "-mconstructor-aliases" "-munwind-tables" "-fuse-init-array" "-target-cpu" "x86-64" "-target-linker-version" "2.38" "-resource-dir" "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/../lib/clang/3.4.2" "-internal-isystem" "/usr/local/include" "-internal-isystem" "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/../lib/clang/3.4.2/include" "-internal-externc-isystem" "/usr/include/x86_64-linux-gnu" "-internal-externc-isystem" "/include" "-internal-externc-isystem" "/usr/include" "-fdebug-compilation-dir" "/home/dong/Documents/latte/latte-llvm-project/latte_demo/clang" "-ferror-limit" "19" "-fmessage-length" "123" "-mstackrealign" "-fobjc-runtime=gcc" "-fdiagnostics-show-option" "-fcolor-diagnostics" "-vectorize-slp" "-o" "/tmp/latte-881321.o" "-x" "c" "latte.c"
 "/usr/bin/ld" "--eh-frame-hdr" "-m" "elf_x86_64" "-dynamic-linker" "/lib64/ld-linux-x86-64.so.2" "-o" "latte" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crt1.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crti.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/crtbegin.o" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../../lib64" "-L/lib/x86_64-linux-gnu" "-L/lib/../lib64" "-L/usr/lib/x86_64-linux-gnu" "-L/usr/lib/../lib64" "-L/usr/lib/x86_64-linux-gnu/../../lib64" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../.." "-L/lib" "-L/usr/lib" "/tmp/latte-881321.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/crtend.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crtn.o"

 ```

 ---
 
 make test
Severity: 4 File: /usr/include/stdio.h Line: 33 Col: 10 Category: "Lexical or Preprocessor Issue" Message: 'stddef.h' file not found


---
make min 

/home/dong/Documents/latte/llvm-project/llvm/latte/install/bin/clang -cc1 -dump-tokens min.c
//使用clang/Basic/TokenKinds.def找到
//int，if 都属于KEYWORD， KEYWORD(X,Y) TOK(kw_ ## X)
int 'int'	 [StartOfLine]	Loc=<min.c:1:1>
//identifier 是不匹配保留字符串的前缀，属于TOK
identifier 'min'	 [LeadingSpace]	Loc=<min.c:1:5>
//l_paren是（的前缀 ，属于PUNCTUATOR  ，PUNCTUATOR(X,Y) TOK(X)
l_paren '('		Loc=<min.c:1:8>
int 'int'		Loc=<min.c:1:9>
identifier 'a'	 [LeadingSpace]	Loc=<min.c:1:14>
comma ','		Loc=<min.c:1:15>
int 'int'	 [LeadingSpace]	Loc=<min.c:1:17>
identifier 'b'	 [LeadingSpace]	Loc=<min.c:1:21>
r_paren ')'		Loc=<min.c:1:22>
l_brace '{'	 [LeadingSpace]	Loc=<min.c:1:24>
if 'if'	 [StartOfLine] [LeadingSpace]	Loc=<min.c:2:5>
l_paren '('	 [LeadingSpace]	Loc=<min.c:2:8>
identifier 'a'		Loc=<min.c:2:9>
less '<'	 [LeadingSpace]	Loc=<min.c:2:11>
identifier 'b'	 [LeadingSpace]	Loc=<min.c:2:13>
r_paren ')'		Loc=<min.c:2:14>
return 'return'	 [StartOfLine] [LeadingSpace]	Loc=<min.c:3:9>
identifier 'a'	 [LeadingSpace]	Loc=<min.c:3:16>
semi ';'		Loc=<min.c:3:17>
return 'return'	 [StartOfLine] [LeadingSpace]	Loc=<min.c:4:5>
identifier 'b'	 [LeadingSpace]	Loc=<min.c:4:12>
semi ';'		Loc=<min.c:4:13>
r_brace '}'	 [StartOfLine]	Loc=<min.c:5:1>
eof ''		Loc=<min.c:5:2>
