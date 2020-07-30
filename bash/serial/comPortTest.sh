#!/bin/bash
# After run -> screen /dev/ttyUSB0 9600
tty=/dev/ttyUSB0
# Redirect tty input/output to fd
exec 4<$tty 5>$tty
echo -ne "AT\r\n" >&5
echo -ne "read AT command reply..."
read -t 5  reply <&4
echo -ne "\nreply: $reply\n"
echo -ne "read AT command reply..."
read -t 5  reply <&4
echo -ne "\nreply: $reply\n"
exec 4<&- 5<&-
