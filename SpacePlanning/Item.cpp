#include "stdafx.h"
#include "Item.h"
using namespace std;


Item::Item(float x, float y, float z)
{
	x_length = x;
	y_length = y;
	z_length = z;
	m_volume = x_length * y_length * z_length;
}

void Item::To_string(int i) 
{
	printf("��%d�����ӣ�ʹ�õ�%d�ְڷŷ�ʽ����������Ϊ����%f, %f, %f��\n", i + 1, (int)(put_Type + 1), center_vector.position_x, center_vector.position_y, center_vector.position_z);
}

//���������жϸ�С���ӿ������ļ��ַ��÷�ʽ����Щ����ĳһ���߹������ܵ��·Ų���ȥ
void Item::Judge_put_type(Space space) 
{
	if (x_length <= space.s_x && y_length <= space.s_y && z_length <= space.s_z)
	{
		put_Types.push_back(dir_xy);
	}
	if (x_length <= space.s_x && y_length <= space.s_z && z_length <= space.s_y)
	{
		put_Types.push_back(dir_xz);
	}
	if (x_length <= space.s_y && y_length <= space.s_x && z_length <= space.s_z)
	{
		put_Types.push_back(dir_yx);
	}
	if (x_length <= space.s_z && y_length <= space.s_x && z_length <= space.s_y)
	{
		put_Types.push_back(dir_yz);
	}
	if (x_length <= space.s_y && y_length <= space.s_z && z_length <= space.s_x)
	{
		put_Types.push_back(dir_zx);
	}
	if (x_length <= space.s_z && y_length <= space.s_y && z_length <= space.s_x)
	{
		put_Types.push_back(dir_zy);
	}
}

//�������������˼���ǣ�С�����������Ŀռ���������С���ӵ����꣬���ݲ�ͬ�ķ��÷�ʽ�ֱ����
void Item::Calc_center_positon(Vector3 base_vector) 
{
	switch (put_Type)
	{
		case dir_xy:
			center_vector.position_x = base_vector.position_x + x_length / 2;
			center_vector.position_y = base_vector.position_y + y_length / 2;
			center_vector.position_z = base_vector.position_z + z_length / 2;
			break;
		case dir_xz:
			center_vector.position_x = base_vector.position_x + x_length / 2;
			center_vector.position_y = base_vector.position_y + z_length / 2;
			center_vector.position_z = base_vector.position_z + y_length / 2;
			break;
		case dir_yx:
			center_vector.position_x = base_vector.position_x + y_length / 2;
			center_vector.position_y = base_vector.position_y + x_length / 2;
			center_vector.position_z = base_vector.position_z + z_length / 2;
			break;
		case dir_yz:
			center_vector.position_x = base_vector.position_x + y_length / 2;
			center_vector.position_y = base_vector.position_y + z_length / 2;
			center_vector.position_z = base_vector.position_z + x_length / 2;
			break;
		case dir_zx:
			center_vector.position_x = base_vector.position_x + z_length / 2;
			center_vector.position_y = base_vector.position_y + x_length / 2;
			center_vector.position_z = base_vector.position_z + y_length / 2;
			break;
		case dir_zy:
			center_vector.position_x = base_vector.position_x + z_length / 2;
			center_vector.position_y = base_vector.position_y + y_length / 2;
			center_vector.position_z = base_vector.position_z + x_length / 2;
			break;
		default:
			break;
	}
}



Item::~Item()
{
}
