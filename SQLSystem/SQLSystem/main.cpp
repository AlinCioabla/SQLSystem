#include"stdafx.h"
#include"SQLSystem.h"
#include"Lexer.h"
#include"LexerTester.h"


bool LexerTests()
{
	//Test #1
	cout << "Test1: " << endl;
	ifstream inputFile1("TestFile1.txt");
	Lexer lexer1;
	LexerTester lexerTester1(inputFile1, lexer1);
	bool succes1 = lexerTester1.TestTokens();
	cout << succes1 << endl << endl;
	
	//Test #2
	cout << "Test2: " << endl;
	ifstream inputFile2("TestFile2FAKE.txt");
	Lexer lexer2;
	LexerTester lexerTester2(inputFile2, lexer2);
	bool succes2 = lexerTester2.TestTokens();
	cout << succes2 << endl << endl;

	//Test #3
	cout << "Test3: " << endl;
	ifstream inputFile3("TestFile3.txt");
	Lexer lexer3;
	LexerTester lexerTester3(inputFile3, lexer3);
	bool succes3 = lexerTester3.TestTokens();
	cout << succes3 << endl << endl;

	if (succes1 && succes2 && succes3)
		return true;
	return false;
}



int main()
{

	if (!LexerTests())
		return -1;
		
	//SQLSystem program;
	//program.Start(in);


	return 0;


}