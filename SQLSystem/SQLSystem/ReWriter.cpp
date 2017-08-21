#include "stdafx.h"
#include "ReWriter.h"

void ReWriter::RewriteQuery(AstNode * aNode)
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      mAstQuery += aNode->GetToken()->GetWord();
      mAstQuery += " ";
    }
    RewriteQuery(aNode->GetLeft().get());
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      mAstQuery += aNode->GetToken()->GetWord();
      mAstQuery += " ";
    }
    RewriteQuery(aNode->GetRight().get());
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
string ReWriter::GetQuery()
{
  if (!mAstQuery.size())
  {
    RewriteQuery(mAst.GetRoot());
  }

  return mAstQuery;
}

ReWriter::~ReWriter()
{
}
