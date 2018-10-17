#pragma once
class Object
{
private:
	float m_posX;
	float m_posY;
	float m_sizeX, m_sizeY;
	float m_R, m_G, m_B, m_A;
	float m_velX;
	float m_velY;
	float m_accX;
	float m_accY;
	float m_mass;
	float m_coefFric;

public:
	Object();
	~Object();

	void Update(float eTime);


	void GetPosition(float* x, float* y);
	void SetPosition(float x, float y);
	
	void GetVel(float* x, float* y);
	void SetVel(float x, float y);

	void GetAcc(float* x, float* y);
	void SetAcc(float x, float y);

	void GetMass(float* m);
	void SetMass(float m);

	void GetCoefFric(float* m);
	void SetCoefFric(float m);

	void GetSize(float* x, float* y);
	void SetSize(float x, float y);
	 
	void GetColor(float* r, float* g, float* b, float* a);
	void SetColor(float r, float g, float b, float a);

	void ApplyForce(float forceX, float forceY, float eTime);

};

