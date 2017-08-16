#pragma once
class Position
{
public:
  Position()
    : mLine(0)
    , mColumn(0){};
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
