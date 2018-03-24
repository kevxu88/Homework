// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	float theta = degrees * pi / 180;
	mat3 m1 = glm::mat3(axis.x * axis.x, axis.x * axis.y, axis.x * axis.z,
		axis.x * axis.y, axis.y * axis.y, axis.y * axis.z,
		axis.x * axis.z, axis.y * axis.z, axis.z * axis.z);
	mat3 m2 = glm::mat3(0, axis.z, -axis.y, -axis.z, 0,
		axis.x, axis.y, -axis.x, 0);
  // You will change this return call
  return (cos(theta) * glm::mat3(1.0f)) + ((1 - cos(theta)) * m1) + sin(theta) * m2;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	vec3 normalize = glm::normalize(up);
	eye = Transform::rotate(degrees, normalize) * eye;
	up = Transform::rotate(degrees, normalize) * up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	vec3 normalize = glm::normalize(glm::cross(eye, up));
	eye = Transform::rotate(degrees, normalize) * eye;
	up = Transform::rotate(degrees, normalize) * up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
	vec3 w = glm::normalize(eye);
	vec3 u = glm::normalize(glm::cross(up, w));
	vec3 v = glm::normalize(glm::cross(w, u));
	mat4 ratation = glm::mat4(u.x, v.x, w.x, 0, u.y, v.y, w.y, 0, u.z, v.z, w.z, 0, 0, 0, 0, 1);
	mat4 traslation = glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -eye.x, -eye.y, -eye.z, 1);
	return ratation * traslation;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
