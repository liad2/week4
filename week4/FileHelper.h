#pragma once
#include "string"
class FileHelper
{
	std::string readFileToString(std::string fileName);
	void writeWordsToFile(std::string inputFileName, std::string   outputFileName);
	void saveTextInFile(std::string text, std::string outputFileName);




};

