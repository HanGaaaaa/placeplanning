#pragma once
#include "Vector3.h"
#include "vector"
#include "Space.h"
using namespace std;
class Item
{
public:
	//构造函数，参数为小箱子的长宽高
	Item(float x, float y, float z);
	//箱子长度
	float x_length;
	//箱子宽度
	float y_length;
	//箱子高度
	float z_length;
	//箱子体积
	float m_volume;
	//箱子的放置方式，这里我的标准是，从大箱子的垂直方向向下看，能看到的小箱子的面是由哪两个轴构成的
	enum Put_type
	{
		dir_xy,
		dir_xz,
		dir_yz,
		dir_zy,
		dir_yx,
		dir_zx
	};
	enum Put_type put_Type;
	//小箱子的中心坐标
	Vector3 center_vector;
	//该箱子可以允许的放置方式
	vector<Put_type> put_Types;
	//用于最后输出
	void To_string(int i);
	//判断箱子可以有哪几种放置方式
	void Judge_put_type(Space space);
	//计算箱子的中心坐标
	void Calc_center_positon(Vector3 base_vector);
	//析构函数
	~Item();
};

