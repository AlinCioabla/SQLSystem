#include "stdafx.h"
#include "ParserTest.h"

bool ParserTest::Execute(ITokensTraversal & aLexer, Parser & aParser)
{
  ifstream _inputFile(mInputFileName);
  if (!TestInputFile(_inputFile))
  {
    cout << "Cannot open the given file" << endl;
    return false;
  }
  aLexer.ReadFromFile(_inputFile);
  aLexer.Tokenize();

  _inputFile.clear();
  _inputFile.seekg(0, _inputFile.beg);

  if (!TestConstructAst(aLexer, aParser))
  {
    cout << "Cannot construct AST. Invalid syntax." << endl;
    return false;
  }
  if (!TestAst(aParser))
  {
    cout << "AST was not constructed properly" << endl;
    return false;
  }

  DisplayAst(aParser);
  PrintQueryFromAst(aParser);
  return true;
}

ParserTest::~ParserTest()
{
}

bool ParserTest::TestInputFile(ifstream & aInputFile)
{
  if (!aInputFile)
  {
    return false;
  }
  return true;
}

bool ParserTest::TestConstructAst(ITokensTraversal & aLexer, Parser & aParser)
{
  return aParser.Parse(aLexer);
}

bool ParserTest::TestAst(Parser aParser)
{
  return true;
}

void ParserTest::PrintQueryFromAst(Parser aParser)
{
  auto root = aParser.GetAst().GetRoot();
  aParser.GetAst().PrintQuery(root);
}

void ParserTest::DisplayAst(Parser aParser)
{
  auto root = aParser.GetAst().GetRoot();
  aParser.GetAst().Display(root, 20);
}
