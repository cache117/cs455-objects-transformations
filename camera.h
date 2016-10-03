#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <cmath>

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

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0f)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0f)));
	}
private:
	glm::mat4 perspective;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};

