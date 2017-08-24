#include "stdafx.h"
#include "ReWriter.h"

void ReWriter::RewriteQuery(AstNode * aNode, string & aAstQuery) const
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      aAstQuery += aNode->GetToken()->GetWord();
      aAstQuery += " ";
    }
    RewriteQuery(aNode->GetLeft().get(), aAstQuery);
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      aAstQuery += aNode->GetToken()->GetWord();
      aAstQuery += " ";
    }
    RewriteQuery(aNode->GetRight().get(), aAstQuery);
  }
}

void ReWriter::DisplayAstInConsole(AstNode * aNode, int indent) const
{
  if (aNode != nullptr)
  {
    if (aNode->GetRight())
    {
      DisplayAstInConsole(aNode->GetRight().get(), indent + 4);
    }
    if (indent != 0)
    {
      cout << setw(indent) << " ";
    }
    if (aNode->GetRight())
    {
      cout << " /\n" << setw(indent) << ' ';
    }
    cout << aNode->GetToken()->GetWord() << "\n ";
    if (aNode->GetLeft())
    {
      cout << setw(indent) << ' ' << " \\\n";
      DisplayAstInConsole(aNode->GetLeft().get(), indent + 4);
    }
  }
}
void ReWriter::Serialize() const
{
}
string ReWriter::GetQuery() const
{
  string query;
  RewriteQuery(mAst.GetRoot(), query);
  return query;
}
