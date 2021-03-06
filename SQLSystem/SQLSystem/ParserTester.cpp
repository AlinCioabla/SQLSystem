#include "stdafx.h"
#include "ParserTester.h"
DiagnosticInfo ParserTester::ConstructAst()
{
  return mParser.Parse();
}

void ParserTester::PrintQueryFromAst()
{
  auto root = mParser.GetAst().GetRoot();
  // mParser.GetAst().PrintQuery(root);
}

void ParserTester::DisplayAst()
{
  auto root = mParser.GetAst().GetRoot();
  // mParser.GetAst().Display(root, 20);
}

bool ParserTester::TestAst()
{
  return false;
}

ParserTester::~ParserTester() = default;
