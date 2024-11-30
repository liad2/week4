#pragma once
#include "PlainText.h"
class SubstitutionText  : public PlainText
{
public:
	SubstitutionText(std::string text, std::string dictionaryFileName);
	~SubstitutionText();
	static std::string crypt(std::string text, const char dictionary[26]);
	static std::string encrypt(std::string text, std::string dictionaryFileName);
	static std::string decrypt(std::string text, std::string dictionaryFileName);
	std::string encrypt();
	std::string decrypt();

private:
	static void readDictionary(std::string dictionaryFileName, char dictionary[26]);
	static void inverseDictionary(const char dictionary[26], char inv[26]);

	std::string _dictionaryFileName;
};

