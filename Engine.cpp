//
//  Engine.cpp
//  SeniorProject
//
//  Created by Shay Bromer on 3/18/14.
//  Copyright (c) 2014 Shay Bromer. All rights reserved.
//

#include <iostream> 
#include <OpenGl/gl.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <cstdlib> 
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Chess.h"
#include "Zombies.h"
#include "Bullet.h"
 
using namespace std;

Chess player;//object that represents user/player
std::vector<Zombies> zombies;
Bullet b;
float level = 3000;
bool isOver = false;
bool stop = false;
 
//methods
void updateBoard ();
void display ();
void drawBoard ();
void shoot ();
void keyboard1 (int key, int x, int y);
void keyboard2 (unsigned char key, int x, int y);
void zombieMovement (int v);
void zombieAddition (int v);
void bulletMovement (int v);
void idle ();
void mouse (int button, int state, int x, int y);

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize (1700, 1700);
    glutCreateWindow (" ");
    glutFullScreen ();
    srand(time(NULL));
    switch (rand ()%6)
    {
        case 0: player.setPieceType (pawn); break;
        case 1: player.setPieceType (bishop); break;
        case 2: player.setPieceType (castle); break;
        case 3: player.setPieceType (horse); break;
        case 4: player.setPieceType (queen); break;
        case 5: player.setPieceType (king); break;
    }
    player.setRow (4);
    player.setColumn (0);
    player.initDisplay ();
    b.setX (-1);
    b.setY (-1);
    b.init ();
    glutKeyboardFunc (keyboard2); 
    glutSpecialFunc (keyboard1);
    glutMouseFunc (mouse);
    glutDisplayFunc(display);
    glutTimerFunc (700, zombieMovement, 0);
    glutTimerFunc (2000, zombieAddition, 0);
    glutIdleFunc (idle);
    glutMainLoop ();
    return 0;
}

void display ()
{
    if (isOver)
    {
        int secs = glutGet(GLUT_ELAPSED_TIME)/1000;
        glClearColor(0.752941f, 0.752941f, 0.752941f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f (0.0f, 0.0f, 0.0f);
        glBegin (GL_QUADS);
        glVertex2f (-0.5f, 0.2f);
        glVertex2f (0.5f, 0.2f);
        glVertex2f (0.5f, 0.7f);
        glVertex2f (-0.5f, 0.7f);
        glEnd ();
        glBegin (GL_QUADS);
        glVertex2f (-0.5f, -0.2f);
        glVertex2f (-0.04f, -0.2f);
        glVertex2f (-0.04f, -0.7f);
        glVertex2f (-0.5f, -0.7f);
        glEnd ();
        glBegin (GL_QUADS);
        glVertex2f (0.04f, -0.2f);
        glVertex2f (0.5f, -0.2f);
        glVertex2f (0.5f, -0.7f);
        glVertex2f (0.04f, -0.7f);
        glEnd ();
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glPushMatrix ();
        glTranslatef (-0.2f ,0.5f ,0.0f);
        glScalef(0.0005f,0.0005,0.0f);
        glColor3f(1.0f,1.0f,1.0f);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'G');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'M');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'V');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
        glPopMatrix ();
        glLoadIdentity ();
        glPushMatrix ();
        glTranslatef (-0.3f ,0.3f ,0.0f);
        glScalef(0.0005f,0.0005,0.0f);
        glColor3f(1.0f,1.0f,1.0f);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'Y');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'U');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'C');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'I');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
        char buffer[256];
        sprintf(buffer,"%d", secs);
        int i =0;
        while (buffer[i] != '\0'){
        glutStrokeCharacter(GLUT_STROKE_ROMAN, buffer[i]);
            i++;
        }
        glPopMatrix ();
        glLoadIdentity ();
        glPushMatrix ();
        glTranslatef (-0.45f ,-0.5f ,0.0f);
        glScalef(0.0005f,0.0005,0.0f);
        glColor3f(1.0f,1.0f,1.0f);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'P');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'L');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'Y');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'G');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'I');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'N');
        glPopMatrix ();
        glPushMatrix ();
        glTranslatef (0.2f ,-0.5f ,0.0f);
        glScalef(0.0005f,0.0005,0.0f);
        glColor3f(1.0f,1.0f,1.0f);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'X');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'I');
        glutStrokeCharacter(GLUT_STROKE_ROMAN, 'T');
        glPopMatrix ();

        if (!stop)
            glutSwapBuffers ();
        stop = true;
    }
    else
    {
    glClearColor(0.752941f, 0.752941f, 0.752941f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard ();
    glMatrixMode(GL_MODELVIEW);
        
    //display chess piece
    glLoadIdentity ();
    glPushMatrix ();
    glTranslatef (player.getRow () * 0.25f, player.getColumn() * 0.25f, 0.0f);
    switch (player.getPieceType ())
    {
        case pawn: {glCallList (player.getPawnDisplay ()); break;}
        case bishop: {glCallList (player.getBishopDisplay ()); break;}
        case castle: {glCallList (player.getCastleDisplay ()); break;}
        case horse: {glCallList (player.getHorseDisplay ()); break;}
        case queen: {glCallList (player.getQueenDisplay ()); break;}
        case king: {glCallList (player.getKingDisplay ()); break;}
    }
    glPopMatrix ();
        
    //display zombies
    for (int i=0;i<zombies.size();i++)
    {
        glLoadIdentity ();
        glPushMatrix ();
        glTranslatef (zombies.at(i).getRow () * 0.25f, zombies.at(i).getColumn() * 0.25f, 0.0f);
        glCallList (zombies.at(i).getDisplay ());
        glPopMatrix ();
    }
        
    //display bullet
    glLoadIdentity ();
    glPushMatrix ();
    if (b.isActive == true){
        glTranslatef (b.getX () * 0.025f, b.getY() * 0.025f, 0.0f);
        glCallList (b.getDisplay ());
    }
    glPopMatrix ();
    }
    if (!isOver)
        glutSwapBuffers ();
}

