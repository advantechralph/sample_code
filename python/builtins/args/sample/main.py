
def argTest1(*args):
    print "argTest1(*args)..."
    print "type(**args): %s"%(type(args))
    for v in args:
        print v

def argTest2(**args):
    print "argTest2(**args)..."
    print "type(**args): %s"%(type(args))
#    for k in args:
#        print "key: %s, value: %s"%(k, args[k])
    for k, v in args.items():
        print "key: %s, value: %s"%(k, v)

argTest1(0,1,2,3);
argTest2(a=0,b=1,c=2,d=3);


