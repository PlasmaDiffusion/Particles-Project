#include "Wrapper.h"
#include "ParticleSystem.h"
#include "Fireworks.h"
#include "AttractionParticleSystem.h"
#include <windows.h>
#include <fstream>
#include <ctime>

ParticleSystem *particleSystem;

enum SystemType
{
	ATTRACTOR,
	DIRECTIONAL
};

void initEmitter(int type)
{
	std::ofstream outFile;
	outFile.open("outFile.txt", std::ios_base::app);


	if (type == 0)
	{
		particleSystem = new ParticleSystem();
		outFile << "Default" << std::endl;

	
	}
	else if (type == 1)
	{
		particleSystem = new Fireworks();
		outFile << "Directional " << std::endl;
	}
	else if (type == 2)
	{
		particleSystem = new AttractionParticleSystem();
		outFile << "Attraction " << std::endl;
	}

	srand((unsigned)time(0));
}

void initParticles(Particle *p, int Size, float range, Vec vel, Vec accl)
{
	particleSystem->maxRange = range;
	for (int i = 0; i < Size; i++)
	{
		p[i].Pos.x = particleSystem->emitterPos.x +(rand()%(int)particleSystem->maxRange) + -particleSystem->maxRange;
		p[i].Pos.y = particleSystem->emitterPos.y + (rand() % (int)particleSystem->maxRange) + -particleSystem->maxRange;
		p[i].Pos.z = particleSystem->emitterPos.z + (rand() % (int)particleSystem->maxRange) + -particleSystem->maxRange;
		
		p[i].Vel.x = vel.x;
		p[i].Vel.y = vel.y;
		p[i].Vel.z = vel.z;

		p[i].Accl.x = accl.x;
		p[i].Accl.y = accl.y;
		p[i].Accl.z = accl.z;

		p[i].Col.x = 1.0f;
		p[i].Col.y = 1.0f;
		p[i].Col.z = 1.0f;

	}
	particleSystem->arraySize = Size;
}

void updateEmitter(Vec position)
{
	particleSystem->emitterPos.x = position.x;
	particleSystem->emitterPos.y = position.y;
	particleSystem->emitterPos.z = position.z;

}

void updateParticles(Particle *p, float dt)
{
	particleSystem->Update(p, dt);

}

//Update a class specific value
void updateParameter(float value, int type) 
{
	particleSystem->setParameter(value);
}


void setVelocityLimit(float newLimit)
{
	particleSystem->maxVelocity = newLimit;
}