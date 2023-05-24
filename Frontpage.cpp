#include <glut.h>
#include <stdio.h>

void front();
void keyboard(unsigned char, int, int);
void button();
void println(float, float, void *, char[]);
void about();
void help();
void binarytree();


int n;


//Function to print characters on screen.
void println(float x, float y, void *font, char str[]) {
  glRasterPos2f(x, y);
  for (int i = 0; str[i] != '\0'; i++) {
    glutBitmapCharacter(font, str[i]);
  }
}

void keyboard(unsigned char keys, int x, int y) {

 //for menu page
  if (keys == 'm'||keys=='M') {
    glutDisplayFunc(button);
    glutPostRedisplay();
  } 
  if (keys==13){
	  glutDisplayFunc(button);
	  glutPostRedisplay();
  }
  if(keys=='a'||keys=='A')
  {
   glutDisplayFunc(about);
    glutPostRedisplay();
  } 
  if(keys=='h'||keys=='H')
  {
   glutDisplayFunc(help);
    glutPostRedisplay();
  } 
    
  if(keys=='B'||keys=='b'||keys==8)
  {
   glutDisplayFunc(front);
    glutPostRedisplay();
  }
  if(keys=='E'||keys=='e')
  {
   exit(0);
  }
  if(keys=='Q'||keys=='q'){
	  glutDisplayFunc(binarytree);
	  glutPostRedisplay();
  }
  if (keys == '1') {
    glutDisplayFunc(front);
    glutPostRedisplay();
  } 
  if(keys=='2')
  {
   glutDisplayFunc(front);
    glutPostRedisplay();
  } 
  if(keys=='3')
  {
    glutDisplayFunc(front);
    glutPostRedisplay();
  } 
  if(keys=='4')
  {
    glutDisplayFunc(button);
    glutPostRedisplay();
  } 
  
}






void binarytree(){
  glClearColor(0.8, 0.8, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);
  println(140.0, 360.0, GLUT_BITMAP_TIMES_ROMAN_24,"WELCOME TO BINARY TREE OPERATIONS"); 
 
  println(160.0, 300.0, GLUT_BITMAP_HELVETICA_18,"1.Algorithm"); 
 glutKeyboardFunc(keyboard);
 println(160.0, 280.0, GLUT_BITMAP_HELVETICA_18,"2.Flow Chart"); 
  glutKeyboardFunc(keyboard);
 println(160.0, 260.0, GLUT_BITMAP_HELVETICA_18,"3.Binary Tree Operations"); 
  glutKeyboardFunc(keyboard);
  println(160.0, 240.0, GLUT_BITMAP_HELVETICA_18,"4.Back "); 
  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();

}

