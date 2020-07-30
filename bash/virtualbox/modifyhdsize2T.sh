#!/bin/bash

[ -n "$1" ] && ( \
  VBoxManage  modifymedium "$1" --resize 2097152 \
)

