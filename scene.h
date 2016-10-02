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
		parkingLotMesh("./res/ParkingLot.obj"),
		carMesh("./res/car.obj"),
		tireTexture("./res/tire.bmp"),
		parkingLotTexture("./res/ParkingLot.bmp"),
		carTexture("./res/car.bmp"),
		camera(glm::vec3(0, 0.5f, -3.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 500.0f),
		transform(),
		xMovement(0),
		zMovement(0),
		xRotation(0),
		yRotation(0),
		tireOrientation(FORWARD)
	{ }

	virtual ~Scene()
	{ }
	void Render();

	enum TirePosition
	{
		FRONT_RIGHT,
		FRONT_LEFT,
		BACK_RIGHT,
		BACK_LEFT
	};

	enum TireOrientation
	{
		TURNED_RIGHT,
		TURNED_LEFT,
		FORWARD
	};
	
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

	inline void setTireOrientation(TireOrientation orientation)
	{
		tireOrientation = orientation;
	}

	inline TireOrientation getTireOrientation()
	{
		return tireOrientation;
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

	Transform getInitialCarTransform();
	const float carY = 0.3f;

	Transform getInitialParkingLotTransform();
	Transform getInitialTireTransform(TirePosition tirePosition);
	inline glm::vec3 getTireRotation(TirePosition tirePosition);

	const glm::vec3 tireScale = glm::vec3(0.25f, 0.25f, 0.25f);
	const glm::vec3 leftTireRotation = glm::vec3(0, 3.0f, 0);
	const glm::vec3 rightTireRotation = glm::vec3(0.0f);
	const float frontTireTurningAngle = 0.75f;
	const glm::vec3 frontTireTurned = glm::vec3(0, 0.75f, 0);
	const float tireZ = 0.5f;
	const float tireX = 0.37f;
	const float tireY = 0.15f;


	float xMovement;
	float zMovement;
	float xRotation;
	float yRotation;

	TireOrientation tireOrientation;
};

