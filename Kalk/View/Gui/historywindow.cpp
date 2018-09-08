#include "historywindow.h"

/**
 * @brief HistoryWindow::HistoryWindow
 * @param history
 * @param parent
 */
HistoryWindow::HistoryWindow(const QVector<QVector<QString>>& history, QWidget *parent):QWidget(parent)
{
    l_history = history;
    if(!l_history.empty()){
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
        setAttribute(Qt::WA_DeleteOnClose);
        show();
        addMenuHistory();
    }else{
        QErrorMessage * error = new QErrorMessage(this);
        error->showMessage("Non ci sono elementi da visualizzare");
    }
}

/**
 * @brief HistoryWindow::~HistoryWindow
 */
HistoryWindow::~HistoryWindow(){
    QComboBox* operations=findChild<QComboBox*>("history_menu");
    QObject::disconnect(operations,SIGNAL(activated(int)),this,SLOT(changeOp(int)));
    QObjectList children = this->children();
    QVector<QObject*> toDelete = children.toVector();
    QObject* child;
    foreach(child,toDelete)
        delete child;
}

/**
 * @brief HistoryWindow::addMenuHistory add entries
 */
void HistoryWindow::addMenuHistory(){
    QComboBox* operations=findChild<QComboBox*>("history_menu");
    operations->clear();
    int sizeH = l_history.size();
    while (sizeH>0) {
        operations->addItem("Operazione n."+QString::number(sizeH));
        sizeH--;
    }
    changeOp(0);

}

/**
 * @brief HistoryWindow::changeOp changes the window's content
 * @param operation
 */
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
