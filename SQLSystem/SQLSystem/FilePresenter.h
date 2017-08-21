#pragma once

#include "IPresenter.h"

class FilePresenter : public IPresenter
{
public:
  FilePresenter(string aFile)
    : mOutputFile(aFile, ios::out | ios::ate | ios::app)
  {
  }

  void Present(DiagnosticInfo & aDiagInfo) override;
  virtual ~FilePresenter() = default;

private:
  ofstream mOutputFile;
};
