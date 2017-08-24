#include "stdafx.h"
#include "ReWriterXml.h"
#include "AstNode.h"

vector<string> tag = { "SELECT",     "DISTINCT ",
                       "COMMA",      "FROM",
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
                       "UPDATE",     "INVALID" };

vector<string> type = {
  "KeywordType",    "OperatorType", "PunctuationType", "WhiteSpaceType",
  "IdentifierType", "NumberType",   "PredicateType",   "TextualOperatorType"
};

void ReWriterXml::Serialize() const
{
  TraverseAst(mAst.GetRoot());
}

void ReWriterXml::TraverseAst(AstNode * aNode, int indent) const
{
  if (aNode != nullptr)
  {
    cout << setw(indent) << "<" << tag[aNode->GetToken()->GetType()] << " at='line "
         << aNode->GetToken()->GetPosition().GetLine() << ", column "
         << aNode->GetToken()->GetPosition().GetColumn() << "' Type='"
         << type[aNode->GetToken()->GetType()] << "'"
         << ">\n";

    TraverseAst(aNode->GetLeft().get(), indent + 3);

    TraverseAst(aNode->GetRight().get(), indent + 3);

    cout << setw(indent) << "<\\" << tag[aNode->GetToken()->GetType()] << ">\n";
  }
}
