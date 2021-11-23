#ifndef KWIC_H_
#define KWIC_H_

#include "word.h"

#include <iostream>
#include <string>
#include <vector>

namespace text{
		using phrase = std::vector<text::Word>;

		std::vector<phrase> getTitles(std::vector<phrase> words);
		void kwic(std::istream & in, std::ostream & out);
}



#endif /* KWIC_H_ */
