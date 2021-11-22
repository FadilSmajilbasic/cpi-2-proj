#include "word.h"
#include "kwic.h"
#include <iostream>
#include <sstream>

int main(){




	text::Word v{"Aa"};
	text::Word x{"aab"};

	std::cout << (v==x) << (v<x);

}
