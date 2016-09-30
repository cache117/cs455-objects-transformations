#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

struct Transform
{
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) : position(pos), rotation(rot), scale(scale)
	{ }
	virtual ~Transform()
	{ }

	inline glm::mat4 GetModel() const
	{
		glm::mat4 posMatrix = glm::translate(position);
		glm::mat4 rotXMatrix = glm::rotate(rotation.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(rotation.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(rotation.z, glm::vec3(0, 0, 1));
		glm::mat4 scaleMatrix = glm::scale(scale);

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
		return posMatrix * rotMatrix * scaleMatrix;
	}

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

