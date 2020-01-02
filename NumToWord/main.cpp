#include <iostream>
#include <fstream>
#include <string>
#include "Number.hpp"

const char* const power_to_word[] = {
	"ten",
	"hundred",
	"thousand",
	"million",
	"billion",
	"trillion"
};

const char* const num_to_word[20] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

std::string NumToWord(const char* number)
{
    std::string num(number);
	std::string res;

	num_to_word[]

	return res;
}

void parseHundreds(const std::string& number, std::string& word)
{
	static std::string temp_and;
	if(number[1] == '0' && number[2] == '0')
		temp_and = "";
	else
		temp_and = "and";
	
	switch(number[0])
	{
	case '0': //do nothing
		break;
	case '1': 
		word = word + " " + one + " " + hundred + " " + temp_and;
		break;
	case '2':
		word = word + " " + two + " " + hundred + " " + temp_and;
		break;
	case '3':
		word = word + " " + three + " " + hundred + " " + temp_and;
		break;
	case '4':
		word = word + " " + four + " " + hundred + " " + temp_and;
		break;
	case '5':
		word = word + " " + five + " " + hundred + " " + temp_and;
		break;
	case '6':
		word = word + " " + six + " " + hundred + " " + temp_and;
		break;
	case '7':
		word = word + " " + seven + " " + hundred + " " + temp_and;
		break;
	case '8':
		word = word + " " + eight + " " + hundred + " " + temp_and;
		break;
	case '9':
		word = word + " " + nine + " " + hundred + " " + temp_and;
		break;
	default:
		std::cout << "tf did you just do to make this happen?";
	}
}

int main()
{
    std::string inWords = NumToWord("13153436");

    // Number num;
    // std::ofstream output;
    // output.open("output.txt");

    // for(int i = 1;i <= 999;i++)
    //     output << num.toWordsHundreds(std::to_string(i)) << std::endl;

    return 0;
}