#pragma once
#include "Vector3.h"
class Space
{
public:
	//分割得到的空间的长度
	float s_x;
	//分割得到的空间的宽度
	float s_y;
	//分割得到的空间的高度
	float s_z;
	//分割得到的空间的体积
	float s_volume;
	//空间的坐标，这里我的标准是空间底面的夹角坐标
	Vector3 m_bottom_right_positon;
	//无参构造
	Space();
	//有参构造，参数为长宽高
	Space(float x, float y, float z);
	//设定该空间的坐标位置
	void Set_positon(Vector3 position);
	~Space();
};

