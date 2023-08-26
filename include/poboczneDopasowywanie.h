#ifndef POBOCZNEDOPASOWYWANIE_H
#define POBOCZNEDOPASOWYWANIE_H
#include "kursy_grupy_bloki.h"
#include <QList>
#include <QPair>
#include <QString>
#include <QVector>

void dopasuj(Kurs &a, QList<Prowadzacy> prow);
void usun_przedrostki(QString &line);
bool deleteWord(QString &line, const QString &word);
int levenshtein_distance(const QString &s1, const QString &s2);
#endif
