#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"

Ast::Ast()
{
  mRoot = nullptr;
}

void Ast::ConstructQueryFromAst(AstNode * aNode)
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      mAstQuery += aNode->GetToken()->GetWord();
      mAstQuery += " ";
    }
    ConstructQueryFromAst(aNode->GetLeft().get());
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      mAstQuery += aNode->GetToken()->GetWord();
      mAstQuery += " ";
    }
    ConstructQueryFromAst(aNode->GetRight().get());
  }
}

void Ast::SetRoot(AstNodePtr aNode)
{
  if (mRoot == nullptr)
  {
    mRoot = move(aNode);
  }
}

void Ast::InsertLeft(AstNodePtr & aNode, TokenPtr & aToken, AstNodeType aType)
{
  if (aNode != nullptr)
  {
    auto temp = aNode->GetLeft();
    aNode->SetLeft(Ast::GetNewNode(aToken, aType));
    aNode->GetLeft()->SetLeft(temp);
  }
}

void Ast::InsertRight(AstNodePtr & aNode, TokenPtr & aToken, AstNodeType aType)
{
  if (aNode != nullptr)
  {
    auto temp = aNode->GetRight();
    aNode->SetRight(Ast::GetNewNode(aToken, aType));
    aNode->GetRight()->SetRight(temp);
  }
}

IToken * Ast::GetLastAddedToken(AstNodePtr & aNode) const
{
  if (!aNode)
  {
    return nullptr;
  }

  auto _prevTokenNode = aNode->GetLeft();
  if (_prevTokenNode == nullptr)
  {
    return aNode->GetToken();
  }

  while (_prevTokenNode->GetRight() != nullptr)
  {
    _prevTokenNode = _prevTokenNode->GetRight();
  }
  return _prevTokenNode->GetToken();
}

AstNodePtr Ast::GetCurrentInstr() const
{
  if (!mRoot)
  {
    return nullptr;
  }
  auto _tempNode = mRoot;

  while (_tempNode->GetRight() != nullptr)
  {
    _tempNode = _tempNode->GetRight();
  }
  return _tempNode;
}

Ast::~Ast() = default;
