#pragma once
class Vector3
{
public:
	float position_x;
	float position_y;
	float position_z; 
	Vector3();
	Vector3(float x, float y, float z);
	void Set(float x, float y, float z);
	~Vector3();
};

