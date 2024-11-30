#include "PlainText.h"

PlainText::PlainText(std::string text)
{

	_text = text;
	_isEnc = false;
	numOfTexts++;
	_cipherName = "PlainText";
}

PlainText::~PlainText()
{

}

bool PlainText::isEncrypted()
{
	return _isEnc;
}

std::string PlainText::getText()
{
	return _text;
}

std::string PlainText::getCipherName() const
{
	return _cipherName;
}

std::string PlainText::encrypt()
{
	return _text;
}

std::string PlainText::decrypt()
{
	return _text;
}

std::ostream& operator<<(std::ostream& os, PlainText& pt)
{
	os << pt.getCipherName() << std::endl << std::endl;
	if (!pt.isEncrypted())
		os << pt.encrypt();
	else
		os << pt.getText();
	os << std::endl;
	return os;
}
