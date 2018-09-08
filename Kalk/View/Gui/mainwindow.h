/**
 * @file mainwindows.h
 * @author Giuseppe Vito Bitetti
 * @date 20/7/2018
 * @class MainWindows
 * @brief this class uses as base the class View
 * MainWindows uses the qt libraries for the GUI
*/
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
#include <QErrorMessage>
#include <QAbstractScrollArea>
#include <QSizePolicy>
#include "./historywindow.h"
#include "../view.h"

class MainWindow : public View
{
    Q_OBJECT

private:
    int numopertion;
    int leftfields;
    int rightfields;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setLeftTypes(const QVector<QString> types);
    void setRightTypes(const QVector<QString> types);
    void setResultTypes(const QVector<QString> types);
    void setLeftFields(const int& fields,const QVector<QString>& limits);
    void setRightFields(const int& fields,const QVector<QString>& limits);
    void setResultFields(const int& fields);
    void setAvailableOperations(const QVector<QString> operations);
    void setPermittedOperations(const QVector<QString> operations);
    void setResult(const QVector<QString> result);
    void setNumPad();
    void setHistory(const QVector<QVector<QString>>& history);
    void error(const QString& error_message);
    void resetType(QString drop, QString type);
    void show();
private slots:
    void numPadButton();
    void delButton();
    void resetButton();
    void oldButton();
    void operationPadButton();
    void resultButton();
    void leftType(QString type);
    void rightType(QString type);
    void resultType(QString type);

};

#endif // MAINWINDOW_H
