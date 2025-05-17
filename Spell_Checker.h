#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <string>
#include <unordered_set>

class SpellChecker {
public:
    SpellChecker(const std::unordered_set<std::string>& dictionary);

    std::string findClosestMatch(const std::string& input) const;
private:
    int levenshteinDistance(const std::string& a, const std::string& b) const;

    std::unordered_set<std::string> dict;
};

#endif
