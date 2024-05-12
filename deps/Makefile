

./gcc/latte/install/bin/gcc:
	cd gcc && git submodule init && git submodule update && $(MAKE) -f latte.mk all

gcc:./gcc/latte/install/bin/gcc
	echo "build gcc"

dragonegg: ./gcc/latte/install/bin/gcc
	cd dragonegg && $(MAKE) 