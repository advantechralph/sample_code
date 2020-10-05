
.PHONY: test

test: $(builddir)/.fetch_deb $(builddir)/.patch_deb

test2: $(builddir)/.build_deb

