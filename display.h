#pragma once

#include <string>
#include <iostream>
#include <SDL2\SDL.h>
#include <GL/glew.h>
class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	inline bool isClosed()
	{
		return m_isClosed;
	}

	void Update();

	virtual ~Display();
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {}
	void initJoySticks();

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

