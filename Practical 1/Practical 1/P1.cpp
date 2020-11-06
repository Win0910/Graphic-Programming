#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "Practical 1"

//Declare variables
int questionNo;
float radius;
float angle;
float x = 0, y = 0, x2, y2;


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == 0x31)
			questionNo = 1;
		else if (wParam == 0x32)
			questionNo = 2;
		else if (wParam == 0x33)
			questionNo = 3;
		else if (wParam == 0x34)
			questionNo = 4;
		else if (wParam == 0x35)
			questionNo = 5;
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

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

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

//Pahang Flag
void pahangFlag() {
	glBegin(GL_QUADS);	//Flag white
	glColor3f(1, 1, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, 0);
	glVertex2f(0.75, 0);
	glVertex2f(0.75, 0.5);
	glEnd();

	glBegin(GL_QUADS);	//Flag black
	glColor3f(0, 0, 0);
	glVertex2f(-0.75, -0.5);
	glVertex2f(-0.75, 0);
	glVertex2f(0.75, 0);
	glVertex2f(0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border top
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glEnd();

	glBegin(GL_LINES);	//Border left
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border right
	glColor3f(0, 0, 1);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border bottom
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, -0.5);
	glVertex2f(0.75, -0.5);
	glEnd();
}

//--------------------------------------------------------------------

//Negeri Sembilan Flag
void negeriSembilanFlag() {
	glBegin(GL_QUADS);	//Flag yellow
	glColor3f(1, 1, 0);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag red
	glColor3f(1, 0, 0);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0, 0);
	glVertex2f(0, 0.5);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag maroon
	glColor3f(0.502, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(-0.75, 0);
	glVertex2f(-0.75, 0.5);
	glEnd();

	glBegin(GL_LINES);	//Border top
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glEnd();

	glBegin(GL_LINES);	//Border left
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border right
	glColor3f(0, 0, 1);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border bottom
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, -0.5);
	glVertex2f(0.75, -0.5);
	glEnd();
}

//--------------------------------------------------------------------

