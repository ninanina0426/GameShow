#pragma once
#include <map>
#include <string>

using InputDate = std::map<std::string, int>;

class Obj;
enum class InputType
{
	NOW,
	OLD
};

class Input
{
public:
	Input();
	virtual ~Input();
	virtual bool Update(Obj& obj) = 0;//�p����̂ݎg�p
	const InputDate& GetDate(InputType type);
private:
protected:
	InputDate date_;
	InputDate dateOld_;
};

