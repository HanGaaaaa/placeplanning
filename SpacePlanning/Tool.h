#pragma once

using namespace std;
class Tool
{
public:
	Tool();
	static float Get_input(char* tip);
	static float Get_input(char* tip, int i);
	~Tool();
};

