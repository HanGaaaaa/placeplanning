#pragma once
#include "Vector3.h"
#include "vector"
#include "Space.h"
using namespace std;
class Item
{
public:
	//���캯��������ΪС���ӵĳ����
	Item(float x, float y, float z);
	//���ӳ���
	float x_length;
	//���ӿ��
	float y_length;
	//���Ӹ߶�
	float z_length;
	//�������
	float m_volume;
	//���ӵķ��÷�ʽ�������ҵı�׼�ǣ��Ӵ����ӵĴ�ֱ�������¿����ܿ�����С���ӵ��������������ṹ�ɵ�
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
	//С���ӵ���������
	Vector3 center_vector;
	//�����ӿ�������ķ��÷�ʽ
	vector<Put_type> put_Types;
	//����������
	void To_string(int i);
	//�ж����ӿ������ļ��ַ��÷�ʽ
	void Judge_put_type(Space space);
	//�������ӵ���������
	void Calc_center_positon(Vector3 base_vector);
	//��������
	~Item();
};

