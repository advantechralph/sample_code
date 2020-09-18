#!/usr/bin/env python
#print dir()
#print dir("__builtins__")
import os
#import traceback
#if os.access("output", os.R_OK) ==  True : 
#  os.remove("output");
try: 
  os.remove("output");
except: 
  print "output not exist..."
#  traceback.print_exc()
f=open("output","a");
f.write("ooxx");
f.seek(0,0);
f.seek(0,2);
len=f.tell();
print("len: %d"%len);
f.close();
