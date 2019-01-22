#include "stdafx.h"
#include "Space.h"


Space::Space()
{
	s_x = 0;
	s_y = 0;
	s_z = 0;
	s_volume = s_x * s_y * s_z;
}

Space::Space(float x, float y, float z)
{
	s_x = x;
	s_y = y;
	s_z = z;
	s_volume = s_x * s_y * s_z;
}

void Space::Set_positon(Vector3 position) 
{
	m_bottom_right_positon.position_x = position.position_x;
	m_bottom_right_positon.position_y = position.position_y;
	m_bottom_right_positon.position_z = position.position_z;
}

Space::~Space()
{
}
