//
//  Zombies.cpp
//  SeniorProject
//
//  Created by Shay Bromer on 3/21/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#include <OpenGl/gl.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265f
#include "Zombies.h"

//get methods
int Zombies :: getRow () {return row;}
int Zombies :: getColumn () {return column;}
int Zombies :: getDisplay () {return display;}
int Zombies :: getType () {return type;}

//set methods
void Zombies :: setRow (int r) {
    if (-1 < r && r < 8)
        row = r;
}
void Zombies :: setColumn (int c) {
    if (-1 < c && c < 8)
        column = c;
}

void Zombies :: setDisplay (int d) {display = d;}
void Zombies :: setType (int t) {type = t;}

Zombies :: Zombies (){}

Zombies :: Zombies (int t, int r, int c)
{
    setType (t);
    setRow (r);
    setColumn (c);
    isActive = true;
}

void Zombies :: init ()
{
    float centerX = -0.875f;
    float centerY = -0.8;
    setDisplay (10);
    glNewList (getDisplay (), GL_COMPILE);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 360; i++)
    {
        glVertex2f(centerX + sin(i) * 0.03f, centerY + cos(i) * 0.03f);
    }
    glEnd();
    
    glEnable (GL_LINE_SMOOTH);
    glLineWidth (6.0f);
    glBegin (GL_LINES);
    glVertex2f (centerX, centerY);
    glVertex2f (centerX, centerY - 0.1f);
    glVertex2f (centerX, centerY - 0.1f);
    glVertex2f (centerX - 0.04f, centerY - 0.175f);
    glVertex2f (centerX, centerY - 0.1f);
    glVertex2f (centerX + 0.04f, centerY - 0.175f);
    glVertex2f (centerX, centerY - 0.035f);
    glVertex2f (centerX + 0.045f, centerY - 0.1f);
    glVertex2f (centerX, centerY - 0.025f);
    glVertex2f (centerX + 0.06f, centerY - 0.045f);
    glEnd ();
    glEndList ();

    isActive = true;
}
