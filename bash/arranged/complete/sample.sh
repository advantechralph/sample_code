#!/bin/bash

cat << EOF

# add completion 'cmdOOXX'
$ complete -W "111 222 333" cmdOOXX

$ cmdOOXX <tab>

111 222 333

# print 'cmdOOXX' completion
$ complete -p cmdOOXX

# remove 'cmdOOXX' completion
$ complete -r cmdOOXX

# register completion function
$ source func

EOF
