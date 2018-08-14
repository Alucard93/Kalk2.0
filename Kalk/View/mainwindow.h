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

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QVector<QString>* data;
    int numopertion;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setNumPad();
    void setOperationPad(const QVector<QString> oplist);
    void setDrop(const QVector<QString> typelist);
    void showResult(const QVector<QString> result);

public slots:
    void updateInputLineL(const QString type);
    void updateInputLineR(const QString type);
    void updateResultLine(const QString type);
    void numPadButton();
    void delButton();
    void operationPadButton();
    void resultButton();
    void togglableButton(const QString type);
    void ansButton();
    void oldButton();
    void reset();
};

#endif // MAINWINDOW_H
