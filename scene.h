#pragma once

#include <GL\glew.h>
#include <SDL2\SDL.h>
#include <iostream>
#include <cmath>
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
		camera(glm::vec3(0, 0.5f, -3.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 500.0f),
		carMesh("./res/car.obj"),
		carTexture("./res/car.bmp"),
		tireTexture("./res/tire.bmp"),
		tireMesh("./res/tire.obj"),
		parkingLotMesh("./res/ParkingLot.obj"),
		parkingLotTexture("./res/ParkingLot.bmp"),
		humanoidMesh("./res/monster.obj"),
		brickTexture("./res/bricks.jpg"),
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
	Shader shader;

	Camera camera;
	float xMovement;
	float zMovement;
	float xRotation;
	float yRotation;

	Mesh tireMesh;
	Mesh parkingLotMesh;
	Mesh carMesh;
	Mesh humanoidMesh;

	Texture tireTexture;
	Texture parkingLotTexture;
	Texture carTexture;
	Texture brickTexture;

	Transform getCarTransform();

	Transform getParkingLotTransform();
	const glm::vec3 parkingLotPosition = glm::vec3(4.2f, 0, -4.8f);
	const glm::vec3 parkingLotRotation = glm::vec3(0, 2.1f, 0);
	const glm::vec3 parkingLotScale = glm::vec3(0.8f);

	Transform getTireTransform(TirePosition tirePosition);
	inline glm::vec3 getTireRotation(TirePosition tirePosition);
	const glm::vec3 tireScale = glm::vec3(0.25f);
	const glm::vec3 leftTireRotation = glm::vec3(0, (float)M_PI, 0);
	const glm::vec3 rightTireRotation = glm::vec3(0.0f);
	const float frontTireZ = -0.53f;
	const float backTireZ = 0.47f;
	const float tireX = 0.35f;
	const float tireY = 0.15f;
	TireOrientation tireOrientation;
	const float frontTireTurningAngle = 0.75f;
	const glm::vec3 frontTireTurned = glm::vec3(0, 0.75f, 0);

	Transform getHumanoidTransform();
};

