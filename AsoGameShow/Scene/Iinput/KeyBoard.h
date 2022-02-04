#pragma once
#include "Input.h"


class KeyBoard :
	public Input
{
public:
	KeyBoard();
	~KeyBoard();
private:
	bool Update(Obj& obj) override;;
	bool init(void);

	std::map<std::string, int> keyTbl_;
	char KeyData_[256];
};

