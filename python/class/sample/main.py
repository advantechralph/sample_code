class Person:
    def __init__(self, fname="", lname="noname"):
        self.fname=fname; 
        self.lname=lname; 
    def info(self):
        print "Name: {0} {1}".format(self.fname, self.lname);
m1=Person("Ralph","Wang");
print "Member 1"
print " ",
m1.info();

class Employee(Person):
    def __init__(self, number=0, fname="", lname="noname"):
        Person.__init__(self, fname=fname, lname=lname);
        #??? super(Employee,self).__init__(fname,lname);
        #self.fname=fname;
        #self.lname=lname; 
        self.number=number;
    def info(self):
        print "Employee: "
        print "  Number: {0}".format(self.number);
        print "  Name: {0} {1}".format(self.fname, self.lname);

m1=Employee(9671, "Ralph", "Wang")

m1.info()


