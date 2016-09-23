//
//  Chess.h
//  SeniorProject
//
//  Created by Shay Bromer on 3/17/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//This class is used represents the user/player and can be set to represent any of the chess pieces.

#ifndef __SeniorProject__Chess__
#define __SeniorProject__Chess__

#include <OpenGl/gl.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265f

enum type {pawn,castle,bishop,horse,king,queen};
enum direction {Right,Left,Up,Down};

class Chess
{
private:
    type pieceType;//type of chess piece being used
    int row;//current row of the player
    int column;//current column of the player
    float x;//curent x coordinate for player
    float y;//current y coordinate for player
    
    //integers used to call display lists
    int pawnDisplay;
    int bishopDisplay;
    int castleDisplay;
    int horseDisplay;
    int queenDisplay;
    int kingDisplay;
    
public:
    type getPieceType ();
    int getRow ();
    int getColumn ();
    void setRow (int r);
    void setColumn (int c);
    void setPieceType (type t);
    float getX ();
    void setX (float num);
    float getY ();
    void setY (float num);
    int getPawnDisplay ();
    void setPawnDisplay (int p);
    int getBishopDisplay ();
    void setBishopDisplay (int b);
    int getCastleDisplay ();
    void setCastleDisplay (int c);
    int getHorseDisplay ();
    void setHorseDisplay (int h);
    int getQueenDisplay ();
    void setQueenDisplay (int q);
    int getKingDisplay ();
    void setKingDisplay (int k);
    void move (direction d);//updates internal representations when the player moves
    void initDisplay ();//sets dislay lists for each chess piece
    bool isDiagonal;
};

#endif /* defined(__SeniorProject__Chess__) */
