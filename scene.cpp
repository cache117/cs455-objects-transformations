#include "scene.h"

void Scene::Render()
{
	camera.moveCamera(xMovement, zMovement);
	camera.rotateCamera(xRotation, yRotation);
	shader.Bind();

	carTexture.Bind(0);
	shader.Update(getInitialCarTransform(), camera);
	carMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getInitialTireTransform(Scene::FRONT_RIGHT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getInitialTireTransform(Scene::FRONT_LEFT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getInitialTireTransform(Scene::BACK_RIGHT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getInitialTireTransform(Scene::BACK_LEFT), camera);
	tireMesh.Draw();

	parkingLotTexture.Bind(0);
	shader.Update(getInitialParkingLotTransform(), camera);
	parkingLotMesh.Draw();
}

Transform Scene::getInitialCarTransform()
{
	return Transform();
}

Transform Scene::getInitialParkingLotTransform()
{
	return Transform(glm::vec3(5.5f, 0, -5.5f), glm::vec3(0, 2.2f, 0));
}

Transform Scene::getInitialTireTransform(TirePosition tirePosition)
{
	switch (tirePosition)
	{
	case Scene::FRONT_RIGHT:
		return Transform(glm::vec3(tireX, tireY, -tireZ), getTireRotation(Scene::FRONT_RIGHT), tireScale);
		break;
	case Scene::FRONT_LEFT:
		return Transform(glm::vec3(-tireX, tireY, -tireZ), getTireRotation(Scene::FRONT_LEFT), tireScale);
		break;
	case Scene::BACK_RIGHT:
		return Transform(glm::vec3(tireX, tireY, tireZ), getTireRotation(Scene::BACK_RIGHT), tireScale);
		break;
	case Scene::BACK_LEFT:
		return Transform(glm::vec3(-tireX, tireY, tireZ), getTireRotation(Scene::BACK_LEFT), tireScale);
		break;
	default:
		return Transform();
		break;
	}
}

glm::vec3 Scene::getTireRotation(TirePosition tirePosition)
{
	switch (tirePosition)
	{
	case Scene::FRONT_RIGHT:
		switch (tireOrientation)
		{
		case Scene::TURNED_RIGHT:
			return rightTireRotation - frontTireTurned;
			break;
		case Scene::TURNED_LEFT:
			return rightTireRotation + frontTireTurned;
			break;
		default:
			return rightTireRotation;
			break;
		}
		break;
	case Scene::FRONT_LEFT:
		switch (tireOrientation)
		{
		case Scene::TURNED_RIGHT:
			return leftTireRotation - frontTireTurned;
			break;
		case Scene::TURNED_LEFT:
			return leftTireRotation + frontTireTurned;
			break;
		default:
			return leftTireRotation;
			break;
		}
		break;
	case Scene::BACK_RIGHT:
		return rightTireRotation;
		break;
	case Scene::BACK_LEFT:
		return leftTireRotation;
		break;
	default:
		return glm::vec3();
		break;
	}
}


