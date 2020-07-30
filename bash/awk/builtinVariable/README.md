
#### 8 Powerful Awk Built-in Variables – FS, OFS, RS, ORS, NR, NF, FILENAME, FNR

** FS & RS **

All FS and RS are sperator, but RS is bigger range for FS. 

ex: 
```
awk '
BEGIN{
  FS="\n";
  RS="\n\n";
}
{
  print $1
}
' << EOF
111 222 333
444 555
666

a b c d
e f g h


oooo vvvv gggg
ssss tttt uuuu vvvv 
wwww xxxx yyyy zzzz 
kkkk llll mmmm


EOF

```


