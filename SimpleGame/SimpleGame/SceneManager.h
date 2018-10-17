#pragma once
#include "Renderer.h"
#include "Object.h"

// ScnMgr : ��� ������, ������Ʈ�� �����Ѵ�!
class SceneManager
{
private:
	Renderer *m_Renderer;
	Object *m_TestObj;
	GLuint m_TestTexture = 0;

public:
	SceneManager();
	~SceneManager();

	void RenderScene();

	void Update(float eTime);

	void InputKey(int key);

	void ApplyForce(float forceX, float forceY, float eTime);


};
