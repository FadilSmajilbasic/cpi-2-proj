#include "word.h"

#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace text {
	Word::Word(std::string str){
		bool valid{true};
		std::for_each(str.begin(), str.end(), [&valid] (char const &c) {
			if(!std::isalpha(c)) { valid = false; }
		});

		if(valid){
			word = str;
		}
	}

	std::string Word::transformWord(std::string s) const {
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		return s;
	}

	std::istream & operator>>(std::istream & is, Word & word){
		std::vector<char> v {};
		char c{};
		bool inWord{false};
		while(is.good()){
			word.word = "";
			is >> std::noskipws >> c;
			if(inWord == true && (!std::isalpha(c) || is.fail())){
				inWord = false;
				for(char charInV : v){
					word.word += charInV;
				}
				break;
			}
			else if(std::isalpha(c)){
				inWord = true;
				v.push_back(c);
			}
		}
		return is;
	}


	std::ostream & operator<<( std::ostream & os , Word const & word){
		os << word.word;
		return os;
	}
}


