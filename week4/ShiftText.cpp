#include "ShiftText.h"

ShiftText::ShiftText(std::string text, int key) :
	PlainText(text)
{
	_key = key;
	_cipherName = "Shift";
}

ShiftText::~ShiftText()
{

}

std::string ShiftText::encrypt(std::string text, int key)
{
	std::string s;
	s.resize(text.length());
	int i = 0;
	for (i = 0; i < text.length(); i++) 
	{
		s[i] = text[i] - key;
	}
	return s;
}

std::string ShiftText::decrypt(std::string text, int key)
{
	std::string s;
	s.resize(text.length());
	int i = 0;
	for (i = 0; i < text.length(); i++)
	{
		s[i] = text[i] + key;
	}
	return s;
}

std::string ShiftText::encrypt()
{
	_text = encrypt(_text, _key);
	_isEnc = true;
	return _text;
}

std::string ShiftText::decrypt()
{
	_text = decrypt(_text, _key);
	_isEnc = false;
	return _text;
}
