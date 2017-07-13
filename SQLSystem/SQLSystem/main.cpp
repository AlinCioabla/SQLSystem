#include"stdafx.h"
#include"SQLSystem.h"
#include"Lexer.h"
#include"LexerTester.h"


bool LexerTests()
{
	//Test #1
	cout << "Test1: " << endl;
	ifstream _inputFile1("TestFile1.txt");
	Lexer _lexer1;
	LexerTester lexerTester1(_inputFile1, _lexer1);
	bool _succes1 = lexerTester1.TestLexer();
	cout << _succes1 << endl << endl;
	
	//Test #2
	cout << "Test2: " << endl;
	ifstream _inputFile2("TestFile2FAKE.txt");
	Lexer _lexer2;
	LexerTester lexerTester2(_inputFile2, _lexer2);
	bool _succes2 = lexerTester2.TestLexer();
	cout << _succes2 << endl << endl;

	//Test #3
	cout << "Test3: " << endl;
	ifstream _inputFile3("TestFile3.txt");
	Lexer _lexer3;
	LexerTester lexerTester3(_inputFile3, _lexer3);
	bool _succes3 = lexerTester3.TestLexer();
	cout << _succes3 << endl << endl;

	if (_succes1 && _succes2 && _succes3)
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