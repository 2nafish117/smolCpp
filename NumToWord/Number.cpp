#include "Number.hpp"

const char* const Number::ten = "ten";
const char* const Number::hundred = "hundred";
const char* const Number::_and = "and";
const char* const Number::y = "y";
const char* const Number::ty = "ty";
const char* const Number::one = "one";
const char* const Number::two = "two";
const char* const Number::three = "three";
const char* const Number::four = "four";
const char* const Number::five = "five";
const char* const Number::six = "six";
const char* const Number::seven = "seven";
const char* const Number::eight = "eight";
const char* const Number::nine = "nine";
const char* const Number::eleven = "eleven";
const char* const Number::twelve = "twelve";
const char* const Number::thirteen = "thirteen";
const char* const Number::fourteen = "fourteen";
const char* const Number::fifteen = "fifteen";
const char* const Number::sixteen = "sixteen";
const char* const Number::seventeen = "seventeen";
const char* const Number::eighteen = "eighteen";
const char* const Number::nineteen = "nineteen";
const char* const Number::twenty = "twenty";
const char* const Number::thirty = "thirty";
const char* const Number::forty = "forty";
const char* const Number::fifty = "fifty";


std::string Number::toWord(const std::string& number)
{
	// @ TODO
}

std::string toWord(const std::string&& number)
{
	// @ TODO
}


std::string Number::toWordsHundreds(std::string& number)
{
	std::string word("");

	//pad it with 0's
	while(number.length() < 3)
		number = "0" + number;

	//parse hundreds place
	parseHundreds(number, word);

	//parse tens place
	parseTens(number, word);

	//parse ones place
	parseOnes(number, word);

	return word;
}

std::string Number::toWordsHundreds(std::string&& number)
{
	return toWordsHundreds(number);
}

std::string Number::toWordsHundreds(const unsigned int num)
{
	if(num > 999 || num == 0)
		return "REEE";
	
	return toWordsHundreds(std::to_string(num));
}

void Number::parseHundreds(const std::string& number, std::string& word)
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

void Number::parseTens(const std::string& number, std::string& word)
{
	switch(number[1])
	{
	case '0': //do nothing
		break;
	case '1': parseTeens(number, word);
		break;
	case '2': word = word + " " + twenty;
		break;
	case '3': word = word + " " + thirty;
		break;
	case '4': word = word + " " + forty;
		break;
	case '5': word = word + " " + fifty;
		break;
	case '6': word = word + " " + six + ty;
		break;
	case '7': word = word + " " + seven +ty;
		break;
	case '8': word = word + " " + eight + y;
		break;
	case '9': word = word + " " + nine + ty;
		break;
	default:
		std::cout << "how tf";
	}
}

void Number::parseTeens(const std::string& number, std::string& word)
{
	tensPlaceIsOne = true;
	switch(number[2])
	{
	case '0': word = word + " " + ten;
		break;
	case '1': word = word + " " + eleven;
		break;
	case '2': word = word + " " + twelve;
		break;
	case '3': word = word + " " + thirteen;
		break;
	case '4': word = word + " " + fourteen;
		break;
	case '5': word = word + " " + fifteen;
		break;
	case '6': word = word + " " + sixteen;
		break;
	case '7': word = word + " " + seventeen;
		break;
	case '8': word = word + " " + eighteen;
		break;
	case '9': word = word + " " + nineteen;
		break;
	default:
		std::cout << "how tf";
	}
}

void Number::parseOnes(const std::string& number, std::string& word)
{
	if(tensPlaceIsOne)
	{
		tensPlaceIsOne = false;
		return;
	}

	switch(number[2])
	{
	case '0': //do nothing
		break;
	case '1': word = word + " " + one;
		break;
	case '2': word = word + " " + two;
		break;
	case '3': word = word + " " + three;
		break;
	case '4': word = word + " " + four;
		break;
	case '5': word = word + " " + five;
		break;
	case '6': word = word + " " + six;
		break;
	case '7': word = word + " " + seven;
		break;
	case '8': word = word + " " + eight;
		break;
	case '9': word = word + " " + nine;
		break;
	default:
		std::cout << "how tf";
	}
}