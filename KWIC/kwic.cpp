#include "kwic.h"
#include "word.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

namespace text {


void kwic(std::istream &is) {
	text::Word words { };

	is >> words;

	std::vector<std::string> wordsVector { };
	std::ostringstream out { };

	out << words;

	wordsVector.push_back(out.str());

	std::vector<std::vector<std::string>> kwicFinished = getTitles(wordsVector);


}

std::vector<std::vector<std::string>> getTitles(std::vector<std::string> words) {

	int modVal = words.size() - 1;

	std::vector<std::vector<std::string>> result;

	for (int i = 0; i < modVal; i++) {
		for (int k = 0; k < modVal; k++) {
			result[i][k] = words[(i+k)%modVal];
		}
	}
	return result;
}

}
