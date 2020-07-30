# vim: softtabstop=2 ts=2 sw=2 et
#!/bin/bash

func(){
  printf "%s: %d\n"  $FUNCNAME $BASH_LINENO; 
}

func
