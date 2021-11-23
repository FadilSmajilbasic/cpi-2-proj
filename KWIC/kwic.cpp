#include "kwic.h"
#include "word.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

namespace text {

	std::vector<phrase> getTitles(phrase words) {
		std::vector<phrase> result;
		for(int i = 1; i < words.size(); i++){
			std::rotate(words.begin(), words.begin()+i, words.end());
			result.push_back(words);
		}
		return result;
	}

	void kwic(std::istream & is, std::ostream & out) {
		text::Word line{};
		phrase wordsVector {};
		while(is.good()){
			is >> line;
			wordsVector.push_back(text::Word{line.word});
		}
		std::vector<phrase> kwicFinished = getTitles(wordsVector);
		for(phrase wordVector : kwicFinished){
			for(text::Word word : wordVector){
				out << word.word << " ";
			}
			out << "\n";
		}
	}
}
