#!/bin/bash
_strToHex(){
  printf "%s" "$1" | xxd -ps 
}

# p=61, q=53
p=61
q=53
n=$(echo "${p}*${q}" | bc)
Pi_n=$[($p-1)*($q-1)]
# Pi_n, e mutual prime
e=17
# (e*d)%Pi_n=1
# e*d-k*Pi_n=1
i=1
for i in $(seq $[${Pi_n}/${e}] 1 $[${Pi_n}/${e}+10000]) ; do 
#  echo $[$[(${e}*${i})]%${Pi_n}]
  if [ "$[(${e}*${i})%$Pi_n]" == "1"  ] ; then
    d=$i
    break; 
  fi
done
# n=3233，e=17，d=2753
# n: 共有, e: 加密的公鑰, d: 解密私鑰
printf "p=%d, q=%d, n=%d, Pi_n=%d, e=%d, d=%d\n" "$p" "$q" "$n" "$Pi_n" "$e" "$d"
# encrypted / decrypted
m=78
c=$(echo "(${m}^${e})%${n}" | bc)
m_ans=$(echo "(${c}^${d})%${n}" | bc)
printf "c=%d, m=%d\n" "$c" "$m_ans"

