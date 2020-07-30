#!/bin/bash
certfile=${1:-MyRootCA}
openssl genrsa -out ${certfile}.key 2048
openssl req -x509 -new -nodes -key ${certfile}.key -sha256 -days 1024 -out ${certfile}.pem -subj "/C=TW/ST=Taipei/L=Taipei/O=Company Name/OU=Org/CN=www.example.com"

openssl genrsa -out ${certfile}Client.key 2048
openssl req -new -key ${certfile}Client.key -out ${certfile}Client.csr -subj "/C=TW/ST=Taipei/L=Taipei/O=Company Name/OU=Org/CN=www.exampleclient.com"

openssl x509 -req -in ${certfile}Client.csr -CA ${certfile}.pem -CAkey ${certfile}.key -CAcreateserial -out ${certfile}Client.pem -days 1024 -sha256
