#include "scene.h"

void Scene::Render()
{
	camera.moveCamera(xMovement, zMovement);
	camera.pitch(xRotation);
	camera.yaw(yRotation);
	shader.Bind();

	carTexture.Bind(0);
	shader.Update(getCarTransform(), camera);
	carMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getTireTransform(Scene::FRONT_RIGHT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getTireTransform(Scene::FRONT_LEFT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getTireTransform(Scene::BACK_RIGHT), camera);
	tireMesh.Draw();

	tireTexture.Bind(0);
	shader.Update(getTireTransform(Scene::BACK_LEFT), camera);
	tireMesh.Draw();
#ifdef LOAD_LARGE 
	parkingLotTexture.Bind(0);
	shader.Update(getParkingLotTransform(), camera);
	parkingLotMesh.Draw();

	brickTexture.Bind(0);
	shader.Update(getHumanoidTransform(), camera);
	humanoidMesh.Draw();
#endif // LOAD_ALL
}

Transform Scene::getCarTransform()
{
	return Transform();
}

Transform Scene::getParkingLotTransform()
{
	return Transform(parkingLotPosition, parkingLotRotation, parkingLotScale);
}

Transform Scene::getTireTransform(TirePosition tirePosition)
{
	switch (tirePosition)
	{
	case Scene::FRONT_RIGHT:
		return Transform(glm::vec3(tireX, tireY, frontTireZ), getTireRotation(Scene::FRONT_RIGHT), tireScale);
		break;
	case Scene::FRONT_LEFT:
		return Transform(glm::vec3(-tireX, tireY, frontTireZ), getTireRotation(Scene::FRONT_LEFT), tireScale);
		break;
	case Scene::BACK_RIGHT:
		return Transform(glm::vec3(tireX, tireY, backTireZ), getTireRotation(Scene::BACK_RIGHT), tireScale);
		break;
	case Scene::BACK_LEFT:
		return Transform(glm::vec3(-tireX, tireY, backTireZ), getTireRotation(Scene::BACK_LEFT), tireScale);
		break;
	default:
		return Transform();
		break;
	}
}

Transform Scene::getHumanoidTransform()
{
	return Transform(glm::vec3(0, 0.67f, 0.05f), glm::vec3(0, M_PI, 0), glm::vec3(0.05f));
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
	case Scene::BACK_LEFT:
		return leftTireRotation;
		break;
	default:
		return rightTireRotation;
		break;
	}
}


