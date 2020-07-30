# vim: softtabstop=2 ts=2 sw=2 et
#!/bin/bash
echo -ne "google abc\nyahoo abc\n" | sed -e '/google/ b label1 ; { s/abc/Abc/ ; b end ; } ; :label1 { s/abc/aBc/ } ; :end'
echo -ne "111\n222\n333\n"   | sed -e '/111/ b label1; { s/2/a/g; b end;} ; :label1 { s/1/b/g };  :end ; '

s="
/google/ b capitalA #←樣板條件跳躍,如符合'google'則跳躍到 label 'capitalA'
    {
       s/b/B/g
       b end #←無條件跳躍到 label 'end'
    }
:capitalA #←label 'capitalA'
    {
       s/a/A/g
    }
:end #←label 'end'
"

echo -e 'google abc\nyahoo abc' | sed -e "$s"

unset s

s="
/\(google\)/ b label1 
  {
    b end
  }
:label1
  {
    s/\(google\)/\1/
    b end
  }
:end
"

echo -e 'google abc\nyahoo abc' | sed -e "$s"

