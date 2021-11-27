#include "word.h"

#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

namespace text {
Word::Word(std::string str) {
	bool valid { true };
	std::for_each(str.begin(), str.end(), [&valid](char const &c) {
		if (!std::isalpha(c)) {
			valid = false;
		}
	});

	if (valid && str.size() > 0) {
		word = str;
	} else {
		throw std::invalid_argument("Invalid syntax.");
	}
}

std::string Word::transformWord(std::string s) const {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

std::istream& operator>>(std::istream &is, Word &word) {

	if (is.rdbuf()->in_avail() > 0) { // check if input stream has any element
		char temp { };
		bool ignoredAChar { false };
		word.word = "";
		is >> std::noskipws;
		temp = is.peek();

		while (temp != EOF) { // check if next char is not EOF

			if (std::isalpha(temp)) { // enter if, if next char is valid

				if (ignoredAChar) {
					ignoredAChar = false;  // reset flag if last char was invalid
					if (!word.word.empty()) // end the word if it's not empty (some valid characters were already found)
						break;
				}
				word.word += is.get(); // add char to word

			} else {
				is.ignore(1);	// ignore 1 invalid char
				ignoredAChar = true;
			}

			temp = is.peek(); // peek at next char

		}

	}

	if (word.word.empty()) { // set input as failed if no valid chars were found
		is.setstate(std::ios::failbit);
	}
	return is;
}

std::ostream& operator<<(std::ostream &os, Word const &word) {
	os << word.word;
	return os;
}
}

