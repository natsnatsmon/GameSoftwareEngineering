#pragma once
#include "Renderer.h"
#include "Object.h"

// ScnMgr : 모든 렌더링, 오브젝트를 관리한다!
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
