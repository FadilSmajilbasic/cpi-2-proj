#ifndef KWIC_H_
#define KWIC_H_

#include <iostream>
#include <vector>

namespace text{
class Kwic{
public:
	void kwic(const std::istream in);

	std::vector<std::vector<std::string>> getTitles(std::vector<std::string> words) ;

};
}



#endif /* KWIC_H_ */
