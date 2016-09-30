#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int charc, char** argv)
{
	Display display(WIDTH, HEIGHT, "Object Transformations");

	//Mesh crayonMesh("./res/crayonBox.obj");
	Mesh tireMesh("./res/tire.obj");
	//Mesh parkingLotMesh("./res/ParkingLot.obj");
	Mesh carMesh("./res/car.obj");
	Shader shader("./res/basicShader");
	//Texture crayonBoxTexture("./res/CrayonBox2.png");
	Texture tireTexture("./res/tire.bmp");
	Texture parkingLotTexture("./res/ParkingLot.bmp");
	Texture carTexture("./res/car.bmp");
	Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 500.0f);
	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed())
	{		
		transform = Transform();

		transform.rotation.y = counter;

		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		carTexture.Bind(0);
		shader.Update(transform, camera);
		carMesh.Draw();

		transform.scale = glm::vec3(0.25f, 0.25f, 0.25f);
		transform.position.x += 0.62f;
		transform.position.y += 0.15f;

		//shader.Bind();
		tireTexture.Bind(0);
		shader.Update(transform, camera);
		tireMesh.Draw();

		display.Update();
		counter += 0.001f;
	}
	return 0;
}