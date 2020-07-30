#!/bin/bash
commands=${1:-"
#comments
BEGIN{
  FS=\":\"
}
{
  print \$1
}
END{
}
"}
text=${2:-"
111 222 333
a:b:c
"}
echo commands=$commands
set -x
awk "${commands}" << EOF
$text
EOF
