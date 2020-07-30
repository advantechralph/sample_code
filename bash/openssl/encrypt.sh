# vim: ts=2 sw=2 et
#!/bin/bash
# echo "message" | openssl enc -aes-256-cbc -a -pass pass:$password
# echo "encmessage" | openssl enc -aes-256-cbc -a -d -pass pass:$password
enc(){
	echo $1 | openssl enc -aes-256-cbc -a -pass pass:$2
}
[ -n "$1" ] && [ -n "$2" ] && enc $1 $2
[ -n "$1" ] && [ -n "$2" ] && echo $1 | openssl enc -aes-256-cbc -a -pass pass:$2
