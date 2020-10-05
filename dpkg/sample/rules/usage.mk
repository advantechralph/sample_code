
define bar
$(shell printf "#%.0s" {1..47}; echo)
endef

define usage_str

$(call bar)
 MIC-710GS Kernel Update Debian Package
$(call bar)

Usage: 

  make deb

sample package tree: 

  sample
  ├── boot
  │   └── Image.new             # install dummy kernel image file in /boot
  ├── DEBIAN                    # DEBIAN package folder
  │   ├── control               # package information
  │   ├── postinst              # run script after installation. 
  │   ├── postrm                # run script after uninstallation. 
  │   ├── preinst               # run script before installation. 
  │   └── prerm                 # run script before unstallation. 
  └── etc                       # install files in /etc
      └── deb_sample

endef
export usage_str

usage help: 
	@echo "$${usage_str}" | more

