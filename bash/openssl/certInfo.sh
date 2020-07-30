#!/bin/bash

certfile=${1:-cert}

cat $certfile | openssl x509 -text -noout
openssl x509 -text -noout -in $certfile

