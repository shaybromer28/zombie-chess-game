//
//  Bullet.h
//  SeniorProject
//
//  Created by Shay Bromer on 4/8/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#ifndef __SeniorProject__Bullet__
#define __SeniorProject__Bullet__

#include <iostream>

class Bullet
{
private:
    int x;
    int y;
    int display;

public:
    int getDisplay ();
    void setDisplay (int d);
    int getX ();
    void setX (int num);
    int getY ();
    void setY (int num);
    void draw ();
    bool isActive;
    void init ();
};

#endif /* defined(__SeniorProject__Bullet__) */
