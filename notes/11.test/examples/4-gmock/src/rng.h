#pragma once

class RandomNumberGenerator {
public:
  virtual int uniform() = 0;
  virtual ~RandomNumberGenerator() = default;
};
