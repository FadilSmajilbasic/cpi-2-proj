#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

namespace text {
	class Word {
	public:
		std::string value{""};

		Word() = default;
		explicit Word(std::string word);

		std::string transformWord(std::string s) const;

		bool operator<( Word const & rhs ) const{
			return  Word::transformWord(value) < Word::transformWord(rhs.value);
		}

		bool operator==( Word const & rhs) const{
			return (Word::transformWord(value).compare(Word::transformWord(rhs.value))) == 0;
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
