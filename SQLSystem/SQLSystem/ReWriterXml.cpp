#include "stdafx.h"
#include "ReWriterXml.h"
#include "AstNode.h"

vector<string> tag = { "SELECT",   " DISTINCT ", "UPDATE",  " FROM ",     " ALL ",
                       " COLUMN ", " TABLE ",    " WHERE ", "DELETE",     "INSERT",
                       "INTO",     "VALUES",     "OR",      "AND",        "LIKE",
                       "NOTLIKE",  "EQUALS",     "MINUS",   "DIVISIONOP", "MULTIPLICATIONOP",
                       "NUMBER",   "PREDICATE",  "COMA" };

void ReWriterXml::Serialize() const
{
  auto mCurrentNode = mAstTraversal.GetNextNode();
  while (mCurrentNode != nullptr)
  {
    int x = (int)mCurrentNode->GetType();
    cout << tag[x] << " ";
    mCurrentNode = mAstTraversal.GetNextNode();
  }
}
