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

	for (long unsigned int i = 0; i < words.size(); i++) {
		phrase tmp = words;

		std::rotate(tmp.begin(), tmp.begin() + i, tmp.end());
		result.push_back(tmp);
	}

	return result;
}

bool sortcol(const phrase &v1, const phrase &v2) {
	for (long unsigned int i = 0; i < v1.size() && i < v2.size(); i++) {
		if (v1[i] == v2[i])
			continue;
		return v1[i] < v2[i];
	}
	return v1[0] < v2[0];

}

void kwic(std::istream &is, std::ostream &out) {

	std::vector<phrase> phrases { };
	phrase wordsVector { };

	for (std::string tmp; std::getline(is, tmp, '\n');) {
		std::istringstream str(tmp + " ");
		text::Word word;
		while (str >> word) {
			wordsVector.push_back(word);
		}
		wordsVector.push_back(word);

		phrases.push_back(wordsVector);

		wordsVector = phrase { };
	}

	std::vector<phrase> bigStorage { };

	std::for_each(phrases.begin(), phrases.end(), [&bigStorage, &out](phrase singlePhrase) {
		std::vector<phrase> combinations = getCombinations(singlePhrase);
		bigStorage.insert(bigStorage.begin(), combinations.begin(), combinations.end());

	});

	std::sort(bigStorage.begin(), bigStorage.end(), sortcol);

	for (phrase wordVector : bigStorage) {
		for (text::Word word : wordVector) {
			out << word.value << " ";
		}
		out << "\n";
	}

}

}
