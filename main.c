// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include "vec3.h"
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

typedef struct {
    float x;
    float y;
} pos_t;

typedef struct {
    Vec3_t pos;
    Vec3_t velocity;
    Vec3_t acceleration;
    float rad;
    float color[3];  
} Ball_t;

Ball_t firstBall;

// initialises a ball and adds it to the screen
void addBall() {
    firstBall.pos.x = 0;
    firstBall.pos.y = 0;
    firstBall.velocity.x = 0;
    firstBall.velocity.y = 0;
    firstBall.acceleration.x = 0;
    firstBall.acceleration.y = -0.1; // Simulated gravity
    firstBall.rad = 50; // Radius of the ball
}

void updateBall() {
    firstBall.pos.y -= 1.0;
    // check boundaries -> TODO: move to a function


    printf("updating ball x:%f y:%f\n", firstBall.pos.x, firstBall.pos.y);
}

void update(int value) {
    updateBall();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (approximately 60 frames per second)
}
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    glClearColor(0.0, 0.0, 0.0, .0); 
      
    // making picture color green 
    glColor3f(0.0, 1.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 

    // init first ball
} 

void DrawCircle(Vec3_t center, int radius) {
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    // iterate y up to 2*pi, i.e., 360 degree 
    // with small increment in angle as 
    // glVertex2i just draws a point on specified co-ordinate 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = center.x + radius * cos(i); 
        y = center.y + radius * sin(i); 
          
        glVertex2i(x, y); 
    } 
    glEnd(); 
}
  
void display (void)  
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  Vec3_t center = {0, 0, 0};
  DrawCircle(center, 200);
  DrawCircle(firstBall.pos, firstBall.rad);

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
    glutTimerFunc(0, update, 0);
    glutMainLoop(); 
} 
