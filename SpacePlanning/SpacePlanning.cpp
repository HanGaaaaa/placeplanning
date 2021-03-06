#include "stdafx.h"
#include "Vector3.h"
#include "vector"
#include "Space.h"
#include "Tool.h"
#include "Item.h"
#include<algorithm>
using namespace std;

vector<Item> m_items;

//自定义排序函数，用于给小箱子排序
bool sortFunItem(const Item &p1, const Item &p2)
{
	return p1.m_volume > p2.m_volume;//降序排列  
}

//自定义排序函数  ，用于给分割得到的空间排序
bool sortFunSpace(const Space &p1, const Space &p2)
{
	return p1.s_volume < p2.s_volume;//升序排列  
}

bool split_space(Space space, int cur_item)
{
	for (int k = cur_item; k < m_items.size(); k++)
	{
		Item* item = &m_items[k];
		if (item->m_volume > space.s_volume)
		{
			//如果我这个小箱子比大箱子都大，那就返回错误了
			return false;
		}
		else
		{
			//判断我这个小箱子允许的放置方式
			item->Judge_put_type(space);
			if (item->put_Types.size() == 0)
			{
				//没有可用的放置方式，返回错误
				return false;
			}
			else
			{
				//对每一种可行的放置方式进行讨论
				for (size_t i = 0; i < item->put_Types.size(); i++)
				{
					//这里只讨论一种吧。。有六种摆放方式，这里省略了其他五五种的放置方式
					if (item->put_Types[i] == Item::dir_xy)
					{
						//设置中心坐标
						item->Calc_center_positon(space.m_bottom_right_positon);
						//设置放置方式
						item->put_Type = Item::dir_xy;
						//分割方式的存储容器
						vector<vector<Space>> six_split_type;

						Vector3 vector3;
						//讨论分割剩余空间的方式，4种可能，第一种分割方式
						{
							//得到空间1
							vector<Space> spaces_one;
							//构建空间1，传入长宽高
							Space one(item->x_length, item->y_length, space.s_z - item->z_length);
							//设置该空间的坐标
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z + item->z_length / 2);
							one.Set_positon(vector3);
							spaces_one.push_back(one);
							//得到空间2
							Space two(item->x_length, space.s_y - item->y_length, space.s_z);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y + item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							two.Set_positon(vector3);
							spaces_one.push_back(two);
							//得到空间3
							Space three(space.s_x - item->x_length, space.s_y, space.s_z);
							vector3.Set(item->center_vector.position_x + item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							three.Set_positon(vector3);
							spaces_one.push_back(three);
							//升序
							sort(spaces_one.begin(), spaces_one.end(), sortFunSpace);
							six_split_type.push_back(spaces_one);
						}
						//第二种分割空间方式
						{
							vector<Space> spaces_two;
							Space one(item->x_length, item->y_length, space.s_z - item->z_length);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z + item->z_length / 2);
							one.Set_positon(vector3);
							spaces_two.push_back(one);
							Space two(space.s_x, space.s_y - item->y_length, space.s_z);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y + item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							two.Set_positon(vector3);
							spaces_two.push_back(two);
							Space three(space.s_x - item->x_length, item->y_length, space.s_z);
							vector3.Set(item->center_vector.position_x + item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							three.Set_positon(vector3);
							spaces_two.push_back(three);
							//升序
							sort(spaces_two.begin(), spaces_two.end(), sortFunSpace);
							six_split_type.push_back(spaces_two);
						}
						//第三种分割空间方式
						{
							vector<Space> spaces_three;
							Space one(item->x_length, space.s_y, space.s_z - item->z_length);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z + item->z_length / 2);
							one.Set_positon(vector3);
							spaces_three.push_back(one);
							Space two(item->x_length, space.s_y - item->y_length, item->z_length);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y + item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							two.Set_positon(vector3);
							spaces_three.push_back(two);
							Space three(space.s_x - item->x_length, space.s_y, space.s_z);
							vector3.Set(item->center_vector.position_x + item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							three.Set_positon(vector3);
							spaces_three.push_back(three);
							//升序
							sort(spaces_three.begin(), spaces_three.end(), sortFunSpace);
							six_split_type.push_back(spaces_three);
						}
						//第四种分割空间方式
						{
							vector<Space> spaces_four;
							Space one(space.s_x, item->y_length, space.s_z - item->z_length);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z + item->z_length / 2);
							one.Set_positon(vector3);
							spaces_four.push_back(one);
							Space two(space.s_x, space.s_y - item->y_length, space.s_z);
							vector3.Set(item->center_vector.position_x - item->x_length / 2, item->center_vector.position_y + item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							two.Set_positon(vector3);
							spaces_four.push_back(two);
							Space three(space.s_x - item->x_length, item->y_length, space.s_z);
							vector3.Set(item->center_vector.position_x + item->x_length / 2, item->center_vector.position_y - item->y_length / 2, item->center_vector.position_z - item->z_length / 2);
							three.Set_positon(vector3);
							spaces_four.push_back(three);
							//升序
							sort(spaces_four.begin(), spaces_four.end(), sortFunSpace);
							six_split_type.push_back(spaces_four);
						}
						bool total_result = false;
						//对四种分割方式做遍历
						for (int m = 0; m < six_split_type.size(); m++)
						{
							//对三块空间做遍历
							for (size_t i = 0; i < six_split_type[m].size(); i++)
							{
								//递归调用该函数，当前物体下标+1
								if (split_space(six_split_type[m][i], cur_item + 1))
								{
									//只有有一种放置和分割方案可行，就返回true
									total_result = true;
								}
							}
						}
						return total_result;
					}
				}
			}
		}
	}
	return true;
}




int main()
{
	float total_x = Tool::Get_input((char *)"请输入大箱子长度，必须为数值型数据：");
	float total_y = Tool::Get_input((char *)"请输入大箱子宽度，必须为数值型数据：");
	float total_z = Tool::Get_input((char *)"请输入大箱子高度，必须为数值型数据：");
	int item_count = (int)Tool::Get_input((char *)"请输入小箱子数量, 必须为数值型数据：");
	float all_volume = 0.0;
	for (int i = 0; i < item_count; i++)
	{
		float x = Tool::Get_input((char *)"请输入第%d个小箱子的长度：", i + 1);
		float y = Tool::Get_input((char *)"请输入第%d个小箱子的宽度：", i + 1);
		float z = Tool::Get_input((char *)"请输入第%d个小箱子的高度：", i + 1);
		Item item(x, y, z);
		printf("第%d个小箱子的体积是：%f \n", i + 1, item.m_volume);
		m_items.push_back(item);
		all_volume += item.m_volume;
	}
	//这里给小箱子排序，降序，放的时候先放大一点的箱子
	sort(m_items.begin(), m_items.end(), sortFunItem);
	Space total_space(total_x, total_y, total_z);
	total_space.Set_positon(Vector3(0.0, 0.0, 0.0));
	//先大致判断一下，如果总的体积都比大箱子大，那就没得往下算了
	if (all_volume > total_space.s_volume)
	{
		printf("无法全部放入\n");
	}
	else
	{
		//计算算法，返回true  false
		bool result = split_space(total_space, 0);
		if (result)
		{
			printf("可以全部放入\n");
			for (int i = 0; i < m_items.size(); i++)
			{
				//如果可以放入则打印每个箱子放置的方式和位置信息
				m_items[i].To_string(i);
			}
		}
		else
		{
			printf("无法全部放入\n");
		}
		system("pause");
	}
    return 0;
}

