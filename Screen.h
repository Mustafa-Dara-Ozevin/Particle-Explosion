#pragma once
#include <SDL.h>

namespace mustiReis
{
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 1100;
		const static int SCREEN_HEIGHT = 700;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;
		Uint32* m_buffer2;
	public:
		Screen();
		bool init();
		bool processEvents();
		void setPixel(int x, int y,Uint8 red, Uint8 green, Uint8 blue);
		void close();
		void boxBlur();
		void update();

	};
}