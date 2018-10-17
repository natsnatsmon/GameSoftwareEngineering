/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/
#include "stdafx.h"
#include <iostream>
#include <Windows.h>

// ��������� 64/32��Ʈ�� ��������� lib(���̺귯��)������ �� Ȯ�����ֵ�������
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "SceneManager.h"

using namespace std;

SceneManager *g_scgMgr = NULL;

DWORD g_prevTime = 0;
float rect_x = 0.f, rect_y = 0.f;
float moveDistance = 1.f;

BOOL g_keyW = false;
BOOL g_keyA = false;
BOOL g_keyS = false;
BOOL g_keyD = false;

void RenderScene(void)
{
	// Calc Elapsed Time
	if (g_prevTime == 0) {
		g_prevTime = timeGetTime();
		return;
	}
	DWORD currTime = timeGetTime(); // curr time in milli
	DWORD elapsedTime = currTime - g_prevTime;
	g_prevTime = currTime;
	float eTime = (float)elapsedTime / 1000.f;

	//cout << "elapsedTime : " << eTime << endl;
	cout << "W :" << g_keyW << ", A :" << g_keyA << ", S :" << g_keyS << ", D :" << g_keyD << endl;

	float forceX = 0.f;
	float forceY = 0.f;
	if (g_keyA) { forceX = -1.f; }
	else if (g_keyW) { forceY = 1.f; }
	else if (g_keyS) { forceY = -1.f; }
	else if (g_keyD) { forceX = 1.f; }
	g_scgMgr->ApplyForce(forceX, forceY, eTime);

	// update
	g_scgMgr->Update(eTime);
	g_scgMgr->RenderScene();

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

// Ű���尡 press�Ǿ��� �� �߻��ϴ� �̺�Ʈ
void KeyDownInput(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a' :
		g_keyA = TRUE;
		break;
	case 's':
		g_keyS = TRUE;
		break;
	case 'd':
		g_keyD = TRUE;
		break;
	case 'w' :
		g_keyW = TRUE;
		break;
	}
}

// Ű���尡 �������� �� �߻��ϴ� �̺�Ʈ
void KeyUpInput(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		g_keyA = FALSE;
		break;
	case 's':
		g_keyS = FALSE;
		break;
	case 'd':
		g_keyD = FALSE;
		break;
	case 'w':
		g_keyW = FALSE;
		break;
	}
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}


	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	// init SceneManager
	g_scgMgr = new SceneManager;

	glutMainLoop();


    return 0;
}
