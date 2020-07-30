#!/bin/bash
certfile=${1:-MyRootCA}
# with password
#openssl req -x509 -newkey rsa:4096 -keyout ${certfile}.key -out ${certfile}.pem -days 365 -subj '/CN=localhost'
# without password
openssl req -x509 -newkey rsa:4096 -keyout ${certfile}.key -out ${certfile}.pem -days 365 -subj '/CN=localhost' -nodes
# add subjects
#-subj "/C=US/ST=Oregon/L=Portland/O=Company Name/OU=Org/CN=www.example.com"
# basic usage
#openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 

