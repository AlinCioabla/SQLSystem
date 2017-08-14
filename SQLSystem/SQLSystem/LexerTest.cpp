
#include "stdafx.h"
#include "LexerTest.h"

bool LexerTest::Execute()
{
  ifstream _inputFile(mInputFileName);
  if (!TestInputFile(_inputFile))
  {
    cout << "Cannot open the specified input file" << endl;
    return false;
  }
  if (!TestReadFromFile(_inputFile))
  {
    cout << "Failed to read properly from the given file" << endl;
    return false;
  }
  if (!TestGetSqlCommand(_inputFile))
  {
    cout << "Cannot retrieve the initial input." << endl;
    return false;
  }
  if (!TestTokenize(_inputFile))
  {
    cout << "Tokenization did not end properly. Unexpected symbol" << endl;
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

bool LexerTest::TestReadFromFile(ifstream & aInputFile)
{
  if (mLexer->ReadFromFile(aInputFile))
  {
    aInputFile.clear();
    aInputFile.seekg(0, aInputFile.beg);

    string _inputString((istreambuf_iterator<char>(aInputFile)), istreambuf_iterator<char>());
    return _inputString == mLexer->GetSqlCommand();
  }
  return false;
}

bool LexerTest::TestTokenize(ifstream & aInputFile)
{
  string _tokens;
  if (!mLexer->Tokenize())
    return false;

  auto _currentToken = mLexer->GetNextToken();
  while (_currentToken)
  {
    _tokens += _currentToken->GetWord();
    _currentToken = mLexer->GetNextToken();
  }

  aInputFile.clear();
  aInputFile.seekg(0, aInputFile.beg);

  string _inputString((istreambuf_iterator<char>(aInputFile)), istreambuf_iterator<char>());

  return _tokens == _inputString;
}

bool LexerTest::TestGetSqlCommand(ifstream & aInputFile)
{
  aInputFile.clear();
  aInputFile.seekg(0, aInputFile.beg);

  string _inputString((istreambuf_iterator<char>(aInputFile)), istreambuf_iterator<char>());

  return _inputString == mLexer->GetSqlCommand();
}
