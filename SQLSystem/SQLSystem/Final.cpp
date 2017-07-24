#include "Final.h"

void Final::SetArguments(IToken *aTableName) {
  mArguments.push_back(aTableName);
}

CommandType Final::GetCommandType() const { return CommandType::FinalType; }

bool Final::ExpectedNext(ICommand *aNextCommand) const {
  return (aNextCommand->GetCommandType() == FinalType);
}

Final::~Final() = default;
