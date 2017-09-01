#pragma once
#include "IBuffer.h"
class BufferXml : public IBuffer
{
public:
  BufferXml() = default;

  void   Update(string aCommand) override;
  string Get() override;

  virtual ~BufferXml() = default;

private:
  string mBufferString;
};
