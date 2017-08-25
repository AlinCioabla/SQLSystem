#include "stdafx.h"
#include "TextRewriter.h"

void TextRewriter::TraverseTree(AstNode * aNode, string & aAstQuery) const
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      aAstQuery += aNode->GetToken()->GetWord();
      aAstQuery += " ";
    }
    TraverseTree(aNode->GetLeft().get(), aAstQuery);
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      aAstQuery += aNode->GetToken()->GetWord();
      aAstQuery += " ";
    }
    TraverseTree(aNode->GetRight().get(), aAstQuery);
  }
}

void TextRewriter::Serialize()
{
  string tempQuery;
  TraverseTree(mAst.GetRoot(), tempQuery);
  mOutputStream << tempQuery;
  mOutputStream << endl << endl;
}

void TextRewriter::DisplayAstInConsole(AstNode * aNode, int indent) const
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
string TextRewriter::GetQuery() const
{
  string tempQuery;
  TraverseTree(mAst.GetRoot(), tempQuery);
  return tempQuery;
}

// void ReWriter::Serialize() const
//{
//  stack<AstNode *> stack;
//
//  AstNode * curr = mAst.GetRoot();
//
//  while (!stack.empty() || curr != nullptr)
//  {
//    if (curr != nullptr)
//    {
//      stack.push(curr);
//      if (curr->GetToken()->GetType() == KeywordType)
//        cout << curr->GetToken()->GetWord() << " ";
//      curr = curr->GetLeft().get();
//    }
//    else
//    {
//      curr = stack.top();
//      stack.pop();
//
//      if (curr->GetToken()->GetType() != KeywordType)
//        cout << curr->GetToken()->GetWord() << " ";
//
//      curr = curr->GetRight().get();
//    }
//  }
//  cout << endl;
//}