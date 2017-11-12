#pragma once

#include "ParticleSystem.h"

class AttractionParticleSystem : public ParticleSystem
{
public:

    AttractionParticleSystem();
	~AttractionParticleSystem();

	float m_GravityPull = 1;

	void Update(Particle a_arr[], float dt);

	void updateGravityPull(float f);

};