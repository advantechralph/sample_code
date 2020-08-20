
define prependpath
  $(foreach f,$(1),$(2)/$(f))
endef

