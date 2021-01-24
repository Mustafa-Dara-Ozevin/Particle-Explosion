#include "Screen.h"
#include "Swarm.h"
#include <SDL.h>
#include <iostream>
#include <vector>

#undef main
using namespace std;
using namespace mustiReis;

int main()
{
	srand(time(NULL));
	Screen screen;
	Swarm swarm;
	
	if (not screen.init())
		cout << "SDL Failed to initialize" << endl;
	
	
	while (true)
	{
		int elapsed = SDL_GetTicks();
		Uint8 red = (1 + cos(elapsed * 0.0006)) * 128;
		Uint8 green = (1 + cos(elapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(elapsed * 0.0003)) * 128;
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < swarm.NPARTICLES; i++)
		{
			Particle particle = pParticles[i];
			int x = particle.m_x * screen.SCREEN_WIDTH / 2;
			int y = particle.m_y * screen.SCREEN_WIDTH / 2 - 200;
			screen.setPixel(x, y, red, green, blue);
		}
		swarm.update(elapsed);
		screen.boxBlur();
		screen.update();
		if (not screen.processEvents())
			break;
	}
	screen.close();
}