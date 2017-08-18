#pragma once
#include "IPresenter.h"
class FilePresenter : public IPresenter
{
public:
  FilePresenter(ofstream & aFile)
    : mFile(aFile){};
  void Present(DiagnosticInfo & aDiagInfo) const override;
  virtual ~FilePresenter() = default;
  ofstream & mFile;
};
