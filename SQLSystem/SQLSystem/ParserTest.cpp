#include "stdafx.h"
#include "ParserTest.h"
#include "IPresenter.h"
#include "AstTraversal.h"
#include "ConsolePresenter.h"
#include "FilePresenter.h"
#include "Helpers.h"
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
  return !!aInputFile;
}

DiagnosticInfo ParserTest::TestConstructAst()
{
  return mParser->Parse();
}

bool ParserTest::TestAst()
{
  ReWriter rewriter(mParser->GetAst());
  rewriter.DisplayAstInConsole(mParser->GetAst().GetRoot(), 20);

  string queryFromAst = rewriter.GetQuery();
  string initialQuery = mLexer->GetSqlCommand();

  FormatQuery(initialQuery);
  FormatQuery(queryFromAst);

  return initialQuery == queryFromAst;
}
