#!/bin/bash
echo -ne "User??\n\n"
read usr
echo -ne "Password?\n\n"
read -s pwd
# 1. Login name
loginName=${usr}
# 2. Encrypted password (-1: MD5)
encPwd=$(echo "$pwd" | openssl passwd -1 -stdin)
# 3. Date of last password change
dateLastChange=$(echo $(($(date -d now "+%s") / 86400)))
# 4. Minimum password age
minPwdAge=0
# 5. Maximum password age
maxPwdAge=99999
# 6. Password warning period
pwdWarningPeriod=7
# 7. Password inactivity period
pwdInactPeriod=
# 8. Account expiration date
accountExpireDate=
# 9. Reserved field
reserveField=


echo $loginName:$encPwd:$dateLastChange:$minPwdAge:$maxPwdAge:$pwdWarningPeriod:$pwdInactPeriod:$accountExpireDate:$reserveField