void mouse (int button, int state, int x, int y)
{
    exit (EXIT_SUCCESS);
}

void keyboard1 (int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        player.move (Up);
    }
    if (key == GLUT_KEY_DOWN)
    {
        player.move (Down);
    }
    if (key == GLUT_KEY_RIGHT)
    {
        player.move (Right);
    }
    if (key == GLUT_KEY_LEFT)
    {
        player.move (Left);
    }
}

void keyboard2 (unsigned char key, int x, int y)
{
    if (key == ' ')
    {
        b.setX (player.getRow () * 10);
        b.setY (player.getColumn () * 10);
        b.isActive = true;
        glutTimerFunc (30, bulletMovement, 0);
    }
    if (key == 'z')
        player.isDiagonal = !player.isDiagonal;
}

void zombieMovement (int v)
{
    for (int i=0;i<zombies.size();i++)
    {
        if (zombies.at(i).getType () == 1)
        {
            if (player.getColumn () < zombies.at(i).getColumn ())
                zombies.at(i).setColumn (zombies.at(i).getColumn () - 1);
            if (player.getColumn () > zombies.at(i).getColumn ())
                zombies.at(i).setColumn (zombies.at(i).getColumn () + 1);
            if (player.getRow () < zombies.at(i).getRow ())
                zombies.at(i).setRow (zombies.at(i).getRow () - 1);
            if (player.getRow () > zombies.at(i).getRow ())
                zombies.at(i).setRow (zombies.at(i).getRow () + 1);
        }
        else
        {
            switch (rand ()%4)
            {
                case 0: zombies[i].setRow (zombies[i].getRow () - 1); break;
                case 1: zombies[i].setRow (zombies[i].getRow () + 1); break;
                case 2: zombies[i].setColumn (zombies[i].getColumn () - 1); break;
                case 3: zombies[i].setColumn (zombies[i].getColumn () + 1); break;
                default: break;
            }
        }
    }
    glutTimerFunc (1000, zombieMovement, 0);
}

void zombieAddition (int v)
{
    Zombies z;
    if (level>0)
        level = level*0.9f;
    if (level > 1500)
        z = Zombies (0, rand()%6 , 7);
    if (level > 1000 && level <1500)
        z = Zombies (rand()%2, rand()%6 , 7);
    if (level < 1000)
        z = Zombies (1, rand()%6 , 7);
    z.init ();
    zombies.push_back (z);
    glutTimerFunc (level, zombieAddition, 0);
}

void bulletMovement (int v)
{
    b.setY (b.getY () + 1);
    for (int i=0;i<zombies.size();i++)
    {
        if (b.getX ()/10 == zombies.at(i).getRow () && b.getY ()/10 == zombies.at(i).getColumn ())
        {
            zombies.erase (zombies.begin () + i);
            b.isActive = false;
        }
    }
    if (b.isActive)
        glutTimerFunc (30, bulletMovement, 0);
}

void idle ()
{
    //check if player is on the same square as any of the zombies
    for (int i=0;i<zombies.size();i++)
    {
        if (player.getRow()==zombies.at(i).getRow()&&player.getColumn()==zombies.at(i).getColumn())
            isOver = true;
    }
    
    //check if bullet has hit any of the zombies
    for (int i=0;i<zombies.size();i++)
    {
        if (b.getX ()/10 == zombies.at(i).getRow () && b.getY ()/10 == zombies.at(i).getColumn ())
        {
            zombies.erase (zombies.begin () + i);
            b.isActive = false;
        }
    }
    glutPostRedisplay ();
}

void drawBoard ()
{
    float x = -1.5f;
    float y = -1.0f;
    float x2 = -1.25f;
    float y2 = -0.75f;
    glBegin (GL_QUADS);
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            x += 0.5f;
            x2 += 0.5f;
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(x, y);
            glVertex2f(x2, y);
            glVertex2f(x2, y2);
            glVertex2f(x, y2);
        }
        y += 0.5f;
        y2 += 0.5f;
        x = -1.5f;
        x2 = -1.25f;
    }
    x = -1.25f;
    y = -0.75f;
    x2 = -1.0f;
    y2 = -0.5f;
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            x += 0.5f;
            x2 += 0.5f;
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(x, y);
            glVertex2f(x2, y);
            glVertex2f(x2, y2);
            glVertex2f(x, y2);
        }
        y += 0.5f;
        y2 += 0.5f;
        x = -1.25f;
        x2 = -1.0f;
    }
   	glEnd();
}



