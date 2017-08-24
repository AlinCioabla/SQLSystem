#include "stdafx.h"
#include "AstTraversal.h"

AstNode * AstTraversal::GetNextNode()
{
  while (!stack.empty() || mCurrentNode != nullptr)
  {
    if (mCurrentNode != nullptr)
    {
      stack.push(mCurrentNode);

      auto prevNode = mCurrentNode;

      mCurrentNode = mCurrentNode->GetLeft().get();

      if (prevNode->GetToken()->GetType() == KeywordType)
      {
        return prevNode;
      }
    }
    else
    {
      mCurrentNode = stack.top();
      stack.pop();

      auto prevNode = mCurrentNode;

      mCurrentNode = mCurrentNode->GetRight().get();

      if (prevNode->GetToken()->GetType() != KeywordType)
      {
        return prevNode;
      }
    }
  }
  return nullptr;
}

void AstTraversal::ResetNext()
{
  mCurrentNode = mAst.GetRoot();
}
