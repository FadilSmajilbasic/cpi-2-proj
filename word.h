#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>
namespace text {
	class Word {
		std::string word{"DEFAULT_WORD"};


	public:
		Word() = default;
		explicit Word(std::string word);

		friend std:: istream & operator>>( std::istream & is, Word &);
		friend std:: ostream & operator<<( std::ostream & os , Word const &);
	};
}


#endif /* WORD_H_ */
