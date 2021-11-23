#include "word.h"
#include "kwic.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

int main(){
	std::istringstream input{"this is a test \n this is another test"};
	text::kwic(input, std::cout);
}
