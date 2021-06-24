#include <myle_regex.h>
#include <myle_init.h>
#include <myle_benchmark.h>
#include <myle_makro.h>

using namespace std;


int main()
{
	MYLE::init();
	{
		MYLE::Timer regexSpeed("Regex Speed");
		std::string myString = "I love MYLE. It's such a good library!";
		if (MYLE::contains(myString, "MYLE"))
		{
			std::cout << "MYLE is contained by " << myString << std::endl;
		}
		else
		{
			std::cout << "MYLE is NOT contained by " << myString << std::endl;
		}

		myString = "abcabcabcabcabcabcdefghijklmopqrstuvwxyz";
		std::string myRegex = "abc";
		int matches = MYLE::count_matches(myString, myRegex);

		std::cout << "There has been " << matches << " matches!" << std::endl;

		myRegex = std::string(R"(((?<!=\x{A826})(?<=\x{A826}),(?=\w+=\x{A826})))");

		myString = "sendMessage:teamId=ꠦ1ꠦ,messageText=ꠦ,Hallo, mein Name ist Andreasꠦ,email=ꠦaa@aa.atꠦ";
		std::vector<std::string> regex_matches;
	
		try
		{
			regex_matches = MYLE::getAllMatches(myString, regex("((((?<!=\\x{A826})(?<=\\x{A826}),(?=\\w+=\\x{A826}))))"));
		}
		catch (std::regex_error e)
		{
			std::cout << e.what() << std::endl;
		}

		for (std::string element : regex_matches)
		{
			std::cout << element << std::endl;
		}	
		
	}
}
