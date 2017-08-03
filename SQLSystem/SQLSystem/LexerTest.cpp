
#include "stdafx.h"
#include "LexerTest.h"

bool LexerTest::Execute(Lexer aLexer)
{
  ifstream _inputFile(mInputFileName);
  if (!TestInputFile(_inputFile))
  {
    cout << "Cannot open the specified input file" << endl;
    return false;
  }
  if (!TestReadFromFile(aLexer, _inputFile))
  {
    cout << "Failed to read properly from the given file" << endl;
    return false;
  }
  if (!TestGetSqlCommand(aLexer))
  {
    cout << "Cannot retrieve the initial input." << endl;
    return false;
  }
  if (!TestTokenize(aLexer))
  {
    cout << "Tokenization did not end properly. Unexpected symbol" << endl;
    return false;
  }
  if (!TestGetNextToken(aLexer))
  {
    cout << "Getting next token failed." << endl;
    return false;
  }

  return true;
}

LexerTest::~LexerTest()
{
}

bool LexerTest::TestInputFile(ifstream & aInputFile)
{
  if (!aInputFile)
  {
    return false;
  }
  return true;
}

bool LexerTest::TestReadFromFile(Lexer & aLexer, ifstream & aInputFile)
{
  if (aLexer.ReadFromFile(aInputFile))
  {
    string _temp;
    char   _c;
    aInputFile.clear();
    aInputFile.seekg(0, aInputFile.beg);

    while (aInputFile.get(_c))
    {
      _temp += _c;
    }
    return _temp == aLexer.mSqlCommand;
  }
  return false;
}

bool LexerTest::TestTokenize(Lexer & aLexer)
{
  string _tokens;
  if (!aLexer.Tokenize())
    return false;

  for (auto & it : aLexer.mTokens)
    _tokens += it->GetWord();
  return _tokens == aLexer.mSqlCommand;
}

bool LexerTest::TestGetNextToken(Lexer & aLexer)
{
  for (auto token : aLexer.mTokens)
  {
    if (token != aLexer.GetNextToken())
      return false;
  }
  return true;
}

bool LexerTest::TestGetSqlCommand(Lexer & aLexer)
{
  return aLexer.mSqlCommand == aLexer.GetSqlCommand();
}
