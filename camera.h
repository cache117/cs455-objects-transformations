#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <math.h>

class Camera
{
public:
	Camera()
	{ }
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	inline glm::mat4 GetView() const
	{
		return glm::lookAt(m_position, m_position + m_forward, m_up);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return m_perspective * GetView();
	}

	virtual ~Camera()
	{ }

	inline void moveCamera(float x, float z)
	{
		m_position.x += x;
		m_position.z += z;
	}

	inline void rotateCamera(float x, float y)
	{
		glm::mat4 yRotation = glm::rotate(y, glm::vec3(0, 1, 0));
		glm::mat4 xRotation = glm::rotate(x, glm::vec3(1, 0, 0));
		/*glm::mat4 rotationY = glm::mat4(glm::vec4(cos(y), 0, sin(y), 0), glm::vec4(0, 1, 0, 0), glm::vec4(-sin(y), 0, cos(y), 0), glm::vec4(0, 0, 0, 1));
		glm::mat4 rotationX = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, cos(x), -sin(x), 0), glm::vec4(0, sin(x), cos(x), 0), glm::vec4(0, 0, 0, 1));
		glm::mat4 rotation = rotationY * rotationX;*/
	}
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};

