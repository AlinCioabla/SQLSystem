#include "Begin.h"

CommandType Begin::GetCommandType() const { return CommandType::BeginType; }

bool Begin::ExpectedNext(ICommand *aNextCommand) const {
  return (aNextCommand->GetCommandType() == BeginType ||
          aNextCommand->GetCommandType() == IntermediarType);
}

Begin::~Begin() {}
