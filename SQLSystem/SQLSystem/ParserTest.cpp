#include "stdafx.h"
#include "ParserTest.h"
#include "IPresenter.h"
#include "ConsolePresenter.h"
bool ParserTest::Execute()
{
  ifstream         _inputFile(mInputFileName);
  ConsolePresenter _errorPresenter;
  if (!TestInputFile(_inputFile))
  {
    cout << "Cannot open the given file" << endl;
    return false;
  }
  mLexer->ReadFromFile(_inputFile);

  mLexer->Tokenize();

  _inputFile.clear();
  _inputFile.seekg(0, _inputFile.beg);

  DiagnosticInfo _parseInfo = TestConstructAst();

  if (_parseInfo.GetErrorCode() != 0)
  {
    _errorPresenter.Present(_parseInfo);
    return false;
  }
  if (!TestAst())
  {
    cout << "AST was not constructed properly" << endl;
    return false;
  }

  DisplayAst();
  PrintQueryFromAst();
  return true;
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
  auto root = mParser->GetAst().GetRoot();
  mParser->GetAst().PrintQuery(root);
}

void ParserTest::DisplayAst()
{
  auto root = mParser->GetAst().GetRoot();
  mParser->GetAst().Display(root, 20);
}
