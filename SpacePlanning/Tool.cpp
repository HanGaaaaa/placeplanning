#include "stdafx.h"
#include "Tool.h"
#include "stdio.h"
#include "iostream"
#include "sstream"
using namespace std;


Tool::Tool()
{
}

float Tool::Get_input(char* tip) 
{
	printf(tip);
	float value;
	scanf_s("%f", &value);
	return value;
}


float Tool::Get_input(char* tip, int i)
{
	printf(tip, i);
	float value;
	scanf_s("%f", &value);
	return value;
}

Tool::~Tool()
{
}
