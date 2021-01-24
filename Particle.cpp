#include "Particle.h"
#include <stdlib.h>
#include <cmath>
#include <SDL_stdinc.h>
namespace mustiReis {
	Particle::Particle():m_x(1),m_y(1) {
		m_direction = (2 * M_PI * rand())/RAND_MAX;
		m_speed = (0.02 * rand())/RAND_MAX;
		m_speed *= (m_speed*m_speed)/(m_speed/2);
	}
	void Particle::update(int interval) {
		m_direction += interval * 0.0004;
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);
		m_x += xspeed * interval;
		m_y += yspeed * interval;
		
	}

}