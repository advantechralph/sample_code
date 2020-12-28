#!/bin/bash

dev_ip=$1
dev_ip=${dev_ip:-172.17.9.190}
delay=$2
delay=${delay:-10}

nw_ping(){
  ping -c 1 -W 1 $1  > /dev/null 2>&1
  echo $?
}

count=0

while true; do
  ret=
  ret=$(nw_ping $dev_ip)
  if [ $ret -eq 0 ] ; then
    count=$(($count + 1))
    echo nw_ping ok, then exec ${count} times...
    sleep $delay
    ssh $dev_ip systemctl reboot 
  fi
  sleep 3; 
done

