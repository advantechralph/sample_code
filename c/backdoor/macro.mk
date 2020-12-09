currdir=$(shell pwd)
builddir=${currdir}/build
SHELL=/bin/bash

targets=bd_svr bd_cli

bd_svr_target=bd_svr
bd_svr_srcs=
bd_svr_srcs+=$(foreach s,tools cmd_tools socket_tools handle,$(wildcard srcs/$(s)/*.c))
bd_svr_srcs+=srcs/svr.c
bd_svr_cc=$(CROSS_COMPILE)gcc
bd_svr_cflags=-Wall -Iinc
bd_svr_ldflags=

bd_cli_target=bd_cli
bd_cli_srcs=
bd_cli_srcs+=$(foreach s,tools cmd_tools socket_tools handle,$(wildcard srcs/$(s)/*.c))
bd_cli_srcs+=srcs/cli.c
bd_cli_cc=$(CROSS_COMPILE)gcc
bd_cli_cflags=-Wall -Iinc
bd_cli_ldflags=

