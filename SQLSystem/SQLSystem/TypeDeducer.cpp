#include "stdafx.h"
#include "TypeDeducer.h"

TypeDeducer::TypeDeducer()
{
}

void TypeDeducer::Visit(SelectNode & aSelectNode)
{
  mOutput = "SELECT";
}
