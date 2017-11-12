#include "AttractionParticleSystem.h"

#include <fstream>

AttractionParticleSystem::AttractionParticleSystem()
{
	m_GravityPull = 1.0f;

}

AttractionParticleSystem::~AttractionParticleSystem()
{
}

void AttractionParticleSystem::Update(Particle a_arr[], float dt)
{
	/*
	std::ofstream outFile;
	outFile.open("outFile.txt", std::ios_base::app);
	outFile << dt << "In function" << std::endl;
	*/
	for (unsigned int i = 0; i < arraySize; i++)
	{
		a_arr[i].Vel = math.subtract(a_arr[i].Vel, math.multiply(math.multiply(math.Normalize(math.subtract(a_arr[i].Pos, emitterPos)), m_GravityPull), dt));
		a_arr[i].Pos = math.add(a_arr[i].Pos, a_arr[i].Vel);

		//Mess with colours
		a_arr[i].Col = math.divide(a_arr[i].Pos, m_GravityPull);
	}
}

void AttractionParticleSystem::updateGravityPull(float f)
{
}
