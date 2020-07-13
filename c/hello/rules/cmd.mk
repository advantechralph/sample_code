define createcmd
  logT=$(builddir)/$(2)-$$(date +"%F_%T").log; \
  log=$(builddir)/$(2).log; \
  rm -rf \$${logT}; \
  ln -sf \$${logT} \$${log}; \
  exec > >(tee -i -a \$${logT}); \
  exec 2>&1; \
  set -x; \
  date +"%F_%T"; \
  $(1); \
  date +"%F_%T"; \
  exit 0; 
endef
