#pragma once
#include "IBuffer.h"
class BufferXml : public IBuffer
{
public:
  BufferXml() = default;

  void           Update(string aCommand) override;

  void           Clear() override;

  string Get() override;

  virtual ~BufferXml() = default;

  BufferXml & operator<<(const string & str)
  {
    mBufferString += str;
    return *this;
  }

  template <typename T>
  BufferXml & operator<<(T val)
  {
    mBufferString += to_string(val);
    return *this;
  }

  template <>
  BufferXml & operator<<(const char * buff)
  {
    *this << string(buff);
    return *this;
  }

  BufferXml & operator<<(bool boolean)
  {
    *this << (int)boolean;
    return *this;
  }

private:
  string mBufferString;
};
