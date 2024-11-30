#pragma once
#include "PlainText.h"
class ShiftText : public PlainText
{
public:
	ShiftText(std::string text, int key);
	~ShiftText();
	static std::string encrypt(std::string text, int key);
	static std::string decrypt(std::string text, int key);
	std::string encrypt();
	std::string decrypt();

protected:
	int _key;
};

