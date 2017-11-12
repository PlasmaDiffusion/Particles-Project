#include "Fireworks.h"

enum State
{
	RISING,
	BURSTING,
	BURSTED,
	DONE
};

Fireworks::Fireworks()
{
	time = 0.0f;
	currentState = RISING;
}

Fireworks::~Fireworks()
{
}



void Fireworks::Update(Particle particles[], float dt)
{
	//First update as normally. The state of the particles will overtime change velocity from the initial velocity.
	for (unsigned int i = 0; i < arraySize; i++)
	{
		//Accelerate
		particles[i].Vel = math.add(particles[i].Vel, particles[i].Accl);

		//Limit velocity
		math.clamp(particles[i].Vel, maxVelocity, true);
		math.clamp(particles[i].Vel, -maxVelocity, false);

		//Move from velocity
		particles[i].Pos = math.add(particles[i].Pos, particles[i].Vel);
	}
	
	//Wait a set amount of time to trigger a state change in the firework. When a state change happens, a velocity change happens

		if (currentState == RISING) //Particles are stuck together and will rise
		{



		if (time < timeUntilStateChange)time += dt;
		else {
			//Change state and time
			currentState = BURSTING;
			time = 0.0f;

			//Every particle gets a random velocity now to burst into a firework
			randomizeVelocity(particles);
			}
		

		}
		else if (currentState == BURSTING) //Particles will begin to burst away from each other into a firework
		{




			if (time < timeUntilStateChange)time += dt;
			else
			{
				currentState = BURSTED;
				setAllVelocities(particles, 0.0f, -1.0f, 0.0f);
			}

		}
		else if (currentState == BURSTED) //A firework formed. Now let the particles fall down a little and be done
		{
			if (time < timeUntilStateChange)time += dt;
			else
			{
				//Finished. Remove particles
				currentState = DONE;
				setAllVelocities(particles, 0.0f, 0.0f, 0.0f);
			}

		}

	
}

void Fireworks::setParameter(float newParameter)
{
	timeUntilStateChange = newParameter;
}

//Choose a random direction of sorts
void Fireworks::randomizeVelocity(Particle particles[])
{
	float biggerRange = maxRange * 2.0f;

	for (unsigned int i = 0; i < arraySize; i++)
	{
		particles[i].Vel.x = ((rand() % (int)(biggerRange * 100)) + (-biggerRange * 100)) / 100;
		particles[i].Vel.y = ((rand() % (int)(biggerRange * 100)) + (-biggerRange * 100)) / 100;
		particles[i].Vel.z = ((rand() % (int)(biggerRange * 100)) + (-biggerRange * 100)) / 100;
	}

}

//Choose a random direction of sorts
void Fireworks::setAllVelocities(Particle particles[], float velX, float velY, float velZ)
{

	for (unsigned int i = 0; i < arraySize; i++)
	{
		particles[i].Vel.x = velX;
		particles[i].Vel.y = velY;
		particles[i].Vel.z = velZ;
	}
}