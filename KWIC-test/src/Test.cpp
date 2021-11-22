#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
#include "kwic.h"
#include <iostream>
#include <string>

void inputTest() {
	std::istringstream input{"compl33tely ~ weird !!?!! 4matted in_put"};
	std::ostringstream output{};

	text::Word w{};

	input >> w;
	output << w << "\n";

	input >> w;
	output << w << "\n";

	input >> w;
	output << w << "\n";

	input >> w;
	output << w << "\n";

	input >> w;
	output << w << "\n";

	input >> w;
	output << w << "\n";

	ASSERT_EQUAL("compl\ntely\nweird\nmatted\nin\nput\n",output.str());
}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(inputTest));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
