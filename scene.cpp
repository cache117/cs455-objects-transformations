#include "scene.h"

void Scene::Render()
{
	camera.moveCamera(xMovement, zMovement);
	shader.Bind();
	transform = Transform();
	//transform.rotation.y = 0.5f;

	carTexture.Bind(0);
	shader.Update(transform, camera);
	carMesh.Draw();

	transform.scale = glm::vec3(0.25f, 0.25f, 0.25f);
	transform.position.y = 0.15f;

	transform.position.x = 0.62f;

	tireTexture.Bind(0);
	shader.Update(transform, camera);
	tireMesh.Draw();

	/*transform.rotation.y = 3.0f;

	transform.position.x = -0.62f;

	tireTexture.Bind(0);
	shader.Update(transform, camera);
	tireMesh.Draw();*/
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
		return Transform();
		break;
	case Scene::FRONT_LEFT:
		return Transform();
		break;
	case Scene::BACK_RIGHT:
		return Transform();
		break;
	case Scene::BACK_LEFT:
		return Transform();
		break;
	default:
		return Transform();
		break;
	}
}
