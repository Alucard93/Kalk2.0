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

class MainWindow :  public View, public QWidget
{
    Q_OBJECT

private:
    int numopertion;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setNumPad();
    void setAvailableOperations(const QVector<QString> oplist);
    void setAvailableTypes(const QVector<QString> typelist);
    void setResult(const QVector<QString> result);
    void show();

signals:
    void setTypeL(QString type);
    void setTypeR(QString type);
    void setOperation(QString type);
    void existingOperation();
    void permittedOperation(QString type);
    void result();

public slots:
    void getTypeL();
    void getTypeR();
    void getOperation();
    void getPermittedOperation();
    void getResult();

private slots:
    void numPadButton();
    void delButton();
    void operationPadButton();
    void resultButton();
    void togglableButton(const QString type);
    void ansButton();
    void oldButton();
    void reset();
    //?
    void updateInputLineL(const QString type);
    void updateInputLineR(const QString type);
    void updateResultLine(const QString type);
    //?
};

#endif // MAINWINDOW_H
