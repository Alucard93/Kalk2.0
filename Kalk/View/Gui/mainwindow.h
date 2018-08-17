#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QComboBox>
#include <QVector>
#include <QButtonGroup>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QMessageBox>
#include "../view.h"

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    int numopertion;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setNumPad();
    void setOpPad(const QVector<QString> oplist);

signals:
    void typeLIsSet(QString type);
    void typeRIsSet(QString type);
    void leftValuesAreSet(QVector<QString> values);
    void rightValuesAreSet(QVector<QString> values);
    void operationIsSet(QString type);
    void reset();
    void result();
    void lastOperation();

public slots:
    void setTypeL(const QVector<QString> types);
    void setTypeR(const QVector<QString> types);
    void permittedOperations(const QVector<QString> operations);
    void resultIsSet(const QVector<QString> result);
    void ansIsSet(const QVector<QString> values);
    void init();
private slots:
    void updateInputLineL(const QString type);
    void updateInputLineR(const QString type);
    void updateResultLine(const QString type);
    void numPadButton();
    void delButton();
    void resetButton();
    void ansButton();
    void oldButton();
    void operationPadButton();
    void resultButton();

};

#endif // MAINWINDOW_H
