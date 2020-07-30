#!/bin/bash

[ -n $1 ] && ( 7z x $1 ${@:2} ) 
