#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
#include "TypeDeducer.h"
#include "WriterXml.h"
#include "XmlNodeAttributes.h"

void XmlRewriter::Serialize()
{
  mXmlWr.StartDocument();
  TraverseAst(mAst.GetRoot());
  mXmlWr.EndDocument();
  mXmlWr.Write();
}

void XmlRewriter::TraverseAst(AstNode * aNode)
{
  bool hasChildren = false;
  if (aNode != nullptr)
  {
    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      hasChildren = true;
    }

    TypeDeducer typeDeducer;
    aNode->Accept(typeDeducer);
    auto nodeAttr = GetNodeAttr(aNode);

    mXmlWr.AddNode(typeDeducer.GetOutput(), hasChildren, nodeAttr);

    TraverseAst(aNode->GetLeft().get());

    TraverseAst(aNode->GetRight().get());

    if (hasChildren)
      mXmlWr.CloseNode();
  }
}

map<string, string> XmlRewriter::GetNodeAttr(AstNode * aNode)
{
  map<string, string> temp;

  temp.insert({ "Line"s, to_string(aNode->GetToken()->GetPosition().GetLine()) });
  temp.insert({ "Column"s, to_string(aNode->GetToken()->GetPosition().GetColumn()) });
  temp.insert({ "Word"s, aNode->GetToken()->GetWord() });

  return temp;
}
