#1/bin/bash
#useradd -d /home/dummy -g idiots -m -p $(echo "P4sSw0rD" | openssl passwd -1 -stdin) dummy

user=dummy
pwd=test
userdel $user
pwdEnc=$(echo "$pwd" | openssl passwd -1 -stdin)
echo $pwdEnc
salt=$(echo $pwdEnc | awk -F '$' '{print $3}')
echo $salt
#openssl passwd -1 -salt $salt

useradd $user -m -p $pwdEnc 

