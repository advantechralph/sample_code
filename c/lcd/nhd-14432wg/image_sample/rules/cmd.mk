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
  ret=\$$?; \
  [ ! \$$ret -eq 0 ] && exit \$$ret; \
  date +"%F_%T";
endef
