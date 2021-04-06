
.PHONY: $(builddir) 
$(builddir): 
	@mkdir -p $@

.PHONY: clean
clean: 
	@rm -rf $(builddir)
