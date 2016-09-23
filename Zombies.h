//
//  Zombies.h
//  SeniorProject
//
//  Created by Shay Bromer on 3/21/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#ifndef __SeniorProject__Zombies__
#define __SeniorProject__Zombies__

#include <iostream>

//enum direction {Right,Left,Up,Down};

class Zombies
{
private:
    int row;//current row of the zombie
    int column;//current column of the zombie
    int display;//used to store display list
    int type;//used to determine behavior 
    
public:
    Zombies ();
    Zombies (int t, int r, int c);
    int getRow ();
    int getColumn ();
    void setRow (int r);
    void setColumn (int c);
    int getDisplay ();
    void setDisplay (int d);
    int getType ();
    void setType (int t);
    bool isActive;
    void init ();
};
#endif /* defined(__SeniorProject__Zombies__) */
