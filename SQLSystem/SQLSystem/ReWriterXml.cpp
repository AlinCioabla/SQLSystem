#include "stdafx.h"
#include "ReWriterXml.h"
#include "AstNode.h"

vector<string> tag = { "SELECT",     "DISTINCT ",
                       "UPDATE",     "FROM ",
                       "ALL",        "COLUMN ",
                       "TABLE",      "WHERE ",
                       "DELETE",     "INSERT",
                       "INTO",       "VALUES",
                       "VALUE",      "OR",
                       "AND",        "LIKE",
                       "NOTLIKE",    "EQUALS",
                       "PLUSOP",     "MINUS",
                       "DIVISIONOP", "MULTIPLICATIONOP",
                       "NUMBER",     "PREDICATE",
                       "COMMA",      "INVALID" };

vector<string> type = {
  "KeywordType",    "OperatorType", "PunctuationType", "WhiteSpaceType",
  "IdentifierType", "NumberType",   "PredicateType",   "TextualOperatorType"
};

void ReWriterXml::Serialize() const
{
  auto mCurrentNode = mAstTraversal.GetNextNode();
  while (mCurrentNode != nullptr)
  {
    cout << "<" << tag[(int)mCurrentNode->GetType()] << " at='line "
         << mCurrentNode->GetToken()->GetPosition().GetLine() << ", column "
         << mCurrentNode->GetToken()->GetPosition().GetColumn() << "' Type='"
         << type[(int)mCurrentNode->GetToken()->GetType()] << "'"
         << ">" << mCurrentNode->GetToken()->GetWord() << "</" << tag[(int)mCurrentNode->GetType()]
         << ">" << endl;

    mCurrentNode = mAstTraversal.GetNextNode();
  }
}
