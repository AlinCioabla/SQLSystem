#pragma once
#include "stdafx.h"
#include "IPresenter.h"

class FilePresenter : public IPresenter
{
public:
  FilePresenter(string & aFile)
    : mFile(aFile){

    };
  void Present(DiagnosticInfo & aDiagInfo) const override;
  virtual ~FilePresenter() = default;

private:
  string mFile;
};
