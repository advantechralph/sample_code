LOG=1
ifdef LOG
MAKELOG= 2>&1 | tee log.make
endif
.PHONY: all clean run
all:
	@ctags -R `pwd`
#	@scons -Q $(MAKELOG)
	@scons -Q --toolchain=gnu $(MAKELOG)
clean:
#	-@scons -c -Q $(MAKELOG)
	-@scons -c -Q --toolchain=gnu $(MAKELOG)
	@rm -rf build .sconsign.dblite log.* tags
run:
	@./build/gnu/prog | tee log.run
