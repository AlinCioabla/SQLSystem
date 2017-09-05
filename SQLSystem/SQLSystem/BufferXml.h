#pragma once
#include "IBuffer.h"
class BufferXml : public IBuffer
{
public:
  BufferXml() = default;

  void           Update(string aCommand) override;
  const string & Get() const override;
  void           Clear() override;

  virtual ~BufferXml() = default;

  BufferXml & operator<<(const string & str)
  {
    mBufferString += str;
    return *this;
  }

  template <typename T>
  BufferXml & operator<<(T val)
  {
    mBufferString += to_string(value);
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
