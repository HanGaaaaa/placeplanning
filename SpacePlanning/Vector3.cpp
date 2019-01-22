#include "stdafx.h"
#include "Vector3.h"

Vector3::Vector3()
{
	position_x = 0;
	position_y = 0;
	position_z = 0;
}


Vector3::Vector3(float x, float y, float z)
{
	position_x = x;
	position_y = y;
	position_z = z;
}

void Vector3::Set(float x, float y, float z) 
{
	position_x = x;
	position_y = y;
	position_z = z;
}


Vector3::~Vector3()
{
}
