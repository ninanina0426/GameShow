#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}



const InputDate& Input::GetDate(InputType type)
{
	if (type == InputType::NOW)
	{
		return date_;
	}
	else
	{
		return dateOld_;
	}
			
		
	
}
