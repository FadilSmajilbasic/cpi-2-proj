#include "kwic.h"
#include "word.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

namespace text {
	std::vector<phrase> getCombinations(phrase words) {
		std::vector<phrase> result;

		for(long unsigned int i = 0; i < words.size(); i++){
			phrase tmp = words;

			std::rotate(tmp.begin(), tmp.begin()+i, tmp.end());
			result.push_back(tmp);
		}
		return result;
	}

	void kwic(std::istream & is, std::ostream & out) {
		std::vector<phrase> phrases{};
		phrase wordsVector {};

		for (std::string tmp; std::getline(is, tmp, '\n');) {
		    std::istringstream str(tmp+" ");
		    for (text::Word word; str >> word;) {
		    	wordsVector.push_back(text::Word{word.word});
		    }

		    phrases.push_back(wordsVector);
		    wordsVector = phrase{};
		}

		out << "===============\n";

		std::for_each(phrases.begin(),	 phrases.end(), [&out](phrase singlePhrase ) {
			std::vector<phrase> kwicFinished = getCombinations(singlePhrase);
			for(phrase wordVector : kwicFinished){
				for(text::Word word : wordVector){
					out << word.word << " ";
				}
				out << "\n";
			}
		});



	}
}
