#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


float angle=0.0f;
float red=1.0f, blue=1.0f, green=1.0f;

//Drawing function
void draw(void)
{
  //Background color
  glClearColor(0,1,0,1);
  glClear(GL_COLOR_BUFFER_BIT );
  //Draw order
  glFlush();
}
//Render scene
void render_scene(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glLoadIdentity();
  
  //Set Camera
  gluLookAt(
			0.0f, 0.0f, 10.0f,
			0.0f, 0.0f,  0.0f,
			0.0f, 1.0f,  0.0f
	   );
  
  glRotatef(angle, 0.0f, 0.0f, 1.0f);
  
  glColor3f(red,green,blue);
  
  glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
  glEnd();
  
  angle+=0.1f;
  
  glutSwapBuffers();
}


void process_normal_keys(unsigned char key, int x, int y){
    if(key==27){
	exit(0);
    }
}    
 void process_special_keys(int key, int x, int y){
 switch(key) {
		case GLUT_KEY_F1 :
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
	}
 }


//Reshape function

void change_size(int width, int height){
    float ratio;
    if(height ==0){
      height=1;
    }
    printf("\n%d x %d", width, height);
    ratio= 1.0 * width / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    
    gluPerspective(45, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

//Main program
int main(int argc, char **argv)
{
  
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800 ,600);
  
  glutCreateWindow("Green window");
  //Call to the drawing function
  //glutDisplayFunc(draw);
  glutDisplayFunc(render_scene);
  glutReshapeFunc(change_size); 
  
  glutIdleFunc(render_scene);
  
  glutKeyboardFunc(process_normal_keys);
  glutSpecialFunc(process_special_keys);

  
  glutMainLoop();
  
  return 1;
}