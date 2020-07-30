# vim: softtabstop=2 ts=2 sw=2 et
#!/bin/bash
a=( "111" "222" "333" "444" "555" )
echo ${a[@]: -3:2}
echo ${a[@]:1:2}
echo ${a[1]}

#set -- $(echo "111 222 333 444 555 666" | sed 's/ //')
set -- `echo -ne "111\n222\n333\n"`
echo $@
echo $#

unset a
a="aaa bbb ccc ddd eee  "
a=( $(echo $a | sed 's/ /\n/g') )
echo ${a[@]}
echo ${#a[@]}

unset a
declare -A a
a=( [xxx]=yaya [yyy]=ooxx ) 
echo '${a[xxx]}='"${a[xxx]}"
echo '${a[yyy]}='"${a[yyy]}"


