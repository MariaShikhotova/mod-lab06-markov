// Copyright 2021 GHA Test Team
#pragma once
#include <stdexcept>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

class text {
 public:
  void read(std::string filename,
            std::map<std::string, std::vector<std::string>>& markovChain,
            int prefixLength);
  void generate(std::map<std::string, std::vector<std::string>> markovChain,
                int prefixLength, int textLength);
  std::vector<std::string> prefix;
  std::string stop;
  std::string generateText;
};
