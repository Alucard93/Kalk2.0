#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include <QWidget>
#include <QComboBox>
#include <QVector>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
#include <iostream>

class HistoryWindow : public QWidget
{
    Q_OBJECT
public:
    HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();
public slots:
    void changeOp(int operation);
    void addMenuHistory(const QVector<QVector<QString>>& history);
private:
    QVector<QVector<QString>> l_history;
    QVector<QLabel*> glines;
};

#endif // HISTORYWINDOW_H
