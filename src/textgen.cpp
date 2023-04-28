// Copyright 2021 GHA Test Team
#include "textgen.h"

void text::read(std::string filename,
                std::map<std::string, std::vector<std::string>>& markovChain,
                int prefixLength) {
  std::ifstream file(filename);

  if (file.is_open()) {
    std::string word;

    while (file >> word) {
      if (prefix.size() < prefixLength) {
        prefix.push_back(word);
        continue;
      }
      std::string key = "";
      for (int i = 0; i < prefix.size() - 1; i++) {
        key += prefix[i] + " ";
      }
      key += prefix.back();

      markovChain[key].push_back(word);
      prefix.erase(prefix.begin());
      prefix.push_back(word);
      stop = key;
    }
    file.close();
  }
}

void text::generate(std::map<std::string, std::vector<std::string>> markovChain,
                    int prefixLength, int textLength) {
  generateText = "";
  srand(time(NULL));
  int index = rand() % markovChain.size();
  auto it = markovChain.begin();
  for (int i = 0; i < index; i++) {
    it++;
  }
  std::string key = it->first;
  generateText += key + " ";
  std::cout << key << " ";

  int i = 0;

  std::string nextWord;
  while (i < textLength - prefixLength && key != stop) {
    std::vector<std::string> possibleWords = markovChain[key];
    nextWord = possibleWords[rand() % possibleWords.size()];
    std::cout << nextWord << " ";
    generateText += nextWord;
    if (prefixLength > 1)
      key = key.substr(key.find(" ") + 1) + " " + nextWord;
    else
      key = nextWord;
    i++;
  }
  std::cout << std::endl;
}
