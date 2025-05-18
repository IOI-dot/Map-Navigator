#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <QString>
#include <QSet>

class SpellChecker {
public:
    SpellChecker(const QSet<QString>& dictionary);
    QString findClosestMatch(const QString& input) const;
    QSet<QString> dict;

private:
    int levenshteinDistance(const QString& a, const QString& b) const;
};

#endif
