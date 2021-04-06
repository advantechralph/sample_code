#ifndef __class_h__
#define __class_h__
class SuperClass {
public: 
  SuperClass(int);
  void dump(void);
private:
  int param1;
}; 
class SubClass:SuperClass {
public: 
//  SubClass(int,int):SuperClass(int);
  SubClass(int,int);
  void dump(void);
private:
  int param1;
  int param2;
};
#endif /*__class_h__*/
