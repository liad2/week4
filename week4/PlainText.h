#pragma once
#include <string>
#include <ostream>
class PlainText
{

public:
	PlainText(std::string text);
	~PlainText();
	bool isEncrypted();
	virtual std::string getText();
	std::string getCipherName() const;
	std::string encrypt();
	std::string decrypt();

	static int numOfTexts;

protected:
	std::string _text;
	bool _isEnc;
	std::string _cipherName;

};

std::ostream& operator<<(std::ostream& os, PlainText& pt);
