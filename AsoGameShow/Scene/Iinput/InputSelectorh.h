#pragma once
#include <DxLib.h>
#include <memory>
#include "JoyPad.h"
#include "KeyBoard.h"



struct InputSelector
{
	std::unique_ptr<Input> operator()()
	{
		std::unique_ptr<Input> input_;
		if (GetJoypadNum())
		{
			input_ = std::make_unique<JoyPad>();
		}
		else
		{
			input_ = std::make_unique<KeyBoard>();
		}
		return std::move(input_);
	}
	
};
