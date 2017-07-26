#include "Ast.h"
#include "AstNode.h"

Ast::Ast(const Ast & aAst)
{
  mRoot = aAst.GetRoot();
}

Ast::Ast()
{
  mRoot = nullptr;
}

void Ast::Display(AstNode * aNode, int indent) const
{
  if (aNode != nullptr)
  {
    if (aNode->GetRight())
    {
      Display(aNode->GetRight(), indent + 4);
    }
    if (indent)
    {
      cout << setw(indent) << " ";
    }
    if (aNode->GetRight())
      cout << " /\n" << setw(indent) << ' ';
    cout << aNode->GetToken()->GetWord() << "\n ";
    if (aNode->GetLeft())
    {
      cout << setw(indent) << ' ' << " \\\n";
      Display(aNode->GetLeft(), indent + 4);
    }
  }
}

void Ast::PrintQuery(AstNode * aNode)
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      cout << aNode->GetToken()->GetWord() << " ";
    }
    PrintQuery(aNode->GetLeft());
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      cout << aNode->GetToken()->GetWord() << " ";
    }
    PrintQuery(aNode->GetRight());
  }
}

// string Ast::GetQuery(AstNode * aNode) const
//{
//  string query;
//  if (aNode != nullptr)
//  {
//    if (aNode->GetToken()->GetType() == KeywordType)
//    {
//      query += aNode->GetToken()->GetWord();
//      query += " ";
//    }
//    GetQuery(aNode->GetLeft());
//    if (aNode->GetToken()->GetType() != KeywordType)
//    {
//      query += aNode->GetToken()->GetWord();
//      query += " ";
//    }
//    GetQuery(aNode->GetRight());
//  }
//}

void Ast::SetRoot(AstNode * aNode)
{
  if (mRoot == nullptr)
  {
    mRoot = aNode;
  }
}

Ast::~Ast()
{
  delete mRoot;
}
