#include <glut.h>
#include <stdio.h>
#include <process.h>
void front();
void keyboard(unsigned char, int, int);
void button();
void println(float, float, void *, char[]);
void about();
void help();
void binarytree();
void flowchart();
void draw_poly(GLfloat a,GLfloat b,GLfloat c,GLfloat d);
void draw_line(GLint x, GLint y,GLint m, GLint n);
void draw_tri(GLint a,GLint b,GLint c,GLint d,GLint e,GLint f);
void algo();
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
    glutDisplayFunc(algo);
    glutPostRedisplay();
  } 
  if(keys=='2')
  {
   glutDisplayFunc(flowchart);
    glutPostRedisplay();
  } 
  if(keys=='3')
  {
    // glutDisplayFunc(front);
    // glutPostRedisplay();
    execl("./traverse.exe", "./traverse", NULL);
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
 //glutKeyboardFunc(keyboard1);
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
  println(130.0, 370.0, GLUT_BITMAP_TIMES_ROMAN_24," *    SDM INSTITUTE OF TECHNOLOGY, UJIRE   *");

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

void flowchart()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0.8f, 0.6f, 0.7f);
  
  println(185.0, 360.0, GLUT_BITMAP_TIMES_ROMAN_24,"FLOWCHART ");
  draw_line(180,358,230,358);

  glColor3f(1.0f, 0.0f, 0.0f);
  draw_poly(185.0,320.0,225.0,340.0);
  println(195.0, 328.0, GLUT_BITMAP_TIMES_ROMAN_24,"BEGIN ");
  draw_line(205,320,205,300);
  draw_tri(208,304,202,304,205,300);
  println(213.0, 308.0, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'ENTER' ");

  glColor3f(0.0f, 1.0f, 0.0f);
  draw_poly(180.0,280.0,230.0,300.0);
  println(185.0, 288.0, GLUT_BITMAP_TIMES_ROMAN_24,"Menu Window ");
  draw_line(205,280,205,260);
  draw_tri(208,264,202,264,205,260);
  println(213.0, 268.0, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'Q' ");

  glColor3f(0.0f, 0.0f, 1.0f);
  draw_poly(170.0,240.0,240.0,260.0);
  println(171.0, 248.0, GLUT_BITMAP_TIMES_ROMAN_24,"Binary Operations window");
  draw_line(205,240,205,220);
  draw_tri(208,224,202,224,205,220);


  glColor3f(1.0f, 0.0f, 1.0f);
  draw_poly(170.0,200.0,240.0,220.0);
  println(175.0, 208.0, GLUT_BITMAP_TIMES_ROMAN_24,"Input elements to Tree");
  draw_line(205,200,205,180);
  draw_tri(208,184,202,184,205,180);
  println(213.0, 188.0, GLUT_BITMAP_TIMES_ROMAN_24,"Enter a number and Press 'i' ");

  glColor3f(0.0f, 1.0f, 1.0f);
  draw_poly(170.0,160.0,240.0,180.0);
  println(175.0, 168.0, GLUT_BITMAP_TIMES_ROMAN_24,"Press Traversal Button");
  draw_line(205,160,205,140);
  draw_tri(208,144,202,144,205,140);

  glColor3f(1.0f, 1.0f, 0.0f);
  draw_poly(140.0,120.0,270.0,140.0);
  println(145.0, 128.0, GLUT_BITMAP_TIMES_ROMAN_24,"  The Traversals(Inorder,Preorder,Postorder)");
  draw_line(205,120,205,100);
  draw_tri(208,104,202,104,205,100);


  glColor3f(1.0f, 1.0f, 1.0f);
  draw_poly(185.0,80.0,225.0,100.0);
  println(195.0, 88.0, GLUT_BITMAP_TIMES_ROMAN_24," END");

  glutKeyboardFunc(keyboard);
  glFlush();
  glutPostRedisplay();

}

void draw_poly(GLfloat a,GLfloat b,GLfloat c,GLfloat d)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(a,b);
	glVertex2f(c,b);
	glVertex2f(c,d);
	glVertex2f(a,d);
	glEnd();
}
void draw_line(GLint x, GLint y,GLint m, GLint n)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(m,n);
	
	glEnd();
}
void draw_tri(GLint a,GLint b,GLint c,GLint d,GLint e,GLint f)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(a,b);
	glVertex2f(c,d);
	glVertex2f(e,f);
	glEnd();
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

void algo()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  
  println(185.0, 360.0, GLUT_BITMAP_TIMES_ROMAN_24,"ALGORITHM ");
  draw_line(180,358,230,358);

  println(125.0, 330.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 1 : Click on Run button in Visual Studio after the project is opened.");

  println(125.0, 310.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 2 : Press Enter to open main menu page");

  println(125.0, 290.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 3 : For Binary Operations press 'Q'.");

  println(125.0, 270.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 4 : Press 3 for Operations");

  println(125.0, 250.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 5 : Enter the number to tree and press 'i' to insert.");

  println(125.0, 230.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 6 : For deletion press 'd'. ");

  println(125.0, 210.0, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 7 : For Traversal click Inorder, Postorder or Preorder Button");

  println(125.0, 190, GLUT_BITMAP_TIMES_ROMAN_24,"STEP 8 : Press 'E' to exit the execution");
  



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
