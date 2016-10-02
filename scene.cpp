#include "scene.h"

void Scene::Render()
{
	camera.moveCamera(xMovement, zMovement);
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
}

Transform Scene::getInitialCarTransform()
{
	return Transform();
}

Transform Scene::getInitialParkingLotTransform()
{
	return Transform();
}

Transform Scene::getInitialTireTransform(TirePosition tirePosition)
{
	switch (tirePosition)
	{
	case Scene::FRONT_RIGHT:
		return Transform(glm::vec3(tireX, tireY, -tireZ), glm::vec3(), tireScale);
		break;
	case Scene::FRONT_LEFT:
		return Transform(glm::vec3(-tireX, tireY, -tireZ), leftTireRotation, tireScale);
		break;
	case Scene::BACK_RIGHT:
		return Transform(glm::vec3(tireX, tireY, tireZ), glm::vec3(), tireScale);
		break;
	case Scene::BACK_LEFT:
		return Transform(glm::vec3(-tireX, tireY, tireZ), leftTireRotation, tireScale);
		break;
	default:
		return Transform();
		break;
	}
}


