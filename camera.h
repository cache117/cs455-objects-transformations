#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <cmath>

#define LOCKED_Y_MOVEMENT
#define USE_CUSTOM_MATRICES

class Camera
{
public:
	Camera()
	{ }
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->perspective = glm::perspective(fov, aspect, zNear, zFar);
		this->position = pos;
		this->forward = glm::vec3(0, 0, 1);
		this->up = glm::vec3(0, 1, 0);
	}

	inline glm::mat4 GetView() const
	{
		/*glm::mat4 translateToOrigin = glm::mat4(1.0f);
		translateToOrigin[3][0] = -position.x;
		translateToOrigin[3][1] = -position.y;
		translateToOrigin[3][2] = -position.z;

		glm::vec3 n = glm::normalize(position - forward);
		glm::vec3 u = glm::normalize(glm::cross(up, n));
		glm::vec3 v = glm::normalize(glm::cross(n, u));

		glm::mat4 changeOfBasis = glm::mat4(1.0f);
		changeOfBasis[0][0] = u.x;
		changeOfBasis[1][0] = u.y;
		changeOfBasis[2][0] = u.z;
		changeOfBasis[0][1] = v.x;
		changeOfBasis[1][1] = v.y;
		changeOfBasis[2][1] = v.z;
		changeOfBasis[0][2] = n.x;
		changeOfBasis[1][2] = n.y;
		changeOfBasis[2][2] = n.z;
		
		return changeOfBasis * translateToOrigin;*/
		return glm::lookAt(position, position + forward, up);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return perspective * GetView();
	}

	virtual ~Camera()
	{ }

	inline void moveCamera(float x, float z)
	{
		position += forward * z;
		position += glm::cross(up, forward) * x;
#ifdef LOCKED_Y_MOVEMENT
		position.y = 0.5f;
#endif // !LOCKED_Y_MOVEMENT
	}

	inline void pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));
		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0f)));
		up = glm::normalize(glm::cross(forward, right));
	}

	inline void yaw(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

#ifndef USE_CUSTOM_MATRICES
		glm::mat4 rotation = glm::rotate(angle, UP);
#else
		glm::mat4 rotation = glm::mat4(1.0f);
		rotation[0][0] = cos(angle);
		rotation[0][2] = -sin(angle);
		rotation[2][0] = sin(angle);
		rotation[2][2] = cos(angle);
#endif // !USE_CUSTOM_MATRICES

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0f)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0f)));
	}
private:
	glm::mat4 perspective;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};

