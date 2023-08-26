#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "blokWidget.h"
#include "color_dialog.h"
#include "edycja_kursow.h"
#include "edycja_prowadzacych.h"
#include "filtry.h"
#include "kursy_grupy_bloki.h"
#include "login_window.h"
#include "poboczneDopasowywanie.h"
#include "poboczneTerminy.h"
#include "treeWidgetItem.h"
#include <QCheckBox>
#include <QColorDialog>
#include <QEvent>
#include <QFile>
#include <QFileDialog>
#include <QFutureWatcher>
#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QProgressBar>
#include <QProgressDialog>
#include <QSplitter>
#include <QTextStream>
#include <QToolBar>
#include <QTreeWidget>
#include <QtAlgorithms>
#include <QtConcurrent>
#include <random>

class CheckBox;
class Window : public QMainWindow
{
    Q_OBJECT
  public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    QSplitter *splitter;
    QGridLayout *siatka;
    QTreeWidget *tree;
    /***********MENU*************/
    QMenuBar *menu;
    void ustawMenu();
    QMenu *ustawMenuPlik();
    QMenu *ustawMenuEdycja();
    QMenu *ustawMenuWidok();

    /****************************/
    /************SIATKA**********/
    QList<QFrame *> ver;
    QList<QFrame *> hor;
    void drawGridV(int rows, int columnms);
    void drawGridH(int rows, int columnms);
    void drawCourse(int row, int tydzien, int column, int length, QString grupa,
                    QString text, QColor color, QColor fcolor, QString kKursu,
                    QString czas, QString prowadzacy);
    void raiseHorizontalLines();
    void ustawDzienNaSiatce(QString dzien, int row, int col, int rowSpan,
                            int colSpan);
    void ustawGodzinyNaSiatceV();
    void ustawGodzinyNaSiatceH();
    /***************************/

    /*****WYBOR KURSU*********/
    void odznaczWTablicy(int start, int len, int dzien, bool typ, int tydzien);
    bool CzyPozycjaWolna(int start, int len, int dzien, int tydzien);
    void ZablokujNakladajace();
    void ZmienPotomkow();
    void filtry();
    bool SprawdzPotok(const QString &potok, const QString &kodKursu,
                      QTreeWidgetItem *wybrany) const;
    bool porownajGodziny(QString g1, QString g2);
    bool porownajGodziny2(QString g1, QString g2);
    FiltryDialog *filtrowanie;
    bool tablicaCzasu[2][5][180];
    /**************************/

    /*******DRZEWO***********/
    void build_tree();
    void update_tree();
    TreeWidgetItem *add_parent(Kurs a);
    void add_child(TreeWidgetItem *treeItem, Kurs a);
    void add_branch(int ilosc);
    void Przedmioty();
    void reload();
    QList<QString> zapamietajWybraneKursy();
    void wczytajWybraneKursy(const QList<QString> &stareKody);
    void zapiszPlanTymczasowoAction();
    void wczytajTymczasowyPlanAction();
    /**************************/

    void WczytywanieEduAKZ(const QList<Kurs> &lista);
    void przypisz_prowadzacego(QList<Kurs> &lista);

    /***********WIDOK*********/
    void rozdajKolory(QString l, QColor &clr, QColor &fclr);
    void UpdateColors();
    void przepiszKolory(PickColors *p);
    QList<QList<Kurs>> zwrocListeNajmniejszych(QList<QString> kod);
    void zaznaczKurs(QString kodKursu, QString kodGrupy);
    PickColors *pick;
    WybraneKolory kolory;
    /**************************/

    QList<Kurs> kursy;
    QList<QList<Kurs>> przedmioty;
    QList<Prowadzacy> prow;
    QList<BlokWidget *> naSiatce;
    QList<QPair<CheckBox *, QTreeWidgetItem *>> wybraneZajecia;
    QList<QString> ukryjTerminy;
    QList<QString> tymczasowoZapisane;

  public slots:
    void ZmienKolory();
    void Zaznaczono();
    void TreeHeaderClicked(QTreeWidgetItem *parent);
    /*****ZAPISZ/WCZYTAJ********/
    void wczytajPlan();
    void wczytajPlanKolegi();
    void zapiszPlan();
    void wczytajKursyZPliku();
    void wczytajKursyZEdukacji();
    void wczytajKursyZAKZ();
    void wczytajProwadzacychZPliku();
    void wczytajProwadzacychZPolwro();
    void ZapiszKursy();
    void ZapiszProwadzacych();
    /**************************/
    void odznaczZaznaczone();
    void PrzelaczWidok();
    void losujPlan();
};

class CheckBox : public QCheckBox
{
  public:
    CheckBox(QWidget *parent = 0) : QCheckBox(parent) {}
    ~CheckBox(){};
    TreeWidgetItem *treeItem;
};

#endif
