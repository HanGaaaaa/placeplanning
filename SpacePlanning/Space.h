#pragma once
#include "Vector3.h"
class Space
{
public:
	//�ָ�õ��Ŀռ�ĳ���
	float s_x;
	//�ָ�õ��Ŀռ�Ŀ��
	float s_y;
	//�ָ�õ��Ŀռ�ĸ߶�
	float s_z;
	//�ָ�õ��Ŀռ�����
	float s_volume;
	//�ռ�����꣬�����ҵı�׼�ǿռ����ļн�����
	Vector3 m_bottom_right_positon;
	//�޲ι���
	Space();
	//�вι��죬����Ϊ�����
	Space(float x, float y, float z);
	//�趨�ÿռ������λ��
	void Set_positon(Vector3 position);
	~Space();
};

