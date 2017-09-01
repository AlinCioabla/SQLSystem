#pragma once
class IBuffer
{
public:
  virtual void   Update(string aCommand) = 0;
  virtual string Get()                   = 0;

  virtual ~IBuffer() = default;
};
