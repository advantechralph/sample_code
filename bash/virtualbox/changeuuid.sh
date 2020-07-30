#!/bin/bash

[ -n "$1" ] && ( \
  VBoxManage internalcommands sethduuid "$1" \
)

