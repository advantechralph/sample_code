#include <string>
#include "Ball.h"
using namespace std;

// 預設建構函式
Ball::Ball() {
    _radius = 0.0; 
    _name = "noname ball"; 
}

Ball::Ball(double radius, const char *name) { 
    _radius = radius; 
    _name = name;
}

Ball::Ball(double radius, string &name) { 
    _radius = radius; 
    _name = name;
}

double Ball::radius() { 
    return _radius; 
} 

double Ball::volumn() { 
    return (4 / 3 * 3.14159 * _radius * _radius * _radius); 
} 

string& Ball::name() { 
    return _name; 
} 

void Ball::radius(double radius) { 
    _radius = radius; 
} 

void Ball::name(string &name) { 
    _name = name; 
}

void Ball::name(const char *name) { 
    _name = name; 
}
