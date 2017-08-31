#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
#include "TypeDeducer.h"
#include "WriterXml.h"
#include "XmlNodeAttributes.h"

void XmlRewriter::Serialize()
{
  mXmlWr.Init();
  TraverseAst(mAst.GetRoot());
  mOutputStream << endl << endl;
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

    mXmlWr.AddNode(typeDeducer.GetOutput(), aNode->GetToken()->GetPosition().GetLine(),
                   aNode->GetToken()->GetPosition().GetColumn(), aNode->GetToken()->GetWord(),
                   hasChildren);

    TraverseAst(aNode->GetLeft().get());

    TraverseAst(aNode->GetRight().get());

    mXmlWr.CloseNode(typeDeducer.GetOutput(), hasChildren);
  }
}
