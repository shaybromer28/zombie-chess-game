//
//  Chess.cpp
//  SeniorProject
//
//  Created by Shay Bromer on 3/17/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#include "Chess.h"

//get methods
type Chess :: getPieceType () {return pieceType;}
int Chess :: getRow () {return row;}
int Chess :: getColumn () {return column;}
int Chess :: getPawnDisplay () {return pawnDisplay;};
int Chess :: getBishopDisplay () {return bishopDisplay;};
int Chess :: getCastleDisplay () {return castleDisplay;};
int Chess :: getHorseDisplay () {return horseDisplay;};
int Chess :: getQueenDisplay () {return queenDisplay;};
int Chess :: getKingDisplay () {return kingDisplay;};

//set methods
void Chess :: setPieceType(type t) {pieceType = t;}
void Chess :: setRow (int r) {
    if (-1 < r && r < 8)
        row = r;
}
void Chess :: setColumn (int c) {
    if (-1 < c && c < 8)
        column = c;
}
void Chess :: setPawnDisplay (int p) {pawnDisplay = p;};
void Chess :: setBishopDisplay (int b) {bishopDisplay = b;};
void Chess :: setCastleDisplay (int c) {castleDisplay = c;};
void Chess :: setHorseDisplay (int h) {horseDisplay = h;};
void Chess :: setQueenDisplay (int q) {queenDisplay = q;};
void Chess :: setKingDisplay (int k) {kingDisplay = k;};

void Chess :: move (direction d)
{
    switch (getPieceType())
    {
        case pawn:
        {
            if (d == Right || d == Left)
                return;
            if (d == Up)
                setColumn (getColumn ()+1);
            if (d == Down)
                setColumn (getColumn ()-1);
            break;
        }
        case bishop:
        {
            if (d == Right)
            {
                setColumn (getColumn ()-1);
                setRow (getRow ()+1);
            }
            if (d == Left)
            {
                setColumn (getColumn ()+1);
                setRow (getRow ()-1);
            }
            if (d == Up)
            {
                setColumn (getColumn ()+1);
                setRow (getRow ()+1);
            }
            if (d == Down)
            {
                setColumn (getColumn ()-1);
                setRow (getRow ()-1);
            }
            break;
        }
        case castle:
        {
            if (d == Right)
                setRow (getRow ()+1);
            if (d == Left)
                setRow (getRow ()-1);
            if (d == Up)
                setColumn (getColumn ()+1);
            if (d == Down)
                setColumn (getColumn ()-1);
            break;
        }
        case horse:
        {
            if (isDiagonal)
            {
                if (d == Right)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()+2);
                }
                if (d == Left)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()-2);
                }
                if (d == Up)
                {
                    setColumn (getColumn ()+2);
                    setRow (getRow ()+1);
                }
                if (d == Down)
                {
                    setColumn (getColumn ()-2);
                    setRow (getRow ()-1);
                }
            }
            else
            {
                if (d == Right)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()+2);
                }
                if (d == Left)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()-2);
                }
                if (d == Up)
                {
                    setColumn (getColumn ()+2);
                    setRow (getRow ()-1);
                }
                if (d == Down)
                {
                    setColumn (getColumn ()-2);
                    setRow (getRow ()+1);
                }
            }
            break;
        }
        case queen:
        {
            if (isDiagonal)
            {
                if (d == Right)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()+1);
                }
                if (d == Left)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()-1);
                }
                if (d == Up)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()+1);
                }
                if (d == Down)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()-1);
                }
            }
            else
            {
                if (d == Right)
                    setRow (getRow ()+1);
                if (d == Left)
                    setRow (getRow ()-1);
                if (d == Up)
                    setColumn (getColumn ()+1);
                if (d == Down)
                    setColumn (getColumn ()-1);
            }
            break;
        }
        case king:
        {
            if (isDiagonal)
            {
                if (d == Right)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()+1);
                }
                if (d == Left)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()-1);
                }
                if (d == Up)
                {
                    setColumn (getColumn ()+1);
                    setRow (getRow ()+1);
                }
                if (d == Down)
                {
                    setColumn (getColumn ()-1);
                    setRow (getRow ()-1);
                }
            }
            else
            {
                if (d == Right)
                    setRow (getRow ()+1);
                if (d == Left)
                    setRow (getRow ()-1);
                if (d == Up)
                    setColumn (getColumn ()+1);
                if (d == Down)
                    setColumn (getColumn ()-1);
            }
            break;
        }
    }
}

