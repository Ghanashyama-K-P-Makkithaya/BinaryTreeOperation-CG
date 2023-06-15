#include <process.h>
#include <stdlib.h>
#include <windows.h>
#include <glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.141592
#define size 512
typedef struct
{
	char data[5];
	int value, left, right, key, level, parent;
	float x, y;
}node;
node a[30];
int p[20];
float color[6][3] = { { 0.0, 0.2, 0.5 }, { 0.5, 0.4, 0.5 }, { 0.0, 1.0, 0.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } ,{0.5f, 0.0f, 1.0f}};
int n = 0;
int flag = 1, ins = 0, del = 0, pre = 0, in = 0, post = 0, ex = 0, rflag = 0, lflag = 0, eflag = 1,eqflag=0;
int count = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
float rad = 1.0;
void delay(int limit=50000)
{
	printf("IN delay Func\n");
	int i, j;
	for (i = 0; i<limit; i++)
	for (j = 0; j<10000; j++);
}
void drawstring(float x, float y, char *string, int col)
{
	printf("IN drawstring Func\n");
	char *c;
	glColor3fv(color[col]);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void drawWindow(int x1, int y1, int x2, int y2)
{
	printf("IN drawWindow Func\n");
	glColor3f(0.5f, 0.0f, 1.0f);
	drawstring(9.0, 27.0,(char*)"TREE TRAVERSAL TECHINQUES", 1);
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex2i(x2, y1);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(x2, y2);
	glColor3f(1.0f, 0.0f, 1.5f);
	glVertex2i(x1, y2);
	glEnd();
	glLineWidth(1);
	glFlush();
}
void drawWindow2(float x1, float y1, float x2, float y2)
{
	printf("IN drawWindow Func\n");
	glColor3f(0.5f, 0.0f, 1.0f);
	
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex2f(x2, y1);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(x2, y2);
	glColor3f(1.0f, 0.0f, 1.5f);
	glVertex2f(x1, y2);
	glEnd();
	glLineWidth(1);
	glFlush();
}
void preorder()
{
	printf("IN preorder Func\n");
	int stack[20], top = -1, cur, j = 0,temp;
	cur = 0;
	for (;;)
	{
		while (cur != -1)
		{
			p[j++] = cur;
			stack[++top] = cur;
			cur = a[cur].left;
			temp=j;
		}
		if (top != -1)
		{
			cur = stack[top--];
			cur = a[cur].right;
		}
		else
			break;
	}
	printf("STACK ELEMNTS FOR PRE ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);

}
void inorder()
{
	printf("IN inorder Func\n");
	int stack[20], top = -1, cur, j = 0,temp;
	cur = 0;
	for (;;)
	{
		while (cur != -1)
		{
			stack[++top] = cur;
			cur = a[cur].left;
		}
		if (top != -1)
		{
			cur = stack[top--];
			p[j++] = cur;
			cur = a[cur].right;
			temp=j;
		}
		else
			break;
	}
	printf("STACK ELEMNTS FOR IN ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);
}
void postorder()
{
	printf("IN postorder Func\n");
	struct stack
	{
		int address, flag;
	};
	int cur = 0, j = 0, top = -1,temp;
	struct stack s[20];
	top++;
	for (;;)
	{
		while (cur != -1)
		{
			top++;
			s[top].address = cur;
			s[top].flag = 1;
			cur = a[cur].left;
		}
		while (s[top].flag<0)
		{
			cur = s[top].address;
			top--;
			p[j++] = cur;
			temp=j;
			if (top == -1)
				return;
		}
		cur = s[top].address;
		cur = a[cur].right;
		s[top].flag = -1;
	}
	printf("STACK ELEMNTS FOR post ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);
}
void menu(GLenum mode)
{
	printf("IN menu Func\n");
	glColor3f(1,0,0);
	drawWindow2(24.5, 24, 29, 26);
	glColor3fv(color[c1]);
	if (mode == GL_SELECT)
		glLoadName(0);

	//glRecti(25, 24, 29, 26);
	glRecti(2, 2, 6, 4);
	//drawstring(26, 25, "INSERT", 2);
	drawstring(3, 3,(char*) "INSERT", 2);
	glColor3fv(color[c2]);
	if (mode == GL_SELECT)
		glLoadName(1);
	//glRecti(25, 21, 29, 23);
	glRecti(8, 2, 12, 4);
	//drawstring(26, 22, "DELETE", 2);
	drawstring(9, 3, (char*)"DELETE", 2);
	glColor3fv(color[c3]);
	if (mode == GL_SELECT)
		glLoadName(2);
	//glRecti(25, 18, 29, 20);
	glRecti(14, 2, 18, 4);
	//drawstring(26, 19, "PREORDER", 2);
	drawstring(15, 3, (char*)"PREORDER", 2);
	glColor3fv(color[c4]);
	if (mode == GL_SELECT)
		glLoadName(3);
	//glRecti(25, 15, 29, 17);
	glRecti(20, 2, 24, 4);
	//drawstring(26, 16, "INORDER", 2);
	drawstring(21, 3, (char*)"INORDER", 2);
	glColor3fv(color[c5]);
	if (mode == GL_SELECT)
		glLoadName(4);
	//glRecti(25, 12, 29, 14);
	glRecti(26, 2, 29, 4);
	//drawstring(26, 13, "POSTORDER", 2);
	drawstring(26.1, 3, (char*)"POSTORDER", 2);
	glColor3fv(color[c6]);
	if (mode == GL_SELECT)
		glLoadName(5);
	glRecti(25, 9, 29, 11);
	drawstring(26, 10, (char*)"EXIT", 2);
	
}
void drawbox(float x, float y, float w, int key, int c)
{
	printf("IN drawbox Func\n");
	int j = 0;
	glColor3fv(color[c]);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x, y + w);
	glVertex2f(x + w, y + w);
	glVertex2f(x + w, y);
	glEnd();
	glFlush();
	glRasterPos2f(x + w / 2.0, y + w / 2.0f);
	while (a[key].data[j] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[key].data[j++]);
	glFlush();
}
void drawnode(int i, int c)
{
	printf("IN drawnode Func\n");
	float angle, x, y;
	int j = 0;
	glColor3fv(color[c]);
	glBegin(GL_POINTS);
	for (angle = 0.0; angle <= 2 * pi; angle += pi / 100.0f)
	{
		x = 0.75*cos(angle) + a[i].x;
		y = rad*sin(angle) + a[i].y;
		glVertex2f(x, y);
	}
	glEnd();
	glRasterPos2f(a[i].x, a[i].y);
	//printf("%f,%f %F",a[i].x, a[i].y,a[i].data);
	while (a[i].data[j] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i].data[j++]);
	glFlush();
}
void processHits(GLuint hits, GLuint buffer[])
{
	printf("IN processHits Func\n\n ");

	GLuint *ptr;
	ptr = (GLuint *)buffer;
	ptr += 3;
	if (*ptr == 0)
	{
		c1++;
		ins = 1;
	}
	if (*ptr == 1)
	{
		c2++;
		del = 1;
	}
	if (*ptr == 2)
	{
		c3++;
		pre = 1;
	}
	if (*ptr == 3)
	{
		c4++;
		in = 1;
	}
	if (*ptr == 4)
	{
		c5++;
		post = 1;
	}
	if (*ptr == 5)
	{
		c6++;
		ex = 1;
	}
}
// void title()	 // to draw the starting screen
// {
// 	printf("IN title Func \n\n\n");
// 	drawstring(5.0, 30.0, (char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
// 	drawstring(5.0, 28.0, (char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
// 	drawstring(5.0, 26.0, (char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~TREE TRAVERSAL TECHINQUES~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
// 	drawstring(5.0, 24.0, (char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
// 	drawstring(5.0, 22.0, (char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	
// 	drawstring(20.0, 10.0, (char*)"SUBMITTED   BY", 0);
// 	drawstring(20.0, 8.0, (char*)"NAME: V R ROHITH", 0);
// 	drawstring(2.0, 2.0, (char*)"*  *LEFT CLICK THE MOUSE TO CONTINUE*  *", 3);
// 	glFlush();
// }

void drawedge(int root, int i, int c)
{
	printf("IN drawedge Func\n");
	glColor3fv(color[c]);
	glBegin(GL_LINES);
	glVertex2f(a[root].x, a[root].y - rad);
	glVertex2f(a[i].x, a[i].y + rad);
	glEnd();
	glFlush();
}
int FindPosition(int i)
{
	// printf("IN findposition Func\n");
	int root = 0;
	
	while (root<i)
	{
		if(a[i].value==i)
		{
		//eqflag=0;
		printf("equal");
		//break;
		// glutPostRedisplay();
		//continue;
		//return 0;
		}
		//printf("skipped equal");
	
		while (a[i].value<a[root].value && (a[root].left != -1))
			root = a[root].left;
		while (a[i].value>a[root].value && (a[root].right != -1))
			root = a[root].right;
		if (a[i].value<a[root].value && (a[root].left == -1))
		{
			lflag = 1;
			a[i].level = a[root].level + 1;
			a[i].x = a[root].x - (4.0f / a[i].level);
			a[i].y = a[root].y - 3;
			a[root].left = a[i].key;
			a[i].parent = root;
			return root;
		}
		else if (a[i].value>a[root].value && (a[root].right == -1))
		{
			rflag = 1;
			a[i].level = a[root].level + 1;
			a[i].x = a[root].x + (4.0f / a[i].level);
			a[i].y = a[root].y - 3;
			a[root].right = a[i].key;
			a[i].parent = root;
			return root;
		}
	}
	return 0;
}
void treecreate()
{
	printf("IN treecreatre Func\n");
	drawnode(0, 2);
	for (int i = 1; i<n; i++)
	{
		drawnode(i, 2);
		drawedge(a[i].parent, i, 2);
	}
}
void insert(int c)
{
	printf("IN insert Func%d\n",c);
	
		printf("%d",n);
	int root;
	a[n].value = atoi(a[n].data);
	a[n].left = -1;
	a[n].right = -1;
	a[n].key = n;
	glColor3f(0.0, 0.0, 0.0);
	if (!n)
	{
		a[n].x = 13.0;
		a[n].y = 25.0;
		a[n].parent = -1;
		drawnode(n, 2);
	}
	else
	{
		root = FindPosition(n);
		if (lflag)
		{
			drawstring(2, 5, a[n].data, c);
			drawstring(3, 5, (char*)"is lesser than it's root, so it goes to the left ", c);
			lflag = 0;
		}
		else if (rflag)
		{
			drawstring(2, 5, a[n].data, c);
			drawstring(3, 5, (char*)"is greater than it's root, so it goes to the right ", c);
			rflag = 0;
		}
		delay(10000);
		drawnode(n, 2);
		drawedge(root, n, 2);
	}
	n++;
	count = 0;
	
}
void display()
{
	printf("\n\n");
	printf("In Display func\n");
	
	char s1[] = "Enter an element and press 'i' to insert that element into the tree.";
	char s2[] = "Enter an element and press 'd' to delete that element from the tree.";
	char s3[] = "ROOT-->LEFT SUBTREE-->RIGHT SUBTREE";
	char s4[] = "LEFT SUBTREE-->ROOT-->RIGHT SUBTREE";
	char s5[] = "LEFT SUBTREE-->RIGHT SUBTREE-->ROOT";
	float l = 22.0, m = 26.0, w = 2.0;
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	if (flag)
	{
		// title();
		flag = 0;
	}
	else
	{
		drawWindow(2, 6, 24, 29);
		menu(GL_RENDER);
		if (n)
		{
			treecreate();
			eflag = 0;
		}
		if (ins)
		{
			drawstring(2, 5, s1, 2);
			drawstring(2, 4, (char*)"Do not enter duplicate elements.", 2);
			c1 = 0;
			ins = 0;
		}
		if (del)
		{
			drawstring(2, 5, s2, 2);
			c2 = 0;
			del = 0;

		}
		if (pre)
		{
			if (!eflag)
			{
				drawstring(2, 5, s3, 2);
				preorder();
				for (i = 0; i<n; i++)
				{
					drawbox(l, m, w, p[i], 3);
					drawnode(p[i], 3);
					delay();
					m = m - w;
				}
			}
			else
				drawstring(2, 4, (char*)"Tree empty,cannot be traversed!", 2);
			c3 = 0;
			pre = 0;
		}
		if (in)
		{
			if (!eflag)
			{
				drawstring(2, 5, s4, 2);
				inorder();
				for (i = 0; i<n; i++)
				{
					drawbox(l, m, w, p[i], 3);
					drawnode(p[i], 3);
					delay();
					m = m - w;
				}
			}
			else
				drawstring(2, 4, (char*)"Tree empty,cannot be traversed!", 2);
			c4 = 0;
			in = 0;
		}
		if (post)
		{
			if (!eflag)
			{
				drawstring(2, 5, s5, 2);
				preorder();
				for (i = 0; i<n; i++)
				{
					drawbox(l, m, w, p[i], 3);
					drawnode(p[i], 3);
					delay();
					m = m - w;
				}
			}
			else
				drawstring(2, 4, (char*)"Tree empty,cannot be traversed!", 2);
			c5 = 0;
			post = 0;
		}
		if (ex)
		{
			exit(0);
		}
	}
	glFlush();
}
void deleteTree()
{
	printf("In deletetree func\n");
	int i, j, m, temp[30], pos, suc;
	a[n].value = atoi(a[n].data);
	j = 0;
	while (a[n].data[j] != '\0')
	{
		a[n].data[j] = '\0';
		j++;
	}
	for (i = 0; i<n; i++)
	if (a[i].value == a[n].value)
		break;
	drawnode(i, 3);
	delay();
	n--;
	if ((a[i].left == -1 && a[i].right == -1) || (a[i].left&&a[i].right == -1))
		a[i].value = -999;
	else
	{
		inorder();
		j = 0;
		while (p[j] != i)
			j++;
		suc = p[j + 1];
		a[i].value = a[suc].value;
		a[suc].value = -999;
	}
	j = 0;
	pos = 0;
	while (j <= n)
	{
		if (a[j].value != -999)
			temp[pos++] = a[j].value;
		j++;
	}
	m = n;
	n = 0;
	while (n<m)
	{
		itoa (temp[n], a[n].data, 10);
		//atoi (a[n].data);
		insert(4);
	}
	j = 0;
	while (a[m].data[j] != '\0')
	{
		a[m].data[j] = '\0';
		j++;
	}
	count = 0;
	glutPostRedisplay();
}
int enterno=25,clearminibox=0;
void displaynum(char string)
{
	if(clearminibox==1)
	{
		//glColor3f(1.0,1.0,1.0);
		//glRectd(25, 24, 29, 26);
	}
	//int inpos=25+(no*2);//, numpar=0;
	printf("%d",enterno);
	
		//drawstring(inpos, 24,n, 2);
	printf("IN displaynum Func\n");
	char *c;
	glColor3fv(color[2]);
	
	glRasterPos2f(enterno, 25);
	//for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string);
	}
		
	enterno++;

	//drawstring(25, float y, char *string, int col)

}



void Keyboard(unsigned char key, int x, int y)
{
	printf("In keyboard func\n");
	enterno += 1;
	switch (key)
	{
		case 'e':
		case 'E':
			execl("./part1.exe", "./part1", NULL);
			break;
	case 'c':glutPostRedisplay();
		break;
	case '0':a[n].data[count++] = '0';
		displaynum('0');
		break;
	case '1':a[n].data[count++] = '1';
		displaynum('1');
		break;
	case '2':a[n].data[count++] = '2';displaynum('2');
		break;
	case '3':a[n].data[count++] = '3';displaynum('3');
		break;
	case '4':a[n].data[count++] = '4';displaynum('4');
		break;
	case '5':a[n].data[count++] = '5';displaynum('5');
		break;
	case '6':a[n].data[count++] = '6';displaynum('6');
		break;
	case '7':a[n].data[count++] = '7';displaynum('7');
		break;
	case '8':a[n].data[count++] = '8';displaynum('8');
		break;
	case '9':a[n].data[count++] = '9';displaynum('9');
		break;
	case 'i':clearminibox=1;
		insert(2);
		glutPostRedisplay();
		enterno=25;
		break;
	case 'd':clearminibox=1;
		deleteTree();
		
		enterno=25;
		break;
	}
}
void pick(int button, int state, int x, int y)
{
	printf("In pick(mouse) func\n");
	GLuint selectBuf[size];
	GLint hits;
	GLint viewport[4];
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;
	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(size, selectBuf);
	(void)glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	/* create 5x5 pixel picking region near cursor location */
	gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 4.0, 4.0, viewport);
	gluOrtho2D(0.0, 30.0, 0.0, 30.0);
	menu(GL_SELECT);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
	hits = glRenderMode(GL_RENDER);
	processHits(hits, selectBuf);
	glutPostRedisplay();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 30, 0, 30);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glColor3f(1,0,0);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1270, 770);
	glutCreateWindow("binary search tree");
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(pick);
	glutFullScreen();
	myinit();
	glutMainLoop();
}
