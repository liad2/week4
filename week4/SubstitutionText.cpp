#define _CRT_SECURE_NO_WARNINGS
#include "SubstitutionText.h"
#include <iostream>

SubstitutionText::SubstitutionText(std::string text, std::string dictionaryFileName) :
	PlainText(text)
{
	_dictionaryFileName = dictionaryFileName;
	_cipherName = "Substitution";
}

SubstitutionText::~SubstitutionText()
{
}

std::string SubstitutionText::crypt(std::string text, const char dictionary[26])
{
	std::string s;
	s.resize(text.length());
	int i = 0;
	for (i = 0; i < text.length(); i++) {
		if (text[i] >= 'a' && text[i] <= 'z')
			s[i] = dictionary[text[i] - 'a'];
		else
			s[i] = text[i];
	}

	return s;
}

std::string SubstitutionText::encrypt(std::string text, std::string dictionaryFileName)
{
	char dictionary[26];
	std::string s;
	readDictionary(dictionaryFileName, dictionary);
	return crypt(text, dictionary);
}

std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{
	char dictionary[26];
	char inv[26];
	std::string s;
	readDictionary(dictionaryFileName, dictionary);
	inverseDictionary(dictionary, inv);
	return crypt(text, inv);
}

std::string SubstitutionText::encrypt()
{
	_text = encrypt(_text, _dictionaryFileName);
	_isEnc = true;
	return _text;
}

std::string SubstitutionText::decrypt()
{
	_text = decrypt(_text, _dictionaryFileName);
	_isEnc = false;
	return _text;
}

void SubstitutionText::readDictionary(std::string dictionaryFileName, char dictionary[26])
{
	FILE *f = fopen(dictionaryFileName.c_str(), "r");
	char line[256];
	int i = 0;
	if (f == NULL) {
		std::cerr << "Error opening dictionary " << dictionaryFileName << std::endl;
		return;
	}

	while (fgets(line, sizeof(line), f)) {
		dictionary[i] = line[2];
		i++;
		if (i == 26)
			break;
	}

	fclose(f);
}

void SubstitutionText::inverseDictionary(const char dictionary[26], char inv[26])
{
	int i = 0;
	for (i = 0; i < 26; i++)
		inv[dictionary[i] - 'a'] = i + 'a';
}
