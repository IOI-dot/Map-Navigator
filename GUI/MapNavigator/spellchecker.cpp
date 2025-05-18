#include "spellchecker.h"
#include <algorithm>
#include <climits>

SpellChecker::SpellChecker(const QSet<QString>& dictionary)
    : dict(dictionary) {}

int SpellChecker::levenshteinDistance(const QString& a, const QString& b) const {
    int m = a.size();
    int n = b.size();
    QVector<QVector<int>> dp(m + 1, QVector<int>(n + 1));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1].toLower() == b[j - 1].toLower()) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
    }

    return dp[m][n];
}

QString SpellChecker::findClosestMatch(const QString& input) const {
    int minDist = INT_MAX;
    QString best;

    for (const QString& word : dict) {
        int dist = levenshteinDistance(input, word);
        if (dist < minDist) {
            minDist = dist;
            best = word;
        }
    }

    return best;
}
