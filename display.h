#pragma once

#include <string>
#include <iostream>
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include "scene.h"

class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	inline bool isClosed()
	{
		return m_isClosed;
	}

	void Update(Scene& scene);

	virtual ~Display();
private:
	void manageKeyPress(Scene& scene, SDL_Keycode key);
	void manageKeyRelease(Scene& scene, SDL_Keycode key);

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
	const float MOVEMENT_AMOUNT = 0.01f;
	const float ROTATION_AMOUNT = 0.05f;
};

