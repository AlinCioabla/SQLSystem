
#include "stdafx.h"
#include "LexerTest.h"
#include "IPresenter.h"
#include "ConsolePresenter.h"
#include "DiagnosticInfo.h"
#include "FilePresenter.h"

bool LexerTest::Execute()
{
  string        _outputFile = "FilePresenter.txt";
  ifstream      _inputFile(mInputFileName);
  FilePresenter _errorPresenter(_outputFile);

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

  DiagnosticInfo _tokenizeInfo = TestTokenize(_inputFile);
  if (_tokenizeInfo.GetErrorCode() != 0)
  {
    _errorPresenter.Present(_tokenizeInfo);
    return false;
  }

  return true;
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
