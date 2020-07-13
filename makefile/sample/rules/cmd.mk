
define debugcmd
  exec > >(tee -i -a $(builddir)/$(if $(2),log$(shell echo $(2) | sed -e 's/^.*\///'),log.$(shell date +"%F_%T"))); exec 2>&1; set -x; $(1)
endef

define logncmd
  logT=$(builddir)/$(2)-$$(date +"%F_%T").log; \
  log=$(builddir)/$(2).log; \
  rm -rf \$${logT}; \
  ln -sf \$${logT} \$${log}; \
  exec > >(tee -i -a \$${logT}); \
  exec 2>&1; \
  set -x; \
  $(1); \
  exit 0; 
endef

