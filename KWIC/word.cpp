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
		std::ostringstream oString{};
		std::istreambuf_iterator<char> isCopy { is };
//		std::istringstream iSS{};
//		is >> iSS;

//		std::copy_if(is, pal+size, back_inserter(pal_raw),
//		        [](char item) {return isalpha(item); }
//		    );

		std::copy_if(std::begin(isCopy),std::end(isCopy) , oString, [](char item) {
			if(isalpha(item	))
				return true;
			else
				valid = false;
				return false;
		})
//		while(is.good()){
//			if(inWord && (!std::isalpha(c) || is.fail())){
//
//				inWord = false;
//				for(char charInV : v){
//					word.word += charInV;
//				}
//				break;
//			}
//			else if(std::isalpha(c)){
//				word.word = "";
//				inWord = true;
//				v.push_back(c);
//			}
//		}
		if(valid)
			word.word = oString.str();
		else
			word.word = "";
		return is;
	}


	std::ostream & operator<<( std::ostream & os , Word const & word){
		os << word.word;
		return os;
	}
}