//England Flag
void englandFlag() {
	glBegin(GL_QUADS);	//Flag red
	glColor3f(0.545, 0, 0);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_QUADS);	//Flag white top left
	glColor3f(0.663, 0.663, 0.663);
	glVertex2f(-0.75, 0.5);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(-0.75, 0.1);
	glColor3f(1, 1, 1);
	glVertex2f(-0.1, 0.1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(-0.1, 0.5);
	glEnd();

	glBegin(GL_QUADS);	//Flag white top right
	glColor3f(0.663, 0.663, 0.663);
	glVertex2f(0.75, 0.5);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(0.1, 0.5);
	glColor3f(1, 1, 1);
	glVertex2f(0.1, 0.1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(0.75, 0.1);
	glEnd();

	glBegin(GL_QUADS);	//Flag white bottom left
	glColor3f(0.663, 0.663, 0.663);
	glVertex2f(-0.75, -0.5);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(-0.75, -0.1);
	glColor3f(1, 1, 1);
	glVertex2f(-0.1, -0.1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(-0.1, -0.5);
	glEnd();

	glBegin(GL_QUADS);	//Flag white bottom right
	glColor3f(0.663, 0.663, 0.663);
	glVertex2f(0.75, -0.5);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(0.1, -0.5);
	glColor3f(1, 1, 1);
	glVertex2f(0.1, -0.1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(0.75, -0.1);
	glEnd();

	glBegin(GL_LINES);	//Border top
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glEnd();

	glBegin(GL_LINES);	//Border left
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border right
	glColor3f(0, 0, 1);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border bottom
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, -0.5);
	glVertex2f(0.75, -0.5);
	glEnd();
}

//--------------------------------------------------------------------

//Scotland Flag
void scotlandFlag() {
	glBegin(GL_QUADS);	//Flag white
	glColor3f(1, 1, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag blue top
	glColor3f(0.255, 0.412, 0.882);
	glVertex2f(-0.60, 0.5);
	glVertex2f(0.60, 0.5);
	glVertex2f(0, 0.125);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag blue left
	glColor3f(0.255, 0.412, 0.882);
	glVertex2f(-0.75, 0.375);
	glVertex2f(-0.75, -0.375);
	glVertex2f(-0.125, 0);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag blue right
	glColor3f(0.255, 0.412, 0.882);
	glVertex2f(0.75, 0.375);
	glVertex2f(0.75, -0.375);
	glVertex2f(0.125, 0);
	glEnd();

	glBegin(GL_TRIANGLES);	//Flag blue bottom
	glColor3f(0.255, 0.412, 0.882);
	glVertex2f(-0.60, -0.5);
	glVertex2f(0.60, -0.5);
	glVertex2f(0, -0.125);
	glEnd();

	glBegin(GL_LINES);	//Border top
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glEnd();

	glBegin(GL_LINES);	//Border left
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border right
	glColor3f(0, 0, 1);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glEnd();

	glBegin(GL_LINES);	//Border bottom
	glColor3f(0, 0, 1);
	glVertex2f(-0.75, -0.5);
	glVertex2f(0.75, -0.5);
	glEnd();
}

//--------------------------------------------------------------------

//Draw Circle
void drawCircle(float x, float y, float radius) {
	glBegin(GL_TRIANGLE_FAN);	
	glVertex2f(x, y);			//origin

	for (angle = 0; angle <= 360; angle += 0.01) {
		x2 = x + radius * (cos(angle));		// x2 = x + rcos(a)
		y2 = y + radius * (sin(angle));		// y2 = y + rsin(a)
		glVertex2f(x2, y2);
	}
	glEnd();
}

//--------------------------------------------------------------------

//Smiley Face
void smileyFace() {
	glClearColor(0.902, 0.902, 0.980, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);			//Left Ear
	glColor3f(0.973, 0.973, 1);
	glVertex2f(-0.55, 0.42);
	glVertex2f(-0.22, 0.62);
	glVertex2f(-0.48, 0.8);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.859, 0.439, 0.576);
	glVertex2f(-0.47, 0.48);
	glVertex2f(-0.25, 0.45);
	glVertex2f(-0.445, 0.77);
	glEnd();

	glBegin(GL_TRIANGLES);			
	glColor3f(0, 0, 0);
	glVertex2f(-0.275, 0.42);
	glVertex2f(-0.22, 0.62);
	glVertex2f(-0.48, 0.8);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.863, 0.863, 0.863);
	glVertex2f(-0.55, 0.42);
	glVertex2f(-0.48, 0.8);
	glEnd();

	glBegin(GL_TRIANGLES);			//Right Ear
	glColor3f(0.973, 0.973, 1);
	glVertex2f(0.55, 0.42);
	glVertex2f(0.22, 0.62);
	glVertex2f(0.48, 0.8);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.859, 0.439, 0.576);
	glVertex2f(0.47, 0.48);
	glVertex2f(0.25, 0.45);
	glVertex2f(0.445, 0.77);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex2f(0.275, 0.42);
	glVertex2f(0.22, 0.62);
	glVertex2f(0.48, 0.8);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.863, 0.863, 0.863);
	glVertex2f(0.55, 0.42);
	glVertex2f(0.48, 0.8);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(-0.25, -0.6, 0.15);		//Left Leg
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(0.25, -0.6, 0.15);		//Right Leg
	glEnd();

	glColor3f(0.663, 0.663, 0.663);
	drawCircle(0, 0, 0.7);			//Outline

	glColor3f(1, 1, 1);
	drawCircle(0, -0.15, 0.5);		//Body Part

	glColor3f(1, 1, 1);
	drawCircle(-0.12, 0.3, 0.2);	//Left Eyes Part

	glColor3f(1, 1, 1);
	drawCircle(0.12, 0.3, 0.2);		//Right Eyes Part

	glLineWidth(8);
	glBegin(GL_LINES);				//Left Eyes
	glColor3f(0, 0, 0);
	glVertex2f(-0.20, 0.35);
	glVertex2f(-0.12, 0.35);
	glEnd();

	glLineWidth(8);
	glBegin(GL_LINES);				//Right Eyes
	glColor3f(0, 0, 0);
	glVertex2f(0.20, 0.35);
	glVertex2f(0.12, 0.35);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);		//Nose Part
	glColor3f(1, 1, 1);
	glVertex2f(0, 0.225);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0, 0.37);
	glVertex2f(-0.05, 0.36);
	glVertex2f(-0.08, 0.35);
	glVertex2f(-0.13, 0.30);
	glVertex2f(-0.15, 0.23);
	glVertex2f(-0.15, 0.22);
	glVertex2f(-0.13, 0.15);
	glVertex2f(-0.08, 0.10);
	glVertex2f(-0.05, 0.09);
	glVertex2f(0, 0.08);
	glVertex2f(0.05, 0.09);
	glVertex2f(0.08, 0.10);
	glVertex2f(0.13, 0.15);
	glVertex2f(0.15, 0.22);
	glVertex2f(0.15, 0.23);
	glVertex2f(0.13, 0.30);
	glVertex2f(0.08, 0.35);
	glVertex2f(0.05, 0.36);
	glVertex2f(0, 0.37);
	glVertex2f(0, 0.225);
	glEnd();

	glBegin(GL_POLYGON);			//Nose
	glColor3f(0, 0, 0);
	glVertex2f(0, 0.35);
	glVertex2f(-0.070, 0.33);
	glVertex2f(-0.055, 0.28);
	glVertex2f(0, 0.26);
	glVertex2f(0.055, 0.28);
	glVertex2f(0.070, 0.33);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);				
	glColor3f(0, 0, 0);
	glVertex2f(0, 0.28);
	glVertex2f(0, 0.20);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINE_STRIP);			//Mouth
	glColor3f(0, 0, 0);
	glVertex2f(-0.065, 0.18);
	glVertex2f(0, 0.21);
	glVertex2f(0.065, 0.18);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(-0.47, 0, 0.08);		//Left Hand
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(-0.535, 0.0945, 0.025);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(-0.47, 0.12, 0.025);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(-0.405, 0.0945, 0.025);
	glEnd();
	

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(0.47, 0, 0.08);		//Right Hand
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(0.405, 0.0945, 0.025);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(0.47, 0.12, 0.025);
	glEnd();

	glColor3f(0.412, 0.412, 0.412);
	drawCircle(0.535, 0.0945, 0.025);
	glEnd();
}

//--------------------------------------------------------------------


void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	switch (questionNo)
	{
	case 1:
		pahangFlag();
		break;
	case 2: 
		negeriSembilanFlag();
		break;
	case 3:
		englandFlag();
		break;
	case 4:
		scotlandFlag();
		break;
	case 5:
		smileyFace();
		break;
	default:
		pahangFlag();
	}
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