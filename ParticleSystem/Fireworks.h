#pragma once

#include "ParticleSystem.h"

class Fireworks : public ParticleSystem
{
public:
	Fireworks();
	~Fireworks();
	void Update(Particle a_arr[], float dt);
	void setParameter(float newParameter);
	//int m_MaxSize; //Arr size
	//Vec m_Pos;
	//float m_MaxDistance = 3; //Max distance particles can spawn from origin
	//float m_GravityPull = 10;
	Vec m_Direction;
	float m_MinDirectionRange;
	float m_MaxDirectionRange;


	void randomizeVelocity(Particle particles[]);
	void setAllVelocities(Particle particles[], float velX, float velY, float velZ);

private:
	//Particle *m_ParticleBuff;
	float timeUntilStateChange;
	float time;
	int currentState;
};