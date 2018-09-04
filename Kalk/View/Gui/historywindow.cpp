#include "historywindow.h"

HistoryWindow::HistoryWindow(QWidget *parent):QWidget(parent)
{
    glines={};
    QGridLayout* layout= new QGridLayout(this);
    layout->setObjectName("History_Layout");
    setLayout(layout);
    setWindowTitle("Cronologia di Kalk");

    QComboBox* operations= new QComboBox(this);
    operations->setObjectName("history_menu");
    layout->addWidget(operations, 1, 0);
    operations->move(30,2);
    resize(300,200);
    QObject::connect(operations,SIGNAL(activated(int)),this,SLOT(changeOp(int)));
    show();
}

HistoryWindow::~HistoryWindow(){

}

void HistoryWindow::addMenuHistory(const QVector<QVector<QString>>& history){
    l_history = history;
    QComboBox* operations=findChild<QComboBox*>("history_menu");
    operations->clear();
    int sizeH = l_history.size();
    while (sizeH>0) {
        operations->addItem("Operazione n."+QString::number(sizeH));
        sizeH--;
    }
    changeOp(0);

}

void HistoryWindow::changeOp(int operation){
    QLayout* layout=findChild<QGridLayout*>("History_Layout");
    QString line;
    QLabel* label;
    foreach(label,glines){
        layout->removeWidget(label);
        delete label;
    }
    glines={};
    foreach(line,l_history[operation]){
        glines.push_back(new QLabel(line,this));
        layout->addWidget(glines.last());
    }

}
