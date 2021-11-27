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
	Word::Word(std::string str){
		bool valid{true};
		std::for_each(str.begin(), str.end(), [&valid] (char const &c) {
			if(!std::isalpha(c)) { valid = false; }
		});

		if(valid && str.size() > 0){
			word = str;
		}else{
			throw std::invalid_argument("Invalid syntax.");
		}
	}

	std::string Word::transformWord(std::string s) const {
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		return s;
	}

	std::istream & operator>>(std::istream & is, Word & word){
		std::vector<char> v {};
		char c{};
		bool valid{true};


		while(is.good()){
			if(valid && (!std::isalpha(c) || is.fail())){

				valid = false;
				for(char charInV : v){
					word.word += charInV;
				}
				break;
			}
			else if(std::isalpha(c)){
				word.word = "";
				valid = true;
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


