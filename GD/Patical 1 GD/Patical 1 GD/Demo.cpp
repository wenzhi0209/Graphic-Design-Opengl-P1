
#include <Windows.h>//import window header
#include <gl/GL.h>//import open gl header
#include <math.h>  

#pragma comment (lib, "OpenGL32.lib")  //setting library

#define WINDOW_TITLE "Practical 1 Exercise" //setting window name
int qNo = 0;

#define MAX_CHAR        128

void drawString(const char* str) {
	static int isFirstCall = 1;
	static GLuint lists;
	if (isFirstCall) { 
		isFirstCall = 0;

		lists = glGenLists(MAX_CHAR);

		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}	
	for (; *str != '\0'; ++str)
		glCallList(lists + *str);
}

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) //window listener check wheater receive any message
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);// vk = virtual key can right click go to definition go all the key
		else if (wParam == 'A')
		{
			//change something
			qNo = 0;
		}
		else if (wParam == 'D')
		{
			//change something
			qNo = 1;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;//transparency 8bit/1 byte
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;// z buffer
	pfd.cStencilBits = 0;//shadow 

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

//POLYGON
const int n = 360;
const double pi = 3.142;

//triangle fan
float x1 = 0, y3 = 0, x2 = 0, y2 = 0;
float angle = 0;
float radius = 0.5;



void selfTest()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.5);
	

	//Q6 ANPANMAN

	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.5, -0.8);
	drawString("ENTER 'A' or 'D' change between questions 1-5 and qustion 6");

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.6, -0.73);
	glColor3f(0.0, 1, 0.0);
	glVertex2f(-0.55, -0.78);
	glColor3f(0.0, 0, 1);
	glVertex2f(-0.6, -0.83);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.96, 0.62, 0.42);
	for (int i = 0; i < n; i++)
	{
		glVertex2f( 0.45 * cos(2 * pi / n * i),  0.45 * sin(2 * pi / n * i));
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(0.45 * cos(2*pi / n * i), 0.45 * sin(2*pi / n * i));
	}
	glEnd();

	//eye
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(-0.15 + 0.08 * cos(pi / n * i), 0.25 + 0.1 * sin(pi / n * i));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2f(-0.12, 0.2);//origin
	for (angle = 0; angle <= 360; angle += 0.2)
	{
		x2 = -0.15 + 0.04 * (cos(angle));//0.1=radius/size
		y2 = 0.2 + 0.05 * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(0.15 + 0.08 * cos(pi / n * i), 0.25 + 0.1 * sin(pi / n * i));
	}
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2f(0.12, 0.2);//origin
	for (angle = 0; angle <= 360; angle += 0.2)
	{
		x2 = 0.15 + 0.04 * (cos(angle));//0.1=radius/size
		y2 = 0.2 + 0.05 * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();

	

	//face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.4, 0);
	glVertex2f(-0.22, 0);//origin
	for (angle = 0; angle <= 360; angle += 0.2)
	{
		x2 = -0.22 + 0.12 * (cos(angle));//0.1=radius/size
		y2 = 0 + 0.12 * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();

	glPointSize(12.0);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.18, 0.02);
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.4, 0);
	glVertex2f(0.22, 0);//origin
	for (angle = 0; angle <= 360; angle += 0.2)
	{
		x2 = 0.22 + 0.12 * (cos(angle));//0.1=radius/size
		y2 = 0 + 0.12 * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();

	glPointSize(12.0);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2f(0.26, 0.02);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(0.22+-0.12 * sin(pi / n * i),0.12 * cos( pi / n * i) );
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(-0.22 + 0.12 * sin(pi / n * i), 0.12 * cos(pi / n * i));
	}
	glEnd();

	//nose
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0);//origin
	for (angle = 0; angle <= 360; angle += 0.2)
	{
		x2 = 0 + 0.1 * (cos(angle));//0.1=radius/size
		y2 = 0 + 0.1 * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();

	glPointSize(12.0);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2f(0.04, 0.02);
	glEnd();

	
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(0.1 * sin(2 * pi / n * i), 0.1 * cos(2 * pi / n * i));
	}
	glEnd();

	//mount

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++)
	{
		glVertex2f( 0.15 * cos(pi / n * i), -0.12 + -0.12 * sin(pi / n * i));
	}
	glEnd();
	



}
void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	switch (qNo)
	{
	case 1:
		selfTest();
		break;

	default:
		//pq Q1
		glClearColor(1, 0.5, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(-0.5,-0.5 );
		drawString("ENTER 'A' or 'D' change between questions 1-5 and qustion 6");

		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.6, -0.42);
		glColor3f(0, 1, 0.0);
		glVertex2f(-0.55, -0.47);
		glColor3f(0, 0.0, 1);
		glVertex2f(-0.6, -0.52);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(-0.9, 0.4);
		glVertex2f(-0.9, 0.55);
		glVertex2f(-0.4, 0.55);
		glVertex2f(-0.4, 0.4);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(-0.9, 0.55);
		glVertex2f(-0.9, 0.7);
		glVertex2f(-0.4, 0.7);
		glVertex2f(-0.4, 0.55);
		glEnd();
		//Q1

		//Q2
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f(-0.25, 0.4);
		glVertex2f(-0.25, 0.7);
		glVertex2f(0.25, 0.7);
		glVertex2f(0.25, 0.4);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex2f(-0.25, 0.55);
		glVertex2f(-0.25, 0.7);
		glVertex2f(0, 0.55);

		glColor3f(1, 0, 0);
		glVertex2f(-0.25, 0.7);
		glVertex2f(0, 0.7);
		glVertex2f(0, 0.55);
		glEnd();

		//Q2

		//Q3
		glBegin(GL_QUADS);
		glColor3f(0.776, 0.145, 0);
		glVertex2f(0.4, 0.4);
		glVertex2f(0.4, 0.7);
		glVertex2f(0.9, 0.7);
		glVertex2f(0.9, 0.4);

		glBegin(GL_QUADS);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.4, 0.58);
		glColor3f(0.75, 0.75, 0.75);
		glVertex2f(0.4, 0.7);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.62, 0.7);
		glColor3f(1, 1, 1);
		glVertex2f(0.62, 0.58);

		glColor3f(1, 1, 1);
		glVertex2f(0.68, 0.58);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.68, 0.7);
		glColor3f(0.75, 0.75, 0.75);
		glVertex2f(0.9, 0.7);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.9, 0.58);

		glColor3f(0.75, 0.75, 0.75);
		glVertex2f(0.4, 0.4);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.4, 0.52);
		glColor3f(1, 1, 1);
		glVertex2f(0.62, 0.52);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.62, 0.4);

		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.68, 0.4);
		glColor3f(1, 1, 1);
		glVertex2f(0.68, 0.52);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(0.9, 0.52);
		glColor3f(0.75, 0.75, 0.75);
		glVertex2f(0.9, 0.4);

		glEnd();
		//Q3

		//Q4
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(-0.9, -0.1);
		glVertex2f(-0.9, 0.2);
		glVertex2f(-0.4, 0.2);
		glVertex2f(-0.4, -0.1);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0.455, 0.651);
		glVertex2f(-0.7, 0.05);
		glVertex2f(-0.9, -0.06);
		glVertex2f(-0.9, 0.16);

		glVertex2f(-0.86, 0.2);
		glVertex2f(-0.65, 0.08);
		glVertex2f(-0.43, 0.2);

		glVertex2f(-0.6, 0.05);
		glVertex2f(-0.4, -0.06);
		glVertex2f(-0.4, 0.16);

		glVertex2f(-0.86, -0.1);
		glVertex2f(-0.65, 0.02);
		glVertex2f(-0.43, -0.1);

		glEnd();
		//Q4

		//Q4
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(-0.25, -0.1);
		glVertex2f(-0.25, 0.2);
		glVertex2f(0.25, 0.2);
		glVertex2f(0.25, -0.1);
		glEnd();



		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		for (int i = 0; i < n; i++)
		{
			glVertex2f(0.075 * cos(2 * pi / n * i), 0.05 + 0.075 * sin(2 * pi / n * i));
		}
		glEnd();
		
		break;
	}
	

	

	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}

//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------