LOG=1
ifdef LOG
MAKELOG= 2>&1 | tee log.make
endif
all:
	@scons -Q $(MAKELOG)
clean:
	-@scons -c -Q $(MAKELOG)
	@rm -rf build .sconsign.dblite
