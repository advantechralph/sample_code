#!/bin/bash

echo "ibase=16;100000;obase=10;" | bc
echo $[$(echo "ibase=16;100000;obase=10;" | bc)/512]

