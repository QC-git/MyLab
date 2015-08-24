
#include "xTest.h"

#include <Windows.h>
//#include <gl/GLU.h>

#include "GLUT/glut.h"
#include <math.h>

namespace space_test_graph {

	void renderScene(void) {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
		glEnd();
		glFlush();
	}

	void test1()
	{

		int argc = 1;
		char* argv = "test";	

		glutInit(&argc, &argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
		glutInitWindowPosition(500, 400);
		glutInitWindowSize(720, 576);
		glutCreateWindow("test");

		glutDisplayFunc(renderScene);

		glutMainLoop();

	}


	const GLfloat factor = 0.1f;//让正弦函数比例放大  
	void myDisplay(void)  
	{  
		GLfloat x;  
		glClear(GL_COLOR_BUFFER_BIT);  
		//画x,y坐标  
		glEnable(GL_LINE_STIPPLE);//启动虚线  
		glLineStipple(2, 0x0F0F);//设置虚线样式  
		glLineWidth(2.0f);    //设置线宽  
		glBegin(GL_LINES);  
		glVertex2f(-1.0f, 0.0f);  
		glVertex2f(1.0f, 0.0f);  
		glVertex2f(0.0f, -1.0f);  
		glVertex2f(0.0f, 1.0f);  
		glEnd();  
		//画正弦函数曲线  
		glDisable(GL_LINE_STIPPLE);//禁止虚线  
		glBegin(GL_LINE_STRIP);  
		for (x=-1.0f/factor;x<1.0f/factor;x+=0.01f)  
		{  
			glVertex2f(x*factor, sin(x)*factor);  
		}  
		glEnd();  
		glFlush();  
	}  

	void test2()
	{
		int argc = 1;
		char* argv = "test";

		glutInit(&argc, &argv);  
		glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);  
		glutInitWindowPosition(100, 100);  
		glutInitWindowSize(400, 400);  
		glutCreateWindow("test");  

		glutDisplayFunc(&myDisplay);  

		glutMainLoop();//进行消息循环  
	}

}

void test_graph()
{
	//space_test_graph::test1();
	space_test_graph::test2();

	while (true)
	{
		Sleep(1);
	}
}