void Chess :: initDisplay()
{
    float centerX = -0.875f;
    float centerY = -0.825;
    int list_base = 1;
    
    setPawnDisplay (list_base);
    glNewList (getPawnDisplay (), GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(centerX, centerY);
        for (int i = 0; i <= 360; i++)
        {
            glVertex2f(centerX + sin(i) * 0.04f, centerY + cos(i) * 0.04f);
        }
        glEnd();
            
        glBegin (GL_TRIANGLES);
        glVertex2f (centerX - 0.065f,centerY - 0.15f);
        glVertex2f (centerX + 0.065f,centerY - 0.15f);
        glVertex2f (centerX, centerY);
        glEnd();
    glEndList ();
    
    setBishopDisplay (list_base + 1);
    glNewList (getBishopDisplay (), GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(centerX, centerY);
        for (int i = 20; i <= 340; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / 360.0f;
            glVertex2f(centerX + sin(theta) * 0.025f, centerY + cos(theta) * 0.07f);
        }
        glEnd();
    
        glBegin (GL_TRIANGLES);
        glVertex2f (centerX - 0.035f,centerY - 0.15f);
        glVertex2f (centerX + 0.035f,centerY - 0.15f);
        glVertex2f (centerX, centerY);
        glEnd();
    glEndList ();
    
    setCastleDisplay (list_base + 2);
    glNewList (getCastleDisplay (), GL_COMPILE);
        glBegin(GL_QUADS);
    
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(centerX - 0.055f, centerY - 0.045f);
        glVertex2f(centerX + 0.055f, centerY - 0.045f);
        glVertex2f(centerX + 0.055f, centerY + 0.02);
        glVertex2f(centerX - 0.055f, centerY + 0.02f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX - 0.05f,centerY - 0.16f);
        glVertex2f (centerX + 0.05f,centerY - 0.16f);
        glVertex2f (centerX + 0.03f,centerY - 0.045f);
        glVertex2f (centerX - 0.03f,centerY - 0.045f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX - 0.055f,centerY + 0.02f);
        glVertex2f (centerX - 0.033f,centerY + 0.02f);
        glVertex2f (centerX - 0.033f,centerY + 0.055f);
        glVertex2f (centerX - 0.055f,centerY + 0.055f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX - 0.027f,centerY + 0.02f);
        glVertex2f (centerX - 0.003f, centerY + 0.02f);
        glVertex2f (centerX - 0.003f, centerY + 0.055f);
        glVertex2f (centerX - 0.027f,centerY + 0.055f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX + 0.003f, centerY + 0.02f);
        glVertex2f (centerX + 0.027f,centerY + 0.02f);
        glVertex2f (centerX + 0.027f,centerY + 0.055f);
        glVertex2f (centerX + 0.003f, centerY + 0.055f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX + 0.033f,centerY + 0.02f);
        glVertex2f (centerX + 0.055f,centerY + 0.02f);
        glVertex2f (centerX + 0.055f,centerY + 0.055f);
        glVertex2f (centerX + 0.033f,centerY + 0.055f);
        glEnd();
    glEndList ();
    
    setHorseDisplay (list_base + 3);
    glNewList (getHorseDisplay (), GL_COMPILE);
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(centerX - 0.105f, centerY - 0.05f);
        glVertex2f(centerX - 0.036f, centerY - 0.05f);
        glVertex2f(centerX + 0.016f, centerY + 0.045f);
        glVertex2f(centerX - 0.022f, centerY + 0.045f);
        glEnd();
    
        glBegin (GL_QUADS);
        glVertex2f (centerX - 0.045f, centerY - 0.16f);
        glVertex2f (centerX + 0.045f, centerY - 0.16f);
        glVertex2f (centerX + 0.025f, centerY + 0.045f);
        glVertex2f (centerX - 0.025f, centerY + 0.045f);
        glEnd();
    
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(centerX - 0.08f, centerY - 0.04f);
        for (int i = 0; i <= 140; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / 360.0f;
            glVertex2f((centerX - 0.072f) + sin(theta) * 0.03f, (centerY - 0.04f) + cos(theta) * 0.03f);
        }
        for (int i = 240; i <= 360; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / 360.0f;
            glVertex2f((centerX - 0.072f) + sin(theta) * 0.03f, (centerY - 0.04f) + cos(theta) * 0.03f);
        }
        glEnd();
    glEndList ();
    
    setQueenDisplay (list_base + 4);
    glNewList (getQueenDisplay (), GL_COMPILE);
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.055f,centerY - 0.16f);
        glVertex2f (centerX + 0.055f,centerY - 0.16f);
        glVertex2f (centerX + 0.025f,centerY - 0.07f);
        glVertex2f (centerX - 0.025f,centerY - 0.07f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX + 0.045f,centerY);
        glVertex2f (centerX - 0.045f,centerY);
        glVertex2f (centerX - 0.025f,centerY - 0.07f);
        glVertex2f (centerX + 0.025f,centerY - 0.07f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.045f,centerY);
        glVertex2f (centerX - 0.015f,centerY);
        glVertex2f (centerX - 0.015f,centerY + 0.025f);
        glVertex2f (centerX - 0.045f,centerY + 0.025f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX + 0.045f,centerY);
        glVertex2f (centerX + 0.015f,centerY);
        glVertex2f (centerX + 0.015f,centerY + 0.025f);
        glVertex2f (centerX + 0.045f,centerY + 0.025f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.01f,centerY);
        glVertex2f (centerX + 0.01f,centerY);
        glVertex2f (centerX + 0.01f,centerY + 0.055f);
        glVertex2f (centerX - 0.01f,centerY + 0.055f);
        glEnd();
    glEndList ();
    
    setKingDisplay (list_base + 5);
    glNewList (getKingDisplay (), GL_COMPILE);
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.055f,centerY - 0.16f);
        glVertex2f (centerX + 0.055f,centerY - 0.16f);
        glVertex2f (centerX + 0.025f,centerY - 0.07f);
        glVertex2f (centerX - 0.025f,centerY - 0.07f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX + 0.04f,centerY + 0.02f);
        glVertex2f (centerX - 0.04f,centerY + 0.02f);
        glVertex2f (centerX - 0.025f,centerY - 0.07f);
        glVertex2f (centerX + 0.025f,centerY - 0.07f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.008f,centerY);
        glVertex2f (centerX + 0.008f,centerY);
        glVertex2f (centerX + 0.008f,centerY + 0.058f);
        glVertex2f (centerX - 0.008f,centerY + 0.058f);
        glEnd();
    
        glBegin (GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f (centerX - 0.02f,centerY + 0.028f);
        glVertex2f (centerX + 0.02f,centerY + 0.028f);
        glVertex2f (centerX + 0.02f,centerY + 0.043f);
        glVertex2f (centerX - 0.02f,centerY + 0.043f);
        glEnd();
    glEndList ();
}



