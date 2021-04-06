#ifndef __football_h__
#define __football_h__
#include <string>
#include "Ball.h"
using namespace std;
class football : public Ball {
public:
    football(){
    }
    football(double r, const char *n):Ball(r,n){
    }
    football(double r, string& n):Ball(r,n){
    }
};
#endif
