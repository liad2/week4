#define _CRT_SECURE_NO_WARNINGS
#include "FileHelper.h"
#include <fstream>

std::string FileHelper::readFileToString(std::string fileName)
{
    std::string s = " ";
    FILE *f = fopen(fileName.c_str(), "r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        s.push_back(ch);
    }
    return s;
}

void FileHelper::writeWordsToFile(std::string inputFileName, std::string outputFileName)
{
    std::ifstream inFile;
    std::ofstream outFile;
    std::string word;
    inFile.open(inputFileName.c_str());
    outFile.open(outputFileName.c_str());
    while (inFile >> word) {
        outFile << word << std::endl;
    }
    outFile.close();
    inFile.close();
}

void FileHelper::saveTextInFile(std::string text, std::string outputFileName)
{
    std::ofstream outFile;
    outFile.open(outputFileName.c_str());
    outFile << text;
}
