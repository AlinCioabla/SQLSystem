#pragma once
#include "stdafx.h"
#include "IPresenter.h"

class FilePresenter : public IPresenter
{
public:
  FilePresenter(string & aFile) { mFile.open(aFile, ios::out | ios::ate | ios::app); };
  void Present(DiagnosticInfo & aDiagInfo) override;
  virtual ~FilePresenter() = default;

private:
  ofstream mFile;
};
