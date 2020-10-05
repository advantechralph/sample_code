
deb: $(builddir)/.fetch_deb $(builddir)/.patch_deb $(builddir)/.build_deb 
	
$(builddir)/.fetch_deb: $(builddir)
	@cp -a sample $(builddir)
	@touch $@

$(builddir)/.patch_deb: $(builddir)
	@sed -i "s/__name__/$(name)/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__version__/$(version)/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__revision__/$(revision)/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__arch__/$(arch)/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__desc__/$${desc}/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__editor__/$${editor}/" $(builddir)/sample/DEBIAN/*
	@sed -i "s/__depends__/$${depends}/" $(builddir)/sample/DEBIAN/*
#	@sed -i "s/__desc__/$(desc)/" $(builddir)/sample/DEBIAN/*
#	@sed -i "s/__editor__/$(editor)/" $(builddir)/sample/DEBIAN/*
#	@sed -i "s/__depends__/$(depends)/" $(builddir)/sample/DEBIAN/*
	@touch $@

$(builddir)/.build_deb: $(builddir)
	@dpkg --build $(builddir)/sample $(builddir) | tee $(builddir)/build_deb.log 2>&1

$(builddir)/.install_deb: 
	@[ -f "$(builddir)/$(name)_$(version)-$(revision)_$(arch).deb" ] && dpkg --install $(builddir)/$(name)_$(version)-$(revision)_$(arch).deb

install_deb: $(builddir)/.install_sample

uninstall_deb: 
	@dpkg --remove $(name)

purge_deb:
	@dpkg --purge $(name)

# $(builddir) $(trydir):
# 	@mkdir -p $@

# clean: 
# 	@dpkg --purge $(name) >/dev/null 2>&1
# 	@rm -rf $(builddir)

