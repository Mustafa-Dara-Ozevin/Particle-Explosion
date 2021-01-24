#pragma once
namespace mustiReis {
	class Particle
	{
	public:
		Particle();
		void update(int interval);
		double m_x;
		double m_y;
		double m_speed;
		double m_direction;
	};
}
