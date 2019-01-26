#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

float inc,inc2,inc3,inc5=0 , inc4=-22 ;
GLfloat red=0.0 , green=0.749 , blue=1.0 ;
GLfloat ll =1000;
GLfloat r=1,g=1,b=0;


void circle(GLdouble rad)
{
    glBegin(GL_POLYGON);
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.15;
		float x = rad * cos(A);
		float y = rad * sin(A);
		glVertex2f(x,y);
	}
	glEnd();
}


void miniCloud()
{
    //Mini Cloud
    glPushMatrix();             //left
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();             //right
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    glPushMatrix();             //top left
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();

    glPushMatrix();             //top right
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    glPushMatrix();             //middle
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}

void singleCloud()
{
    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(35,10,0);
    miniCloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(28,16,0);
    miniCloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(20,10,0);
    miniCloud();
    glPopMatrix();
}

void cloud()
{
    glPushMatrix();                     // Three Cloud
    glTranslatef(-15.0,30.0,0.0);
    glScalef(0.7,0.7,0.0);
    singleCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    singleCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    singleCloud();
    glPopMatrix();
}

void day()
{
    glBegin(GL_POLYGON);              // Blue sky
    glColor3f(red,green,blue);
    glVertex3f(-50,20,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(50,50,0.0);
    glVertex3f(50,20,0.0);
    glEnd();

    glPushMatrix();                    //Sun
    glTranslatef(-20.0,40.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(r,g,b);
    circle(3);
    glPopMatrix();
}

void greenField()
{
    glBegin(GL_QUADS);          //Green Feild Right
    glColor3ub(40,177,20);
    glVertex3f(-20,20,0.0);
    glVertex3f(-20,0,0.0);
    glVertex3f(50,0,0.0);
    glVertex3f(50,20,0.0);
    glEnd();


    glBegin(GL_QUADS);             //Green Field left small
    glColor3ub(40,177,20);
    glVertex3f(-40,-5,0.0);
    glVertex3f(-40,-50,0.0);
    glVertex3f(-50,-50,0.0);
    glVertex3f(-50,-5,0.0);
    glEnd();

    glBegin(GL_QUADS);             //Green Field bottom
    glColor3ub(40,177,20);
    glVertex3f(50,-5,0.0);
    glVertex3f(50,-50,0.0);
    glVertex3f(-20,-50,0.0);
    glVertex3f(-20,-5,0.0);
    glEnd();
}

void railRoad()
{
    glBegin(GL_QUADS);          //rail raod
    glColor3ub(203,205,205);
    glVertex3f(-50,-5,0.0);
    glVertex3f(-50,0,0.0);
    glVertex3f(50,0,0.0);
    glVertex3f(50,-5,0.0);
    glEnd();

    glBegin(GL_QUADS);     //Rail gate supporter
    glColor3ub(53,0,0);
    glVertex3f(-15,-8,0.0);
    glVertex3f(-15,-15,0.0);
    glVertex3f(-20,-15,0.0);
    glVertex3f(-20,-8,0.0);
    glEnd();

}

void railGate()
{

    glBegin(GL_QUADS);      //Main rail gate
    glColor3ub(255,0,0);
    glVertex3f(0,-10,0.0);
    glVertex3f(0,-13,0.0);
    glVertex3f(-20,-13,0.0);
    glVertex3f(-20,-10,0.0);
    glEnd();

}

void Road()
{
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);        //road bottom
    glVertex3f(-20,-5,0.0);
    glVertex3f(-20,-50,0.0);
    glVertex3f(-40,-50,0.0);
    glVertex3f(-40,-5,0.0);
    glEnd();

    glBegin(GL_QUADS);          //road top
    glColor3ub(128,128,128);
    glVertex3f(-20,20,0.0);
    glVertex3f(-20,0,0.0);
    glVertex3f(-50,0,0.0);
    glVertex3f(-50,20,0.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);        //down road strip  bottom
    glVertex3f(-29,-35,0.0);
    glVertex3f(-29,-50,0.0);
    glVertex3f(-31,-50,0.0);
    glVertex3f(-31,-35,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);        //down road  strip  top
    glVertex3f(-29,-10,0.0);
    glVertex3f(-29,-25,0.0);
    glVertex3f(-31,-25,0.0);
    glVertex3f(-31,-10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);        //top road  strip  right
    glVertex3f(-30,10,0.0);
    glVertex3f(-30,7,0.0);
    glVertex3f(-40,7,0.0);
    glVertex3f(-40,10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);        //top road  strip  left
    glVertex3f(-45,10,0.0);
    glVertex3f(-45,7,0.0);
    glVertex3f(-50,7,0.0);
    glVertex3f(-50,10,0.0);
    glEnd();
}

 void Trees()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0,64,0);        //  Tree top left
    glVertex3f(-14,24,0.0);
    glVertex3f(-16,30,0.0);
    glVertex3f(-18,24,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,64,0);
    glVertex3f(-13,21,0.0);
    glVertex3f(-16,26,0.0);
    glVertex3f(-19,21,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,64,0);
    glVertex3f(-13,18,0.0);
    glVertex3f(-16,23,0.0);
    glVertex3f(-19,18,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(83,41,0);
    glVertex3f(-16.5,10,0.0);
    glVertex3f(-16.5,20,0.0);
    glVertex3f(-15.5,20,0.0);
    glVertex3f(-15.5,10,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,89,0);          //right tree 1
    glTranslatef(46,-23,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,89,0);
    glTranslatef(48,-16,0);
    circle(6.5);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(48.5,-27,0.0);
    glVertex3f(48.5,-45,0.0);
    glVertex3f(50.5,-45,0.0);
    glVertex3f(50.5,-27,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,113,0);          //right tree 2
    glTranslatef(30,-23,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,113,0);
    glTranslatef(32,-16,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();                    //right tree 3
    glColor3ub(0,140,0);
    glTranslatef(37,-20,0);
    circle(4.5);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(32.5,-26,0.0);
    glVertex3f(32.5,-43,0.0);
    glVertex3f(34.5,-43,0.0);
    glVertex3f(34.5,-26,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,140,0);
    glTranslatef(37,-15,0);
    circle(4);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(36.5,-22,0.0);
    glVertex3f(36.5,-38,0.0);
    glVertex3f(38.5,-38,0.0);
    glVertex3f(38.5,-22,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,140,0);
    glTranslatef(37,-10,0);
    circle(3);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(44.5,-27,0.0);
    glVertex3f(44.5,-38,0.0);
    glVertex3f(46.5,-38,0.0);
    glVertex3f(46.5,-27,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(20.5,-30,0.0);
    glVertex3f(20.5,-50,0.0);
    glVertex3f(22.5,-50,0.0);
    glVertex3f(22.5,-30,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,128,0);
    glTranslatef(21,-30,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,128,0);
    glTranslatef(22,-24,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(26.5,-36,0.0);
    glVertex3f(26.5,-50,0.0);
    glVertex3f(28.5,-50,0.0);
    glVertex3f(28.5,-36,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(27,-32,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(27,-38,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(40,-39,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(40,-45,0);
    circle(6.5);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(-12.5,-36,0.0);
    glVertex3f(-12.5,-50,0.0);
    glVertex3f(-10.5,-50,0.0);
    glVertex3f(-10.5,-36,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(-12,-38,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(-12,-32,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,121,0);
    glTranslatef(-12,-27,0);
    circle(3.5);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(128,64,0);
    glVertex3f(-6.5,-36,0.0);
    glVertex3f(-6.5,-50,0.0);
    glVertex3f(-4.5,-50,0.0);
    glVertex3f(-4.5,-36,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(0,89,0);
    glTranslatef(-6,-34,0);
    circle(5.5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,89,0);
    glTranslatef(-6,-28,0);
    circle(4.5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,89,0);
    glTranslatef(-6,-23,0);
    circle(3);
    glPopMatrix();

}

void Buildings()
{
    glBegin(GL_QUADS);              //left building1
    glColor3ub(255,255,255);
    glVertex3f(0,40,0.0);
    glVertex3f(0,5,0.0);
    glVertex3f(-10,5,0.0);
    glVertex3f(-10,40,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2
    glColor3ub(63,63,63);
    glVertex3f(0,30,0.0);
    glVertex3f(0,5,0.0);
    glVertex3f(7,5,0.0);
    glVertex3f(7,30,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,29,0.0);
    glVertex3f(1,27,0.0);
    glVertex3f(3,27,0.0);
    glVertex3f(3,29,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,26,0.0);
    glVertex3f(1,24,0.0);
    glVertex3f(3,24,0.0);
    glVertex3f(3,26,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,23,0.0);
    glVertex3f(1,21,0.0);
    glVertex3f(3,21,0.0);
    glVertex3f(3,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,20,0.0);
    glVertex3f(1,18,0.0);
    glVertex3f(3,18,0.0);
    glVertex3f(3,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,17,0.0);
    glVertex3f(1,15,0.0);
    glVertex3f(3,15,0.0);
    glVertex3f(3,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,14,0.0);
    glVertex3f(1,12,0.0);
    glVertex3f(3,12,0.0);
    glVertex3f(3,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,11,0.0);
    glVertex3f(1,9,0.0);
    glVertex3f(3,9,0.0);
    glVertex3f(3,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(1,8,0.0);
    glVertex3f(1,6,0.0);
    glVertex3f(3,6,0.0);
    glVertex3f(3,8,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,29,0.0);
    glVertex3f(4,27,0.0);
    glVertex3f(6,27,0.0);
    glVertex3f(6,29,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,26,0.0);
    glVertex3f(4,24,0.0);
    glVertex3f(6,24,0.0);
    glVertex3f(6,26,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,23,0.0);
    glVertex3f(4,21,0.0);
    glVertex3f(6,21,0.0);
    glVertex3f(6,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,20,0.0);
    glVertex3f(4,18,0.0);
    glVertex3f(6,18,0.0);
    glVertex3f(6,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,17,0.0);
    glVertex3f(4,15,0.0);
    glVertex3f(6,15,0.0);
    glVertex3f(6,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,14,0.0);
    glVertex3f(4,12,0.0);
    glVertex3f(6,12,0.0);
    glVertex3f(6,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,11,0.0);
    glVertex3f(4,9,0.0);
    glVertex3f(6,9,0.0);
    glVertex3f(6,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 2 window
    glColor3ub(55,155,255);
    glVertex3f(4,8,0.0);
    glVertex3f(4,6,0.0);
    glVertex3f(6,6,0.0);
    glVertex3f(6,8,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 3
    glColor3ub(128,128,0);
    glVertex3f(0,35,0.0);
    glVertex3f(0,30,0.0);
    glVertex3f(4,30,0.0);
    glVertex3f(4,35,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4
    glColor3ub(255,255,128);
    glVertex3f(-10,32,0.0);
    glVertex3f(-10,5,0.0);
    glVertex3f(-13,5,0.0);
    glVertex3f(-13,32,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,30,0.0);
    glVertex3f(-11,28,0.0);
    glVertex3f(-12,28,0.0);
    glVertex3f(-12,30,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,27,0.0);
    glVertex3f(-11,25,0.0);
    glVertex3f(-12,25,0.0);
    glVertex3f(-12,27,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,24,0.0);
    glVertex3f(-11,22,0.0);
    glVertex3f(-12,22,0.0);
    glVertex3f(-12,24,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,21,0.0);
    glVertex3f(-11,19,0.0);
    glVertex3f(-12,19,0.0);
    glVertex3f(-12,21,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,18,0.0);
    glVertex3f(-11,16,0.0);
    glVertex3f(-12,16,0.0);
    glVertex3f(-12,18,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,15,0.0);
    glVertex3f(-11,13,0.0);
    glVertex3f(-12,13,0.0);
    glVertex3f(-12,15,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,12,0.0);
    glVertex3f(-11,10,0.0);
    glVertex3f(-12,10,0.0);
    glVertex3f(-12,12,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 4 window
    glColor3ub(0,0,128);
    glVertex3f(-11,9,0.0);
    glVertex3f(-11,7,0.0);
    glVertex3f(-12,7,0.0);
    glVertex3f(-12,9,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5
    glColor3ub(255,255,255);
    glVertex3f(7,25,0.0);
    glVertex3f(7,5,0.0);
    glVertex3f(10,5,0.0);
    glVertex3f(10,25,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,23,0.0);
    glVertex3f(8,21,0.0);
    glVertex3f(10,21,0.0);
    glVertex3f(10,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,20,0.0);
    glVertex3f(8,18,0.0);
    glVertex3f(10,18,0.0);
    glVertex3f(10,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,17,0.0);
    glVertex3f(8,15,0.0);
    glVertex3f(10,15,0.0);
    glVertex3f(10,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,14,0.0);
    glVertex3f(8,12,0.0);
    glVertex3f(10,12,0.0);
    glVertex3f(10,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,11,0.0);
    glVertex3f(8,9,0.0);
    glVertex3f(10,9,0.0);
    glVertex3f(10,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //left building 5 window
    glColor3ub(0,0,128);
    glVertex3f(8,8,0.0);
    glVertex3f(8,6,0.0);
    glVertex3f(10,6,0.0);
    glVertex3f(10,8,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1
    glColor3ub(128,128,64);
    glVertex3f(10,40,0.0);
    glVertex3f(10,5,0.0);
    glVertex3f(20,5,0.0);
    glVertex3f(20,40,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,38,0.0);
    glVertex3f(11,36,0.0);
    glVertex3f(13,36,0.0);
    glVertex3f(13,38,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,35,0.0);
    glVertex3f(11,33,0.0);
    glVertex3f(13,33,0.0);
    glVertex3f(13,35,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,32,0.0);
    glVertex3f(11,30,0.0);
    glVertex3f(13,30,0.0);
    glVertex3f(13,32,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,29,0.0);
    glVertex3f(11,27,0.0);
    glVertex3f(13,27,0.0);
    glVertex3f(13,29,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,26,0.0);
    glVertex3f(11,24,0.0);
    glVertex3f(13,24,0.0);
    glVertex3f(13,26,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,23,0.0);
    glVertex3f(11,21,0.0);
    glVertex3f(13,21,0.0);
    glVertex3f(13,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,20,0.0);
    glVertex3f(11,18,0.0);
    glVertex3f(13,18,0.0);
    glVertex3f(13,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,17,0.0);
    glVertex3f(11,15,0.0);
    glVertex3f(13,15,0.0);
    glVertex3f(13,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,14,0.0);
    glVertex3f(11,12,0.0);
    glVertex3f(13,12,0.0);
    glVertex3f(13,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,11,0.0);
    glVertex3f(11,9,0.0);
    glVertex3f(13,9,0.0);
    glVertex3f(13,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(11,8,0.0);
    glVertex3f(11,6,0.0);
    glVertex3f(13,6,0.0);
    glVertex3f(13,8,0.0);
    glEnd();

     glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,38,0.0);
    glVertex3f(14,36,0.0);
    glVertex3f(16,36,0.0);
    glVertex3f(16,38,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,35,0.0);
    glVertex3f(14,33,0.0);
    glVertex3f(16,33,0.0);
    glVertex3f(16,35,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,32,0.0);
    glVertex3f(14,30,0.0);
    glVertex3f(16,30,0.0);
    glVertex3f(16,32,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,29,0.0);
    glVertex3f(14,27,0.0);
    glVertex3f(16,27,0.0);
    glVertex3f(16,29,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,26,0.0);
    glVertex3f(14,24,0.0);
    glVertex3f(16,24,0.0);
    glVertex3f(16,26,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,23,0.0);
    glVertex3f(14,21,0.0);
    glVertex3f(16,21,0.0);
    glVertex3f(16,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,20,0.0);
    glVertex3f(14,18,0.0);
    glVertex3f(16,18,0.0);
    glVertex3f(16,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,17,0.0);
    glVertex3f(14,15,0.0);
    glVertex3f(16,15,0.0);
    glVertex3f(16,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,14,0.0);
    glVertex3f(14,12,0.0);
    glVertex3f(16,12,0.0);
    glVertex3f(16,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,11,0.0);
    glVertex3f(14,9,0.0);
    glVertex3f(16,9,0.0);
    glVertex3f(16,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(14,8,0.0);
    glVertex3f(14,6,0.0);
    glVertex3f(16,6,0.0);
    glVertex3f(16,8,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,8,0.0);
    glVertex3f(17,6,0.0);
    glVertex3f(19,6,0.0);
    glVertex3f(19,8,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,38,0.0);
    glVertex3f(17,36,0.0);
    glVertex3f(19,36,0.0);
    glVertex3f(19,38,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,35,0.0);
    glVertex3f(17,33,0.0);
    glVertex3f(19,33,0.0);
    glVertex3f(19,35,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,32,0.0);
    glVertex3f(17,30,0.0);
    glVertex3f(19,30,0.0);
    glVertex3f(19,32,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,29,0.0);
    glVertex3f(17,27,0.0);
    glVertex3f(19,27,0.0);
    glVertex3f(19,29,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,26,0.0);
    glVertex3f(17,24,0.0);
    glVertex3f(19,24,0.0);
    glVertex3f(19,26,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,23,0.0);
    glVertex3f(17,21,0.0);
    glVertex3f(19,21,0.0);
    glVertex3f(19,23,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,20,0.0);
    glVertex3f(17,18,0.0);
    glVertex3f(19,18,0.0);
    glVertex3f(19,20,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,17,0.0);
    glVertex3f(17,15,0.0);
    glVertex3f(19,15,0.0);
    glVertex3f(19,17,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,14,0.0);
    glVertex3f(17,12,0.0);
    glVertex3f(19,12,0.0);
    glVertex3f(19,14,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 1 window
    glColor3ub(255,255,170);
    glVertex3f(17,11,0.0);
    glVertex3f(17,9,0.0);
    glVertex3f(19,9,0.0);
    glVertex3f(19,11,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2
    glColor3ub(255,255,128);
    glVertex3f(20,35,0.0);
    glVertex3f(20,5,0.0);
    glVertex3f(27,5,0.0);
    glVertex3f(27,35,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,33,0.0);
    glVertex3f(21,31,0.0);
    glVertex3f(23,31,0.0);
    glVertex3f(23,33,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,30,0.0);
    glVertex3f(21,28,0.0);
    glVertex3f(23,28,0.0);
    glVertex3f(23,30,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,27,0.0);
    glVertex3f(21,25,0.0);
    glVertex3f(23,25,0.0);
    glVertex3f(23,27,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,24,0.0);
    glVertex3f(21,22,0.0);
    glVertex3f(23,22,0.0);
    glVertex3f(23,24,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,21,0.0);
    glVertex3f(21,19,0.0);
    glVertex3f(23,19,0.0);
    glVertex3f(23,21,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,18,0.0);
    glVertex3f(21,16,0.0);
    glVertex3f(23,16,0.0);
    glVertex3f(23,18,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,15,0.0);
    glVertex3f(21,13,0.0);
    glVertex3f(23,13,0.0);
    glVertex3f(23,15,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,12,0.0);
    glVertex3f(21,10,0.0);
    glVertex3f(23,10,0.0);
    glVertex3f(23,12,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(21,9,0.0);
    glVertex3f(21,7,0.0);
    glVertex3f(23,7,0.0);
    glVertex3f(23,9,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,33,0.0);
    glVertex3f(24,31,0.0);
    glVertex3f(26,31,0.0);
    glVertex3f(26,33,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,30,0.0);
    glVertex3f(24,28,0.0);
    glVertex3f(26,28,0.0);
    glVertex3f(26,30,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,27,0.0);
    glVertex3f(24,25,0.0);
    glVertex3f(26,25,0.0);
    glVertex3f(26,27,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,24,0.0);
    glVertex3f(24,22,0.0);
    glVertex3f(26,22,0.0);
    glVertex3f(26,24,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,21,0.0);
    glVertex3f(24,19,0.0);
    glVertex3f(26,19,0.0);
    glVertex3f(26,21,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,18,0.0);
    glVertex3f(24,16,0.0);
    glVertex3f(26,16,0.0);
    glVertex3f(26,18,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,15,0.0);
    glVertex3f(24,13,0.0);
    glVertex3f(26,13,0.0);
    glVertex3f(26,15,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,12,0.0);
    glVertex3f(24,10,0.0);
    glVertex3f(26,10,0.0);
    glVertex3f(26,12,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 2 window
    glColor3ub(55,155,255);
    glVertex3f(24,9,0.0);
    glVertex3f(24,7,0.0);
    glVertex3f(26,7,0.0);
    glVertex3f(26,9,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3
    glColor3ub(128,128,255);
    glVertex3f(27,30,0.0);
    glVertex3f(27,5,0.0);
    glVertex3f(30,5,0.0);
    glVertex3f(30,30,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,28,0.0);
    glVertex3f(28,26,0.0);
    glVertex3f(29,26,0.0);
    glVertex3f(29,28,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,25,0.0);
    glVertex3f(28,23,0.0);
    glVertex3f(29,23,0.0);
    glVertex3f(29,25,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,22,0.0);
    glVertex3f(28,20,0.0);
    glVertex3f(29,20,0.0);
    glVertex3f(29,22,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,19,0.0);
    glVertex3f(28,17,0.0);
    glVertex3f(29,17,0.0);
    glVertex3f(29,19,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,16,0.0);
    glVertex3f(28,14,0.0);
    glVertex3f(29,14,0.0);
    glVertex3f(29,16,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,13,0.0);
    glVertex3f(28,11,0.0);
    glVertex3f(29,11,0.0);
    glVertex3f(29,13,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,10,0.0);
    glVertex3f(28,8,0.0);
    glVertex3f(29,8,0.0);
    glVertex3f(29,10,0.0);
    glEnd();

    glBegin(GL_QUADS);              //middle building 3 window
    glColor3ub(0,0,160);
    glVertex3f(28,7,0.0);
    glVertex3f(28,5,0.0);
    glVertex3f(29,5,0.0);
    glVertex3f(29,7,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1
    glColor3ub(128,128,64);
    glVertex3f(30,25,0.0);
    glVertex3f(30,5,0.0);
    glVertex3f(45,5,0.0);
    glVertex3f(45,25,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,23,0.0);
    glVertex3f(31,21,0.0);
    glVertex3f(44,21,0.0);
    glVertex3f(44,23,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,20,0.0);
    glVertex3f(31,18,0.0);
    glVertex3f(44,18,0.0);
    glVertex3f(44,20,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,17,0.0);
    glVertex3f(31,15,0.0);
    glVertex3f(44,15,0.0);
    glVertex3f(44,17,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,14,0.0);
    glVertex3f(31,12,0.0);
    glVertex3f(44,12,0.0);
    glVertex3f(44,14,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,11,0.0);
    glVertex3f(31,9,0.0);
    glVertex3f(44,9,0.0);
    glVertex3f(44,11,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 1 window
    glColor3ub(0,255,255);
    glVertex3f(31,8,0.0);
    glVertex3f(31,6,0.0);
    glVertex3f(44,6,0.0);
    glVertex3f(44,8,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2
    glColor3ub(112,0,223);
    glVertex3f(33,35,0.0);
    glVertex3f(33,25,0.0);
    glVertex3f(41,25,0.0);
    glVertex3f(41,35,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(34,33,0.0);
    glVertex3f(34,31,0.0);
    glVertex3f(36,31,0.0);
    glVertex3f(36,33,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(34,30,0.0);
    glVertex3f(34,28,0.0);
    glVertex3f(36,28,0.0);
    glVertex3f(36,30,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(34,27,0.0);
    glVertex3f(34,25,0.0);
    glVertex3f(36,25,0.0);
    glVertex3f(36,27,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(37,33,0.0);
    glVertex3f(37,31,0.0);
    glVertex3f(39,31,0.0);
    glVertex3f(39,33,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(37,30,0.0);
    glVertex3f(37,28,0.0);
    glVertex3f(39,28,0.0);
    glVertex3f(39,30,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 2 window
    glColor3ub(0,0,160);
    glVertex3f(37,27,0.0);
    glVertex3f(37,25,0.0);
    glVertex3f(39,25,0.0);
    glVertex3f(39,27,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3
    glColor3ub(255,255,255);
    glVertex3f(45,37,0.0);
    glVertex3f(45,5,0.0);
    glVertex3f(50,5,0.0);
    glVertex3f(50,37,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,35,0.0);
    glVertex3f(46,33,0.0);
    glVertex3f(49,33,0.0);
    glVertex3f(49,35,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,32,0.0);
    glVertex3f(46,30,0.0);
    glVertex3f(49,30,0.0);
    glVertex3f(49,32,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,29,0.0);
    glVertex3f(46,27,0.0);
    glVertex3f(49,27,0.0);
    glVertex3f(49,29,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,26,0.0);
    glVertex3f(46,24,0.0);
    glVertex3f(49,24,0.0);
    glVertex3f(49,26,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,23,0.0);
    glVertex3f(46,21,0.0);
    glVertex3f(49,21,0.0);
    glVertex3f(49,23,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,20,0.0);
    glVertex3f(46,18,0.0);
    glVertex3f(49,18,0.0);
    glVertex3f(49,20,0.0);
    glEnd();
             glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,17,0.0);
    glVertex3f(46,15,0.0);
    glVertex3f(49,15,0.0);
    glVertex3f(49,17,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,14,0.0);
    glVertex3f(46,12,0.0);
    glVertex3f(49,12,0.0);
    glVertex3f(49,14,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,11,0.0);
    glVertex3f(46,9,0.0);
    glVertex3f(49,9,0.0);
    glVertex3f(49,11,0.0);
    glEnd();

    glBegin(GL_QUADS);          //right building 3 window
    glColor3ub(0,0,160);
    glVertex3f(46,8,0.0);
    glVertex3f(46,6,0.0);
    glVertex3f(49,6,0.0);
    glVertex3f(49,8,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,38,0.0);
    glVertex3f(-1,36,0.0);
    glVertex3f(-3,36,0.0);
    glVertex3f(-3,38,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,38,0.0);
    glVertex3f(-4,36,0.0);
    glVertex3f(-6,36,0.0);
    glVertex3f(-6,38,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,38,0.0);
    glVertex3f(-7,36,0.0);
    glVertex3f(-9,36,0.0);
    glVertex3f(-9,38,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,35,0.0);
    glVertex3f(-1,33,0.0);
    glVertex3f(-3,33,0.0);
    glVertex3f(-3,35,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,35,0.0);
    glVertex3f(-4,33,0.0);
    glVertex3f(-6,33,0.0);
    glVertex3f(-6,35,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,35,0.0);
    glVertex3f(-7,33,0.0);
    glVertex3f(-9,33,0.0);
    glVertex3f(-9,35,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,32,0.0);
    glVertex3f(-1,30,0.0);
    glVertex3f(-3,30,0.0);
    glVertex3f(-3,32,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,32,0.0);
    glVertex3f(-4,30,0.0);
    glVertex3f(-6,30,0.0);
    glVertex3f(-6,32,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,29,0.0);
    glVertex3f(-4,27,0.0);
    glVertex3f(-6,27,0.0);
    glVertex3f(-6,29,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,26,0.0);
    glVertex3f(-4,24,0.0);
    glVertex3f(-6,24,0.0);
    glVertex3f(-6,26,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,23,0.0);
    glVertex3f(-4,21,0.0);
    glVertex3f(-6,21,0.0);
    glVertex3f(-6,23,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,20,0.0);
    glVertex3f(-4,18,0.0);
    glVertex3f(-6,18,0.0);
    glVertex3f(-6,20,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,17,0.0);
    glVertex3f(-4,15,0.0);
    glVertex3f(-6,15,0.0);
    glVertex3f(-6,17,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,14,0.0);
    glVertex3f(-4,12,0.0);
    glVertex3f(-6,12,0.0);
    glVertex3f(-6,14,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,11,0.0);
    glVertex3f(-4,9,0.0);
    glVertex3f(-6,9,0.0);
    glVertex3f(-6,11,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-4,8,0.0);
    glVertex3f(-4,6,0.0);
    glVertex3f(-6,6,0.0);
    glVertex3f(-6,8,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,32,0.0);
    glVertex3f(-7,30,0.0);
    glVertex3f(-9,30,0.0);
    glVertex3f(-9,32,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,29,0.0);
    glVertex3f(-7,27,0.0);
    glVertex3f(-9,27,0.0);
    glVertex3f(-9,29,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,26,0.0);
    glVertex3f(-7,24,0.0);
    glVertex3f(-9,24,0.0);
    glVertex3f(-9,26,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,23,0.0);
    glVertex3f(-7,21,0.0);
    glVertex3f(-9,21,0.0);
    glVertex3f(-9,23,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,20,0.0);
    glVertex3f(-7,18,0.0);
    glVertex3f(-9,18,0.0);
    glVertex3f(-9,20,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,17,0.0);
    glVertex3f(-7,15,0.0);
    glVertex3f(-9,15,0.0);
    glVertex3f(-9,17,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,14,0.0);
    glVertex3f(-7,12,0.0);
    glVertex3f(-9,12,0.0);
    glVertex3f(-9,14,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,11,0.0);
    glVertex3f(-7,9,0.0);
    glVertex3f(-9,9,0.0);
    glVertex3f(-9,11,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-7,8,0.0);
    glVertex3f(-7,6,0.0);
    glVertex3f(-9,6,0.0);
    glVertex3f(-9,8,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,29,0.0);
    glVertex3f(-1,27,0.0);
    glVertex3f(-3,27,0.0);
    glVertex3f(-3,29,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,26,0.0);
    glVertex3f(-1,24,0.0);
    glVertex3f(-3,24,0.0);
    glVertex3f(-3,26,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,23,0.0);
    glVertex3f(-1,21,0.0);
    glVertex3f(-3,21,0.0);
    glVertex3f(-3,23,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,20,0.0);
    glVertex3f(-1,18,0.0);
    glVertex3f(-3,18,0.0);
    glVertex3f(-3,20,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,17,0.0);
    glVertex3f(-1,15,0.0);
    glVertex3f(-3,15,0.0);
    glVertex3f(-3,17,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,14,0.0);
    glVertex3f(-1,12,0.0);
    glVertex3f(-3,12,0.0);
    glVertex3f(-3,14,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,11,0.0);
    glVertex3f(-1,9,0.0);
    glVertex3f(-3,9,0.0);
    glVertex3f(-3,11,0.0);
    glEnd();

    glBegin(GL_QUADS);           //left building 1 window
    glColor3ub(0,64,128);
    glVertex3f(-1,8,0.0);
    glVertex3f(-1,6,0.0);
    glVertex3f(-3,6,0.0);
    glVertex3f(-3,8,0.0);
    glEnd();
}

void train()
{
    glBegin(GL_QUADS);          //1st train
    glColor3ub(0,0,64);
    glVertex3f(6,-2,0.0);
    glVertex3f(6,10,0.0);
    glVertex3f(10,10,0.0);
    glVertex3f(10,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex3f(1,-2,0.0);
    glVertex3f(1,5,0.0);
    glVertex3f(6,5,0.0);
    glVertex3f(6,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(31,31,31);
    glVertex3f(0,1,0.0);
    glVertex3f(0,4,0.0);
    glVertex3f(1,4,0.0);
    glVertex3f(1,1,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(31,31,31);
    glVertex3f(-1,-2,0.0);
    glVertex3f(1,0,0.0);
    glVertex3f(1,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(31,31,31);
    glVertex3f(1,8,0.0);
    glVertex3f(1,10,0.0);
    glVertex3f(5,10,0.0);
    glVertex3f(5,8,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(107,107,107);
    glVertex3f(2,5,0.0);
    glVertex3f(2,8,0.0);
    glVertex3f(4,8,0.0);
    glVertex3f(4,5,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(6,10,0.0);
    glVertex3f(6,12,0.0);
    glVertex3f(10,12,0.0);
    glVertex3f(10,10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(6,-2,0.0);
    glVertex3f(6,0,0.0);
    glVertex3f(10,0,0.0);
    glVertex3f(10,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(7,4,0.0);
    glVertex3f(7,8,0.0);
    glVertex3f(9,8,0.0);
    glVertex3f(9,4,0.0);
    glEnd();

    glBegin(GL_QUADS);          //2nd train
    glColor3ub(0,0,64);
    glVertex3f(12,-2,0.0);
    glVertex3f(12,10,0.0);
    glVertex3f(22,10,0.0);
    glVertex3f(22,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(12,10,0.0);
    glVertex3f(12,12,0.0);
    glVertex3f(22,12,0.0);
    glVertex3f(22,10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(12,-2,0.0);
    glVertex3f(12,0,0.0);
    glVertex3f(22,0,0.0);
    glVertex3f(22,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(13,4,0.0);
    glVertex3f(13,7,0.0);
    glVertex3f(16,7,0.0);
    glVertex3f(16,4,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(18,4,0.0);
    glVertex3f(18,7,0.0);
    glVertex3f(21,7,0.0);
    glVertex3f(21,4,0.0);
    glEnd();

    glBegin(GL_QUADS);          //3rd train
    glColor3ub(0,0,64);
    glVertex3f(24,-2,0.0);
    glVertex3f(24,10,0.0);
    glVertex3f(34,10,0.0);
    glVertex3f(34,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(24,10,0.0);
    glVertex3f(24,12,0.0);
    glVertex3f(34,12,0.0);
    glVertex3f(34,10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(24,-2,0.0);
    glVertex3f(24,0,0.0);
    glVertex3f(34,0,0.0);
    glVertex3f(34,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(25,4,0.0);
    glVertex3f(25,7,0.0);
    glVertex3f(28,7,0.0);
    glVertex3f(28,4,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(30,4,0.0);
    glVertex3f(30,7,0.0);
    glVertex3f(33,7,0.0);
    glVertex3f(33,4,0.0);
    glEnd();


        glBegin(GL_QUADS);          //4th train
    glColor3ub(0,0,64);
    glVertex3f(36,-2,0.0);
    glVertex3f(36,10,0.0);
    glVertex3f(46,10,0.0);
    glVertex3f(46,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(36,10,0.0);
    glVertex3f(36,12,0.0);
    glVertex3f(46,12,0.0);
    glVertex3f(46,10,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60,0,0);
    glVertex3f(36,-2,0.0);
    glVertex3f(36,0,0.0);
    glVertex3f(46,0,0.0);
    glVertex3f(46,-2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(37,4,0.0);
    glVertex3f(37,7,0.0);
    glVertex3f(40,7,0.0);
    glVertex3f(40,4,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(42,4,0.0);
    glVertex3f(42,7,0.0);
    glVertex3f(45,7,0.0);
    glVertex3f(45,4,0.0);
    glEnd();

    glPushMatrix();             //1st train 1st wheel
    glColor3ub(98,98,255);
    glTranslatef(3,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //1st train 3rd wheel
    glTranslatef(8,-2.5,0);
    circle(2);
    glPopMatrix();

    glPushMatrix();             //2nd train 1st wheel
    glTranslatef(14,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //2nd train 2nd wheel
    glTranslatef(20,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //3rd train 1st wheel
    glTranslatef(26,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //3rd train 2nd wheel
    glTranslatef(32,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //4th train 1st wheel
    glTranslatef(38,-3,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();             //4th train 2nd wheel
    glTranslatef(44,-3,0);
    circle(1.5);
    glPopMatrix();

    glBegin(GL_QUADS);          //1st and 2nd train connector
    glColor3ub(128,64,0);
    glVertex3f(10,0,0.0);
    glVertex3f(10,2,0.0);
    glVertex3f(12,2,0.0);
    glVertex3f(12,0,0.0);
    glEnd();

    glBegin(GL_QUADS);          //2nd and 3rd train connector
    glColor3ub(128,64,0);
    glVertex3f(22,0,0.0);
    glVertex3f(22,2,0.0);
    glVertex3f(24,2,0.0);
    glVertex3f(24,0,0.0);
    glEnd();

    glBegin(GL_QUADS);          //3rd and 4th train connector
    glColor3ub(128,64,0);
    glVertex3f(34,0,0.0);
    glVertex3f(34,2,0.0);
    glVertex3f(36,2,0.0);
    glVertex3f(36,0,0.0);
    glEnd();
}

void light()
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-4,9,0.0);
    glVertex3f(0,4,0.0);
    glVertex3f(0,1,0.0);
    glVertex3f(-4,-4,0.0);
    glEnd();
}

void menWithFlag()
{
    glColor3ub(255,255,255);        //Head
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<300;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/300 ;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x+5,y-21,0.0 );
	}
	glEnd();
	glLineWidth(4);


    glPushMatrix();             //Left eye
    glTranslatef(3.5,-20.5,0);
    circle(.5);
    glPopMatrix();

    glPushMatrix();             //Right  eye
    glTranslatef(7,-20.5,0);
    circle(.5);
    glPopMatrix();



    glBegin(GL_LINE_STRIP);
    for(int ii = 0; ii < 100; ii++)                                      //SMILE
    {
       float theta = 3.0f * 3.1416 / 4.0f * float(ii) / float(-90);

        float x = 0.8 * cosf(theta);//calculate the x component
        float y = 0.8 * sinf(theta);//calculate the y component

        glVertex2f(x + 5, y -21.5);//output vertex
    }
    glEnd();


    glBegin(GL_LINES);          //Gola
    glColor3ub(255,255,255);
    glVertex3f(5,-24,0.0);
    glVertex3f(5,-26,0.0);
    glEnd();


    glBegin(GL_LINE_LOOP);          // Shirt
    glColor3ub(255,255,255);
    glVertex3f(2,-26,0.0);
    glVertex3f(2,-30,0.0);
    glVertex3f(3,-30,0.0);
    glVertex3f(3,-36,0.0);
    glVertex3f(7,-36,0.0);
    glVertex3f(7,-30,0.0);
    glVertex3f(8,-30,0.0);
    glVertex3f(8,-26,0.0);
    glEnd();

    glBegin(GL_LINES);          //left hand
    glColor3ub(255,255,255);
    glVertex3f(2,-28,0.0);
    glVertex3f(0,-28,0.0);
    glEnd();

    glPushMatrix();             //hand circle left
    glTranslatef(0,-28,0);
    circle(1);
    glPopMatrix();


    glPushMatrix();             //hand circle right
    glTranslatef(10,-28,0);
    circle(1);
    glPopMatrix();

    glBegin(GL_LINES);          //right hand
    glColor3ub(255,255,255);
    glVertex3f(8,-28,0.0);
    glVertex3f(10,-28,0.0);
    glEnd();


    glBegin(GL_LINE_LOOP);          // pant
    glColor3ub(255,255,255);
    glVertex3f(3,-36,0.0);
    glVertex3f(3,-42,0.0);
    glVertex3f(4,-42,0.0);
    glVertex3f(5,-41,0.0);
    glVertex3f(6,-42,0.0);
    glVertex3f(7,-42,0.0);
    glVertex3f(7,-36,0.0);
    glEnd();

    glBegin(GL_LINES);          //left leg
    glColor3ub(255,255,255);
    glVertex3f(3.5,-42,0.0);
    glVertex3f(3.5,-46,0.0);
    glEnd();

    glBegin(GL_LINES);          //left leg
    glColor3ub(255,255,255);
    glVertex3f(6.5,-42,0.0);
    glVertex3f(6.5,-46,0.0);
    glEnd();

    glPushMatrix();             //leg circle left
    glTranslatef(3.5,-46,0);
    circle(1);
    glPopMatrix();

    glPushMatrix();             //leg circle right
    glTranslatef(6.5,-46,0);
    circle(1);
    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(128,0,0);        //flag hand
    glVertex3f(10,-22,0.0);
    glVertex3f(10,-28,0.0);
    glVertex3f(10.5,-28,0.0);
    glVertex3f(10.5,-22,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,128,0);        //flag
    glVertex3f(10,-20,0.0);
    glVertex3f(10,-24,0.0);
    glVertex3f(13,-24,0.0);
    glVertex3f(13,-20,0.0);
    glEnd();

    glPushMatrix();
    glColor3ub(255,0,0);        //flag circle
    glTranslatef(11.5,-22,0);
    circle(1);
    glPopMatrix();

}

void car()
{

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //Car body
    glVertex3f(-33,-25,0.0);
    glVertex3f(-33,-38,0.0);
    glVertex3f(-27,-38,0.0);
    glVertex3f(-27,-25,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(64,0,32);
    glVertex3f(-32,-25,0.0);  //up left
    glVertex3f(-34,-25,0.0);
    glVertex3f(-34,-36,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(64,0,32);
    glVertex3f(-32,-38,0.0);
    glVertex3f(-34,-38,0.0);  //d0wn left
    glVertex3f(-34,-42,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(64,0,32);
    glVertex3f(-28,-25,0.0);  //up right
    glVertex3f(-26,-25,0.0);
    glVertex3f(-26,-36,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(64,0,32);
    glVertex3f(-28,-38,0.0);  //down right
    glVertex3f(-26,-38,0.0);
    glVertex3f(-26,-42,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //right looking glass
    glVertex3f(-26,-25,0.0);
    glVertex3f(-26,-26.5,0.0);
    glVertex3f(-24.5,-27,0.0);
    glVertex3f(-24.5,-25,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //left looking glass
    glVertex3f(-34,-25,0.0);
    glVertex3f(-34,-26.5,0.0);
    glVertex3f(-35.5,-27,0.0);
    glVertex3f(-35.5,-25,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //Car body up
    glVertex3f(-33,-25,0.0);
    glVertex3f(-33,-20,0.0);
    glVertex3f(-27,-20,0.0);
    glVertex3f(-27,-25,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //Car body down
    glVertex3f(-33,-41,0.0);
    glVertex3f(-33,-45,0.0);
    glVertex3f(-27,-45,0.0);
    glVertex3f(-27,-41,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //car body right
    glVertex3f(-26,-43,0.0);
    glVertex3f(-26,-23,0.0);
    glVertex3f(-25.5,-23,0.0);
    glVertex3f(-25.5,-43,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(240,240,0);
    glVertex3f(-25.5,-23,0.0);
    glVertex3f(-27,-20,0.0);
    glVertex3f(-27,-23,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);
    glVertex3f(-25.5,-43,0.0);
    glVertex3f(-27,-45,0.0);
    glVertex3f(-27,-43,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);
    glVertex3f(-27,-25,0.0);
    glVertex3f(-27,-23,0.0);
    glVertex3f(-26,-23,0.0);
    glVertex3f(-26,-25,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);
    glVertex3f(-27,-43,0.0);
    glVertex3f(-27,-41,0.0);
    glVertex3f(-26,-41,0.0);
    glVertex3f(-26,-43,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);        //car body left
    glVertex3f(-34,-43,0.0);
    glVertex3f(-34,-23,0.0);
    glVertex3f(-34.5,-23,0.0);
    glVertex3f(-34.5,-43,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(240,240,0);
    glVertex3f(-34.5,-23,0.0);
    glVertex3f(-33,-23,0.0);
    glVertex3f(-33,-20,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);
    glVertex3f(-34.5,-43,0.0);
    glVertex3f(-33,-45,0.0);
    glVertex3f(-33,-43,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);
    glVertex3f(-33,-25,0.0);
    glVertex3f(-33,-23,0.0);
    glVertex3f(-34,-23,0.0);
    glVertex3f(-34,-25,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(64,0,32);
    glVertex3f(-34.5,-43,0.0);
    glVertex3f(-34.5,-41,0.0);
    glVertex3f(-33,-41,0.0);
    glVertex3f(-33,-43,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(-33,-28,0.0);        //Car glass up
    glVertex3f(-33,-25,0.0);
    glVertex3f(-27,-25,0.0);
    glVertex3f(-27,-28,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-27,-25,0.0);
    glVertex3f(-26.25,-25,0.0);
    glVertex3f(-27,-28,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-33,-25,0.0);
    glVertex3f(-33.75,-25,0.0);
    glVertex3f(-33,-28,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(-33,-38,0.0);        //Car glass down
    glVertex3f(-33,-41,0.0);
    glVertex3f(-27,-41,0.0);
    glVertex3f(-27,-38,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-27,-41,0.0);
    glVertex3f(-26.25,-41,0.0);
    glVertex3f(-27,-38,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-33,-38,0.0);
    glVertex3f(-33.75,-41,0.0);
    glVertex3f(-33,-41,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(-27,-28,0.0);        //Car glass right
    glVertex3f(-27,-38,0.0);
    glVertex3f(-26,-38,0.0);
    glVertex3f(-26,-28,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-27,-28,0.0);
    glVertex3f(-26,-27.25,0.0);
    glVertex3f(-26,-28,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-27,-38,0.0);
    glVertex3f(-26,-38.75,0.0);
    glVertex3f(-26,-38,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,255,255);
    glVertex3f(-33,-38,0.0);        //Car glass left
    glVertex3f(-33,-28,0.0);
    glVertex3f(-34,-28,0.0);
    glVertex3f(-34,-38,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-33,-38,0.0);
    glVertex3f(-34,-38.75,0.0);
    glVertex3f(-34,-38,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128,255,255);
    glVertex3f(-33,-28,0.0);
    glVertex3f(-34,-27.25,0.0);
    glVertex3f(-34,-28,0.0);
    glEnd();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    day();
    greenField();
    railRoad();
    Road();
    Buildings();
    Trees();
    menWithFlag();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(inc2,0.0,0.0);
    glScalef(.8,1,0);
    cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(inc,0.0,0.0);
    glScalef(1,1,0);
    train();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(inc3,0.0,0.0);
    glScalef(1,1,0);
    railGate();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,inc4,0.0);
    glScalef(1,.6,0);
    car();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(ll,0.0,0.0);
    glTranslatef(inc,0.0,0.0);
    glScalef(1,1,0);
    light();
    glPopMatrix();


//    glPushMatrix();
//    glRotatef(90.0, 0.0, 0.0, 1.0);
//    glTranslatef(38.0,50+inc5,0.0);
//    glScalef(1,.6,0);
//    car();
//    glPopMatrix();

    glutPostRedisplay();
    glFlush();
}

void Animation()
{
    inc = inc - .03;
    if(inc < -80)
    {
        inc = 50;
    }

    inc2 = inc2  .004;
    if(inc2 < -80)
    {
        inc2 = 50;
    }

    inc4 = inc4 + .03 ;

    if(inc3 < -10)
    {
        inc4 = -2 ;
    }
    else if(inc4 > 30 )
    {
        inc4 = -70;

    }

    inc5 = inc5 + .01 ;
    if(inc5 > 80)
    {
        inc5 = 0 ;
    }

    if( inc4 > 10  && inc  < -30    )
    {
        PlaySound("smash.wav",NULL,SND_FILENAME|SND_LOOP|SND_SYNC);
        exit(0);
    }

    glutPostRedisplay();
}
void animationGate()
{

    inc3 = inc3 - .5;
    if(inc3 < -20)
    {
        inc3 = -20 ;
    }

}
void animationGate2()
{
    inc3 = inc3 + .5 ;
    if(inc3 > 0)
    {
        inc3 = 0 ;
    }

}

void update(int i)
{
    if( i == 0)
    {
      animationGate();
    }
    else if( i == 1)
    {
        animationGate2();
    }

    glutPostRedisplay();
    glutTimerFunc(25,update,i);
}

void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(Animation);
            PlaySound("sound.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
            PlaySound(NULL, NULL, 0);
        }
        break;
    default:
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

    case 'd' :
    red=0.0;
    green=0.749;
    blue=1.0;

    r=1,g=1,b=0;

    ll=1000;
    break;


    case 'D' :
    red=0.0;
    green=0.749;
    blue=1.0;

    r=1,g=1,b=0;

    ll=1000;
    break;

    case 'n':
    red=0.0;
    green=0.0;
    blue=0.0;

    r=1,g=1,b=1;

    ll=0.0;

    break;

    case 'N':
    red=0.0;
    green=0.0;
    blue=0.0;

    r=1,g=1,b=1;

    ll=0.0;

    break;

    default:
    break;
    }
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_LEFT:
          update(0);
            break;

      case GLUT_KEY_RIGHT:
          update(1);
            break;
    }

}

void init(void)
{
    glClearColor (1,1,1,1);
    glOrtho(-50.0,50.0, -50.0, 50.0, -1.0, 1.0);
}

int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Train View");
    init();
    glutDisplayFunc(display);
	glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboard);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler
    glutMainLoop();
    return 0;
}
