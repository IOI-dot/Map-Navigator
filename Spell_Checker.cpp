#include "Spell_Checker.h"
#include <vector>
#include <algorithm>
#include <climits>

SpellChecker::SpellChecker(const std::unordered_set<std::string>& dictionary)
    : dict(dictionary) {}

int SpellChecker::levenshteinDistance(const std::string& a, const std::string& b) const {
    int m = a.size();
    int n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (tolower(a[i - 1]) == tolower(b[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({ dp[i - 1][j], // Deletion
                    dp[i][j - 1], // Insertion
                    dp[i - 1][j - 1] });// Substitution
            }
        }
    }

    return dp[m][n];
}

std::string SpellChecker::findClosestMatch(const std::string& input) const {
    int minDist = INT_MAX;
    std::string best;

    for (const auto& word : dict) {
        int dist = levenshteinDistance(input, word);
        if (dist < minDist) {
            minDist = dist;
            best = word;
        }
    }

    return best;
}

