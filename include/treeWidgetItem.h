#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H
#include "kursy_grupy_bloki.h"
#include <QTreeWidgetItem>

class TreeWidgetItem : public QTreeWidgetItem
{
  public:
    TreeWidgetItem(QTreeWidget *parent);
    TreeWidgetItem(TreeWidgetItem *parent);
    ~TreeWidgetItem() {}
    void setKodTermin(const QString &k);
    void setSchowany(const bool &p);
    void setKurs(const Kurs &kr);
    bool schowany() const;
    QString kodTermin() const;
    Kurs kurs() const;

  private:
    bool operator<(const QTreeWidgetItem &other) const;
    QString Termin;
    bool Schowany;
    Kurs k;
};

#endif
