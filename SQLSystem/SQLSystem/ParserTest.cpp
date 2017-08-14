#include "stdafx.h"
#include "ParserTest.h"

bool ParserTest::Execute()
{
  ifstream _inputFile(mInputFileName);
  if (!TestInputFile(_inputFile))
  {
    cout << "Cannot open the given file" << endl;
    return false;
  }
  mLexer->ReadFromFile(_inputFile);
  mLexer->Tokenize();

  _inputFile.clear();
  _inputFile.seekg(0, _inputFile.beg);

  if (!TestConstructAst())
  {
    cout << "Cannot construct AST. Invalid syntax." << endl;
    return false;
  }
  else if (!TestAst())
  {
    cout << "AST was not constructed properly" << endl;
    return false;
  }

  else
  {
    DisplayAst();
    PrintQueryFromAst();
    return true;
  }
}

ParserTest::~ParserTest()
{
}

bool ParserTest::TestInputFile(ifstream & aInputFile)
{
  if (aInputFile)
  {
    return true;
  }
  return false;
}

bool ParserTest::TestConstructAst()
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
