//
//  Bullet.cpp
//  SeniorProject
//
//  Created by Shay Bromer on 4/8/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#include <OpenGl/gl.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265f
#include "Bullet.h"

//get methods
int Bullet :: getDisplay () {return display;};
int Bullet :: getX (){return x;}
int Bullet :: getY (){return y;}

//set methods
void Bullet :: setDisplay (int d) {display = d;}
void Bullet :: setX(int num){x = num;}
void Bullet :: setY(int num){y = num;}

void Bullet :: init ()
{
    float centerX = -0.875f;
    float centerY = -0.8;
    setDisplay (11);
    glNewList (getDisplay (), GL_COMPILE);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 360; i++)
    {
        glVertex2f(centerX + sin(i) * 0.04f, centerY + cos(i) * 0.04f);
    }
    glEnd();
    glEndList ();
    isActive = false;
}
