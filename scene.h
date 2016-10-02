#pragma once

#include <GL\glew.h>
#include <SDL2\SDL.h>
#include <iostream>
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

class Scene
{
public:
	Scene() : shader("./res/basicShader"),
		tireMesh("./res/tire.obj"),
		/*parkingLotMesh("./res/ParkingLot.obj"),*/
		carMesh("./res/car.obj"),
		tireTexture("./res/tire.bmp"),
		/*parkingLotTexture("./res/ParkingLot.bmp"),*/
		carTexture("./res/car.bmp"),
		camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 500.0f),
		transform(),
		xMovement(0),
		zMovement(0)
	{ }

	virtual ~Scene()
	{ }
	void Render();
	
	inline void setXMovement(float movement)
	{
		xMovement = movement;
	}

	inline void setZMovement(float movement)
	{
		zMovement = movement;
	}

	inline float getXMovement()
	{
		return xMovement;
	}

	inline float getZMovement()
	{
		return zMovement;
	}

	inline void setXRotation(float rotation)
	{
		xRotation = rotation;
	}

	inline void setYRotation(float rotation)
	{
		yRotation = rotation;
	}

	inline float getXRotation()
	{
		return xRotation;
	}

	inline float getYRotation()
	{
		return yRotation;
	}
private:
	Camera camera;
	Shader shader;
	Transform transform;

	Mesh tireMesh;
	Mesh parkingLotMesh;
	Mesh carMesh;

	Texture tireTexture;
	Texture parkingLotTexture;
	Texture carTexture;

	enum TirePosition
	{
		FRONT_RIGHT,
		FRONT_LEFT,
		BACK_RIGHT,
		BACK_LEFT
	};

	Transform getInitialCarTransform();
	Transform getInitialParkingLotTransform();
	Transform getInitialTireTransform(TirePosition tirePosition);

	float xMovement;
	float zMovement;
	float xRotation;
	float yRotation;
};

