#include "stdafx.h"
#include "Presenter.h"

Presenter::Presenter()
{
}

void Presenter::Present(DiagnosticInfo & aDiagInfo)
{
  switch (aDiagInfo.GetErrorCode())
  {
  case 123:
    cout << "Invalid token '" << aDiagInfo.GetWord() << "' "
         << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << endl;
    break;
  case 124:
    cout << "Tokens don't match the initial string  " << endl;
  }
}
