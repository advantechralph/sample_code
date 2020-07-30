#!/bin/bash
certfile=${1:-MyRootCA}
openssl genrsa -out ${certfile}.key 2048
openssl req -x509 -new -nodes -key ${certfile}.key -sha256 -days 1024 -out ${certfile}.pem -subj "/C=TW/ST=Taipei/L=Taipei/O=Company Name/OU=Org/CN=www.example.com"
