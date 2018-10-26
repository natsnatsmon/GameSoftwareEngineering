#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
{
	// Initialize Renderer
	// Renderer는 창마다 하나씩만 만들면 된당!
	m_Renderer = NULL;

	m_Renderer = new Renderer(500, 500);

	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	// Load Texture
	m_TestTexture = m_Renderer->CreatePngTexture("player.png");
	m_ShadowTexture = m_Renderer->CreatePngTexture("shadow.png");
	m_BulletTexture = m_Renderer->CreatePngTexture("bullet.png");

	for (int i = 0; i < MAX_OBJECTS; ++i) {
		m_Objects[i] = NULL;
	}

	// Init Test Obj
	m_Objects[HERO_ID] = new Object();
	m_Objects[HERO_ID]->SetPosition(0.f, 0.f, 0.5f);
	m_Objects[HERO_ID]->SetVel(0.0f, 0.0f);
	m_Objects[HERO_ID]->SetAcc(0.f, 0.f);
	m_Objects[HERO_ID]->SetSize(0.75f, 0.5f);
	m_Objects[HERO_ID]->SetMass(1.f);
	m_Objects[HERO_ID]->SetCoefFric(0.01f);
	m_Objects[HERO_ID]->SetColor(1.f, 1.f, 1.f, 1.f);
	m_Objects[HERO_ID]->SetKind(KIND_HERO);

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

void Shoot(int shootID) {
	if (shootID == SHOOT_NONE) {
		return;
	}

	float amount = 3.f;
	float bvX, bvY; // 총알의 속도

	bvX = 0.f;
	bvY = 0.f;

	switch (shootID) {
	case SHOOT_UP:
		bvX = 0.f;
		bvY = amount;
		break;

	case SHOOT_DOWN:
		bvX = 0.f;
		bvY = -amount;
		break;
	case SHOOT_LEFT:
		bvX = -amount;
		bvY = 0.f;
		break;
	case SHOOT_RIGHT:
		bvX = amount;
		bvY = 0.f;
		break;
	}

	float pX, pY, pZ;
	m_Objects[HERO_ID]->GetPosition(&pX, &pY, &pZ);
	float vX, vY, ;
	m_Objects[HERO_ID]->GetVel(&vX, &vY);
}

int g_seq = 0;
void SceneManager::RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);


	float x, y, z, sizeX, sizeY, r, g, b, a;
	int seqX, seqY;
	seqX = g_seq % 4; // g_seq % 가로 그림 개수
	seqY = 1; // (int)(g_seq / 세로 그림 개수)
	
	g_seq++;
	if (g_seq > 3) // 스프라이트 (가로 * 세로 - 1)
		g_seq = 0;
	m_TestObj->GetPosition(&x, &y, &z);
	m_TestObj->GetSize(&sizeX, &sizeY);
	m_TestObj->GetColor(&r, &g, &b, &a);
	
//	m_Renderer->DrawTextureRect(x * 100.f, y * 100.f, 0, sizeX * 100.f, sizeY * 100.f, r, g, b, a, m_TestTexture);
	m_Renderer->DrawTextureRectHeight(x * 100.f, y * 100.f, 0, sizeX * 100.f, sizeY * 100.f, r, g, b, a, m_ShadowTexture, z);
	m_Renderer->DrawTextureRectSeqXY(x * 100.f, y * 100.f, 0, sizeX * 100.f, sizeY * 100.f, r, g, b, a, m_TestTexture, seqX, seqY, 4, 1);

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