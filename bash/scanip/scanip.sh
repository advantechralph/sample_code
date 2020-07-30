#!/bin/sh
[ -z "$(which fping)" ] && echo "no fping, please install it..." && exit;
#fping -c 1 -t 100 192.168.0.7 > /dev/null 2>&1 && echo $?
_fping(){
  fping -c 1 -t 100 $1 > /dev/null 2>&1 && echo $?
}

_prefix=192.168.0.

for i in $(seq 1 1 254) ; do
  _ip=${_prefix}$i
  [ -n "$(_fping $_ip)" ] && echo $_ip alive!!! && ( \
    nc -vnz -w 1 $_ip 80 ;\
    curl -s -f -o /dev/null  http://$_ip/Cfg.txt && echo "Cfg.txt exists!!" ;\
  )
done

exit 0;