//Function to print front page 
void front() {
 

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glColor3f(0.8,1.0,0.5);
 glBegin(GL_POLYGON);
 
 glVertex2i(0,0);
 glVertex2i(1500,0);
 glVertex2i(1500,200);
 glVertex2i(0,200);
 glEnd();
  glLoadIdentity();
  glColor3f(0, 0, 0);
  println(140.0, 370.0, GLUT_BITMAP_TIMES_ROMAN_24," *    SDM INSTITUTE OF TECHNOLOGY    *");

  glColor3f(0.7, 0, 0);
  println(113.0, 350.0, GLUT_BITMAP_TIMES_ROMAN_24,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");

  glColor3f(1, 0.5, 0);
  println(113.0, 330.0,GLUT_BITMAP_TIMES_ROMAN_24,"COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT ");

  glColor3f(1, 0, 0);
  println(170.0, 260.0, GLUT_BITMAP_TIMES_ROMAN_24, "A MINI PROJECT ON");

  glColor3f(0.5, 0.5, 0.0);
  println(160.0, 240.0, GLUT_BITMAP_TIMES_ROMAN_24,"BINARY TREE OPERATIONS");

  glColor3f(1.0, 0.0, 0.0);
  println(25.0, 120.0, GLUT_BITMAP_TIMES_ROMAN_24, "BY:");
  println(25.0, 120.0,GLUT_BITMAP_TIMES_ROMAN_24, "__");

  glColor3f(0.7, 0.0, 1.0);
  println(25.0, 100.0,GLUT_BITMAP_TIMES_ROMAN_24,"CHARAN K (4SU20CS020)");

  glColor3f(0.7, 0.0, 1.0);
  println(25.0, 80.0,GLUT_BITMAP_TIMES_ROMAN_24,"DARSHAN C S (4SU20CS022)");

  glColor3f(0.7, 0.0, 1.0);
  println(25.0, 60.0, GLUT_BITMAP_TIMES_ROMAN_24,"G S DEEPAK PATIL (4SU20CS030)");

  glColor3f(0.7, 0.0, 1.0);
  println(25.0, 40.0, GLUT_BITMAP_TIMES_ROMAN_24,"GHANASHYAMA K P MAKKITTHAYA (4SU20CS031)");

  glColor3f(1.0, 0.0, 0.0);
  println(320.0, 120.0,GLUT_BITMAP_TIMES_ROMAN_24, "GUIDE:");
  println(320.0, 120.0,GLUT_BITMAP_TIMES_ROMAN_24, "______");

  glColor3f(0.7, 0.0, 1.0);
  println(300.0, 100.0,GLUT_BITMAP_TIMES_ROMAN_24,"DR.RAGHAVENDRA PATEL G E");
  println(300.0, 80.0,GLUT_BITMAP_TIMES_ROMAN_24,"ASSISTANT PROFESSOR");
  println(300.0, 60.0,GLUT_BITMAP_TIMES_ROMAN_24,"DEPT OF CSE");


  glColor3f(0.0, 0.5, 0.0);
 println(160.0,210.0,GLUT_BITMAP_TIMES_ROMAN_24,"PRESS ENTER TO CONTINUE");
  //glColor3f(0.0,0.0,0.0);
  //println(160.0,180.0,GLUT_BITMAP_TIMES_ROMAN_24,"PRESS BACKSPACE TO EXIT");
  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();
}



void button() {
  glClearColor(0.8, 0.8, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  println(180.0,350.0,GLUT_BITMAP_TIMES_ROMAN_24,"MENU PAGE");
  glColor3f(0.0f, 0.0f, 0.0f);
  println(180.0, 290.0, GLUT_BITMAP_TIMES_ROMAN_24," MENU : PRESS M");
   glutKeyboardFunc(keyboard);
  println(180.0,270.0,GLUT_BITMAP_TIMES_ROMAN_24,"ABOUT: PRESS A");
  glutKeyboardFunc(keyboard);
   println(180.0,250.0,GLUT_BITMAP_TIMES_ROMAN_24," HELP : PRESS H");
   glutKeyboardFunc(keyboard);
   println(180.0,230.0,GLUT_BITMAP_TIMES_ROMAN_24," BACK : PRESS B");
  glutKeyboardFunc(keyboard);
  println(160.0,310.0,GLUT_BITMAP_TIMES_ROMAN_24,"Binary Tree Operations: PRESS Q");
  glutKeyboardFunc(keyboard);
  println(180.0,210.0,GLUT_BITMAP_TIMES_ROMAN_24," EXIT : PRESS E");
  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();

}

void about() {
  glClearColor(1.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  println(185.0, 360.0, GLUT_BITMAP_TIMES_ROMAN_24,"ABOUT US");
  println(30.0, 320.0, GLUT_BITMAP_TIMES_ROMAN_24,"CHARAN K");
  glColor3f(1.0f, 0.0f, 1.0f);
  println(30.0, 305.0, GLUT_BITMAP_HELVETICA_18,"USN: 4SU20CS020");
  println(30.0, 290.0, GLUT_BITMAP_HELVETICA_18,"III year, Dept of CSE");
  println(30.0, 275.0, GLUT_BITMAP_HELVETICA_18,"Address: Near Shuddh Hani Factory, Madanthayar,574224");

  glColor3f(1.0f, 0.0f, 0.0f);
  println(230.0, 320.0, GLUT_BITMAP_TIMES_ROMAN_24,"DARSHAN C S");
  glColor3f(1.0f, 0.0f, 1.0f);
  println(230.0, 305.0, GLUT_BITMAP_HELVETICA_18,"USN: 4SU20CS022");
  println(230.0, 290.0, GLUT_BITMAP_HELVETICA_18,"III year, Dept of CSE");
  println(230.0, 275.0, GLUT_BITMAP_HELVETICA_18,"Address: Govt. Highschool(opp) Sannaysikodamagge,Shivamogga,577243");

  glColor3f(1.0f, 0.0f, 0.0f);
  println(30.0, 225.0, GLUT_BITMAP_TIMES_ROMAN_24,"G S DEEPAK PATIL");
  glColor3f(1.0f, 0.0f, 1.0f);
  println(30.0, 210.0, GLUT_BITMAP_HELVETICA_18,"USN: 4SU20CS030");
  println(30.0, 195.0, GLUT_BITMAP_HELVETICA_18,"III year, Dept of CSE");
  println(30.0, 180.0, GLUT_BITMAP_HELVETICA_18,"Address:Near Anjinaya Swami Temple, Devareddy Halli, Challakere,577529 ");

  glColor3f(1.0f, 0.0f, 0.0f);
  println(230.0, 225.0, GLUT_BITMAP_TIMES_ROMAN_24,"GHANASHYAMA K P MAKKITTHAYA");
  glColor3f(1.0f, 0.0f, 1.0f);
  println(230.0, 210.0, GLUT_BITMAP_HELVETICA_18,"USN: 4SU20CS031");
  println(230.0, 195.0, GLUT_BITMAP_HELVETICA_18,"III year, Dept of CSE");
  println(230.0, 180.0, GLUT_BITMAP_HELVETICA_18,"Address: Ist Cross Gundibailu, Kunjibettu, Udupi,576102");
  
  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();

}

//Function to print help page.
void help() {

  glClearColor(0.8, 0.8, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);
  
  println(185.0, 360.0, GLUT_BITMAP_TIMES_ROMAN_24,"HELP ");

  
  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();
}


int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1500, 600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Binary Tree Operations");
  glutDisplayFunc(front);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(10.0, 400.0, 10.0, 400.0);
  glMatrixMode(GL_MODELVIEW);
  glutFullScreen();
  glutMainLoop();
  return 0;
}
