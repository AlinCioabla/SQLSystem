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
  Position(const Position & aPosition);
  Position & operator=(const Position & aPosition);

  void IncrementLine();
  void IncrementColumn();

  int GetLine() const { return mLine; };
  int GetColumn() const { return mColumn; };

  ~Position() = default;

private:
  int mLine;
  int mColumn;
};
