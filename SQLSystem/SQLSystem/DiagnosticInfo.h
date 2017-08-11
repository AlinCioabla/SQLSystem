#pragma once
class DiagnosticInfo
{
public:
  DiagnosticInfo(int aLine, int aColumn)
    : mLine(aLine)
    , mColumn(aColumn){};

  void Increment(char c);

  int GetLine() { return mLine; };
  int GetColumn() { return mColumn; };

  ~DiagnosticInfo() = default;

private:
  int mLine;
  int mColumn;
};
