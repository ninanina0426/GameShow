#pragma once
#include "Input.h"

class JoyPad :
	public Input
{
public:
	JoyPad();
	~JoyPad();

private:
	bool Update(Obj& obj);
	bool init();

	std::map<std::string, int> joyTbl_;
	
};

