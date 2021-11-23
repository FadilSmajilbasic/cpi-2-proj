#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

namespace text {
	class Word {
	public:
		std::string word{"DEFAULT_WORD"};

		Word() = default;
		explicit Word(std::string word);

		std::string transformWord(std::string s) const;

		bool operator<( Word const & rhs ) const{
			return  Word::transformWord(word) < Word::transformWord(rhs.word);
		}

		bool operator==( Word const & rhs) const{
			return (Word::transformWord(word).compare(Word::transformWord(rhs.word))) == 0;
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
	inline bool operator!=( Word const & lhs, Word  const & rhs ){
		return !(lhs == rhs);
	}
}


#endif /* WORD_H_ */
