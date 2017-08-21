
#include "stdafx.h"
#include "LexerTest.h"
#include "IPresenter.h"
#include "ConsolePresenter.h"
#include "DiagnosticInfo.h"
#include "FilePresenter.h"

DiagnosticInfo LexerTest::Execute()
{
  ifstream _inputFile(mInputFileName);

  if (!TestInputFile(_inputFile))
  {
    return DiagnosticInfo(12);
  }
  if (!TestReadFromFile(_inputFile))
  {
    return DiagnosticInfo(14);
  }
  if (!TestGetSqlCommand(_inputFile))
  {
    return DiagnosticInfo(50);
  }

  return TestTokenize(_inputFile);
}

LexerTest::~LexerTest() = default;

bool LexerTest::TestInputFile(ifstream & aInputFile)
{
  return !!aInputFile;
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

DiagnosticInfo LexerTest::TestTokenize(ifstream & aInputFile)
{
  string         _tokens;
  DiagnosticInfo _diagInfo = mLexer->Tokenize();
  if (_diagInfo.GetErrorCode() != 0)
  {
    return _diagInfo;
  }

  auto _currentToken = mLexer->GetNextToken();
  while (_currentToken)
  {
    _tokens += _currentToken->GetWord();
    _currentToken = mLexer->GetNextToken();
  }

  aInputFile.clear();
  aInputFile.seekg(0, aInputFile.beg);

  string _inputString((istreambuf_iterator<char>(aInputFile)), istreambuf_iterator<char>());

  if (_tokens != _inputString)
  {
    return DiagnosticInfo(124);
  }

  return DiagnosticInfo(0);
}

bool LexerTest::TestGetSqlCommand(ifstream & aInputFile)
{
  aInputFile.clear();
  aInputFile.seekg(0, aInputFile.beg);

  string _inputString((istreambuf_iterator<char>(aInputFile)), istreambuf_iterator<char>());

  return _inputString == mLexer->GetSqlCommand();
}
