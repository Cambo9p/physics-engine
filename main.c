
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

typedef struct {
    // need the pos, acceleration and prev location 
} ball;
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(0.0, 1.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} 

void DrawCircle(int radius) {
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    // iterate y up to 2*pi, i.e., 360 degree 
    // with small increment in angle as 
    // glVertex2i just draws a point on specified co-ordinate 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = radius * cos(i); 
        y = radius * sin(i); 
          
        glVertex2i(x, y); 
    } 
    glEnd(); 
}
  
void display (void)  
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  DrawCircle(200);
  DrawCircle(12);

  // Draw the Polygon First
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
     glVertex2i(50,90);
     glVertex2i(100,90);
     glVertex2i(100,150);
     glVertex2i(50,150);
  glEnd();

    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 