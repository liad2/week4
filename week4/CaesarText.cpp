#include "CaesarText.h"

#define KEY 3

CaesarText::CaesarText(std::string text) :
	ShiftText(text, KEY)
{
	_cipherName = "Caesar";
}

CaesarText::~CaesarText()
{

}

std::string CaesarText::encrypt(std::string text)
{
	return ShiftText::encrypt(text, KEY);
}

std::string CaesarText::decrypt(std::string text)
{
	return ShiftText::decrypt(text, KEY);
}

std::string CaesarText::encrypt()
{
	return ShiftText::encrypt();
}

std::string CaesarText::decrypt()
{
	return ShiftText::decrypt();
}
