#查看内核
## 1. Darwin  (macos)
## 2. Linux
##     a. CentOS7   (lsb_release -a)
## 3. SunOS
## 4. AIX
## 5. OpenBSD
## 6. NetBSD
## 7. FreeBSD
## 8. DragonFly
## 9. NetBSD
## 10. Haiku

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

#硬件架构
## 1. arm 
##    a. arm64 (macos m1)
##    b. armv6
##    c. armv7 
##	  d. armv7s
##    e. armv8
##    f. armv64
##    g. armv7l
##    h. armv6l
## 2. x86_64 (x86 64位)
## 3. i386 
## 4. aarch64 


uname_M := $(shell sh -c 'uname -m 2>/dev/null || echo not')
LATTE_CLANGE_LIB=
ifeq ($(uname_M), x86_64)
	LATTE_CLANGE_LIB=-isysroot  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
endif


all:
	/Users/zhouguodong/Documents/github/llvm-project/llvm/latte/install/bin/clang -S -m32 latte.c -o test-32bit.S $(LATTE_CLANGE_LIB)