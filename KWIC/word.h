#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>
#include<algorithm>
#include <cctype>

namespace text {
	class Word {
		std::string word{"DEFAULT_WORD"};


	public:
		Word() = default;
		explicit Word(std::string word);

		std::string transformWord(std::string s) const {
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);
			return s;
		}

		bool operator<( Word const & rhs ) const{
			return  Word::transformWord(word) < Word::transformWord(rhs.word);
		}

		friend std:: istream & operator>>( std::istream & is, Word &);
		friend std:: ostream & operator<<( std::ostream & os , Word const &);
	};

	inline bool operator>( Word const & lhs, Word  const & rhs ){
		return rhs < lhs;
	}
	inline bool operator>=( Word const & lhs, Word  const & rhs ){
		return !(lhs < rhs);
	}
	inline bool operator<=( Word const & lhs, Word  const & rhs ){
		return !(rhs < lhs);
	}
	inline bool operator==( Word const & lhs, Word  const & rhs ){
		return !(lhs < rhs ) && !(rhs < lhs);
	}
	inline bool operator!=( Word const & lhs, Word  const & rhs ){
		return !(lhs == rhs);
	}
}


#endif /* WORD_H_ */
