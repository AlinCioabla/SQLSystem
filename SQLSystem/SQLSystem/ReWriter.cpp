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

ReWriter::~ReWriter()
{
}
