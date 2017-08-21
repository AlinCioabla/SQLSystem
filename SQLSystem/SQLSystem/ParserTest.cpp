#include "stdafx.h"
#include "ParserTest.h"
#include "IPresenter.h"
#include "ConsolePresenter.h"
#include "FilePresenter.h"
#include "LexerTest.h"
DiagnosticInfo ParserTest::Execute()
{
  ifstream _inputFile(mInputFileName);

  if (!TestInputFile(_inputFile))
  {
    return DiagnosticInfo(12);
  }

  mLexer->ReadFromFile(_inputFile);
  mLexer->Tokenize();

  _inputFile.clear();
  _inputFile.seekg(0, _inputFile.beg);

  DiagnosticInfo _parseInfo = TestConstructAst();

  if (_parseInfo.GetErrorCode() != 0)
  {
    return _parseInfo;
  }
  if (!TestAst())
  {
    return DiagnosticInfo(205);
  }
  return DiagnosticInfo(0);
}

ParserTest::~ParserTest() = default;

bool ParserTest::TestInputFile(ifstream & aInputFile)
{
  return static_cast<bool>(aInputFile);
}

DiagnosticInfo ParserTest::TestConstructAst()
{
  return mParser->Parse();
}

bool ParserTest::TestAst()
{
  return true;
}

void ParserTest::PrintQueryFromAst()
{
}

void ParserTest::DisplayAst()
{
  auto root = mParser->GetAst().GetRoot();
  mParser->GetAst().Display(root, 20);
}
