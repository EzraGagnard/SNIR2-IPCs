#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
  /*  void afficherInfos();
        double poids;
        double taille;
        QString nom;
        QString prenom;
        int age;
        static const int NBIMC=6;
        static const int NBCORPULENCE=7;
*/
        void on_pushButtonSuite_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
