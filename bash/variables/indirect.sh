# vim: softtabstop=2 ts=2 sw=2 et
#!/bin/bash
aaa=bbb
bbb=yaya
echo '${!aaa}: '"${!aaa}"
echo -ne 'eval "echo \$${aaa}": '
eval "echo \$${aaa}"

