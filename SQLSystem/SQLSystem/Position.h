#pragma once
class Position
{
public:
  Position() = default;
  Position(int aLine, int aColumn)
    : mLine(aLine)
    , mColumn(aColumn){};

  void IncrementLine();
  void IncrementColumn();

  int GetLine() { return mLine; };
  int GetColumn() { return mColumn; };

  ~Position() = default;

private:
  int mLine;
  int mColumn;
};
