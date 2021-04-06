LOG=1
ifdef LOG
MAKELOG= 2>&1 | tee log.make
endif
.PHONY: all build clean
all: build

build: 
	@ctags `ls *.cpp`
#	@scons -Q $(MAKELOG)
	@scons -Q --toolchain=gnu $(MAKELOG)

run:
	@./build/gnu/prog "ooo xxx 111 222"

clean:
#	-@scons -c -Q $(MAKELOG)
	-@scons -c -Q --toolchain=gnu $(MAKELOG)
	@rm -rf build .sconsign.dblite log.* tags
