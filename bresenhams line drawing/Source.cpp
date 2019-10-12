#include<GL/Glut.h> 
#include<stdlib.h>
#include<math.h>
#include <iostream>

using namespace std;

void myinit(void)
{
 
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // multiply the current matrix by identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
 }
 
float xstart,ystart,xend,yend,x,y;

int Round(float a)//any x i.e 1>=a>=0.5 is rounded to 1
{
  if(a-int(a)>=0.5)
  return int(a)+1;
  else
  return int(a);
     }

void bressen()
     {   
       float ydiff = yend-ystart;
       float xdiff = xend-xstart;  
       
        float p0;
         p0 = 2*(ydiff)-xdiff; 
           
        x = xstart;               //assign xstart to x
        y = ystart;              //assign ystart to y

while ((x != xend+1)&&(y != yend+1))
      {   
       glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(Round(x),Round(y));//sets vertex
	   glEnd();
if (p0<0)   
       {
		x = x+1;
		y = y;
		p0=p0+2*(ydiff);
       }
       else
       {
         x=x+1;
         y=y+1;
         p0=2*(ydiff)-2*(xdiff);
       }
 
}
  
  glutPostRedisplay(); 
  } 
       
void display(void)
{  
     
    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call     
    glColor3f(0,0,1); // sets the current drawing (foreground) color to blue 
    glPointSize(6); // sets the size of points to be drawn (in pixels)
    bressen();// calls programmer defined function(drawline)
    glFlush(); // flushes the frame buffer to the screen
}

int main(int argc,char* argv[])
{
	cout << "Enter the value of xstart : ";
	cin >> xstart;
	cout << "Enter the value of ystart : ";
	cin >> ystart;
	cout << "Enter the value of xend: ";
	cin >> xend;
	cout << "Enter the value of yend : ";
	cin >> yend;


	glutInit(&argc,argv);
    glutInitWindowSize(640,480);//sets the width and height of the window in pixels
    glutInitWindowPosition(10,10);//sets the position of the window in pixels from top left corner 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("Bressenham Line Drawing");//creates the window as specified by the user as above.
	myinit();
	glutDisplayFunc(display);//links the display event with the display event handler(display)
    glutIdleFunc(bressen);
    glutMainLoop();//loops the current event
}