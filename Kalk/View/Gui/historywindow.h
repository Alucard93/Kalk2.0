/**
 * @file historywindow.h
 * @author Gianmarco Pettinato
 * @date 1/09/2018
 * @brief shows the history.
 *
 * */
#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include <QWidget>
#include <QComboBox>
#include <QVector>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
#include <QErrorMessage>

class HistoryWindow : public QWidget
{
    Q_OBJECT
public:
    HistoryWindow(const QVector<QVector<QString>>& history, QWidget *parent = nullptr);
    ~HistoryWindow();
public slots:
    void changeOp(int operation);
    void addMenuHistory();
private:
    QVector<QVector<QString>> l_history;
    QVector<QLabel*> glines;
};

#endif // HISTORYWINDOW_H
