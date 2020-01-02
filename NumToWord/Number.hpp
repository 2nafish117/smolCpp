# pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Number
{
public:
    std::string toWord(const std::string& number);
    std::string toWord(const std::string&& number);
    std::string toWordsHundreds(std::string& number);
    std::string toWordsHundreds(std::string&& number);
    std::string toWordsHundreds(const unsigned int num);

private:
    bool tensPlaceIsOne = false;
    const static char* const ten;
    const static char* const hundred;
    const static char* const _and;
    const static char* const y;
    const static char* const ty;

    const static char* const one;
    const static char* const two;
    const static char* const three;
    const static char* const four;
    const static char* const five;
    const static char* const six;
    const static char* const seven;
    const static char* const eight;
    const static char* const nine;
 
    const static char* const eleven;
    const static char* const twelve;
    const static char* const thirteen;
    const static char* const fourteen;
    const static char* const fifteen;
    const static char* const sixteen;
    const static char* const seventeen;
    const static char* const eighteen;
    const static char* const nineteen;
 
    const static char* const twenty;
    const static char* const thirty;
    const static char* const forty;
    const static char* const fifty;

private:
    void parseHundreds(const std::string& number, std::string& word);
    void parseTens(const std::string& number, std::string& word);
    void parseTeens(const std::string& number, std::string& word);
    void parseOnes(const std::string& number, std::string& word);
};