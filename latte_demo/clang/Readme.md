``` bash

 "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/clang" "-cc1" "-triple" "x86_64-unknown-linux-gnu" "-emit-obj" "-mrelax-all" "-disable-free" "-main-file-name" "latte.c" "-mrelocation-model" "static" "-mdisable-fp-elim" "-fmath-errno" "-masm-verbose" "-mconstructor-aliases" "-munwind-tables" "-fuse-init-array" "-target-cpu" "x86-64" "-target-linker-version" "2.38" "-resource-dir" "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/../lib/clang/3.4.2" "-internal-isystem" "/usr/local/include" "-internal-isystem" "/home/dong/Documents/latte/latte-llvm-project/llvm/latte/install/bin/../lib/clang/3.4.2/include" "-internal-externc-isystem" "/usr/include/x86_64-linux-gnu" "-internal-externc-isystem" "/include" "-internal-externc-isystem" "/usr/include" "-fdebug-compilation-dir" "/home/dong/Documents/latte/latte-llvm-project/latte_demo/clang" "-ferror-limit" "19" "-fmessage-length" "123" "-mstackrealign" "-fobjc-runtime=gcc" "-fdiagnostics-show-option" "-fcolor-diagnostics" "-vectorize-slp" "-o" "/tmp/latte-881321.o" "-x" "c" "latte.c"
 "/usr/bin/ld" "--eh-frame-hdr" "-m" "elf_x86_64" "-dynamic-linker" "/lib64/ld-linux-x86-64.so.2" "-o" "latte" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crt1.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crti.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/crtbegin.o" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../../lib64" "-L/lib/x86_64-linux-gnu" "-L/lib/../lib64" "-L/usr/lib/x86_64-linux-gnu" "-L/usr/lib/../lib64" "-L/usr/lib/x86_64-linux-gnu/../../lib64" "-L/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../.." "-L/lib" "-L/usr/lib" "/tmp/latte-881321.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/crtend.o" "/usr/lib/gcc/x86_64-linux-gnu/7.5.0/../../../x86_64-linux-gnu/crtn.o"

 ```

 ---
 
 make test
Severity: 4 File: /usr/include/stdio.h Line: 33 Col: 10 Category: "Lexical or Preprocessor Issue" Message: 'stddef.h' file not found
