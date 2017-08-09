#pragma once

class SQLSystem
{
public:
  SQLSystem(string aInputFile);

  bool ExecuteQuery();

  ~SQLSystem();

private:
  string mInputFile;
};
