#include "word.h"

#include <iostream>
#include <sstream>

int main(){
	std::istringstream input{"compl33tely ~ weird !!?!! 4matted in_put"};
	text::Word w{};

	input >> w;
	std::cout << w << "\n";

	input >> w;
	std::cout << w << "\n";

	input >> w;
	std::cout << w << "\n";

	input >> w;
	std::cout << w << "\n";

	input >> w;
	std::cout << w << "\n";

	input >> w;
	std::cout << w << "\n";

	input >> w;


}