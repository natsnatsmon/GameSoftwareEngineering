#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
{
	// Initialize Renderer
	// Renderer는 창마다 하나씩만 만들면 된당!
	m_Renderer = NULL;
	m_TestObj = NULL;

	m_Renderer = new Renderer(500, 500);

	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	// Load Texture
	m_TestTexture = m_Renderer->CreatePngTexture("texture.png");

	// Init Test Obj
	m_TestObj = new Object();
	m_TestObj->SetMass(2.f);
	m_TestObj->SetPosition(0.f, 0.f);
	m_TestObj->SetVel(0.0f, 0.0f);
	m_TestObj->SetAcc(0.f, 0.f);
	m_TestObj->SetCoefFric(0.01f);
	m_TestObj->SetSize(0.3f, 0.3f);
	m_TestObj->SetColor(.3f, .2f, .7f, 1.f);
}



SceneManager::~SceneManager()
{	
	if (m_Renderer) {	
		delete m_Renderer;	
		m_Renderer = NULL;
	}

	if (m_TestObj) {	
		delete m_TestObj;	
		m_TestObj = NULL;
	}
}

void SceneManager::RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);


	float x, y, sizeX, sizeY, r, g, b, a;
	m_TestObj->GetPosition(&x, &y);
	m_TestObj->GetSize(&sizeX, &sizeY);
	m_TestObj->GetColor(&r, &g, &b, &a);
	
//	m_Renderer->DrawSolidRect(x * 100.f, y * 100.f, 0, sizeX * 100.f, sizeY * 100.f, r, g, b, a);
	m_Renderer->DrawTextureRect(x * 100.f, y * 100.f, 0, sizeX * 100.f, sizeY * 100.f, r, g, b, a, m_TestTexture);

}

void SceneManager::Update(float eTime) {
	m_TestObj->Update(eTime);
	
}

void SceneManager::InputKey(int key) {
	std::cout << key << std::endl;
}

void SceneManager::ApplyForce(float forceX, float forceY, float eTime) {
	m_TestObj->ApplyForce(forceX, forceY, eTime);

}