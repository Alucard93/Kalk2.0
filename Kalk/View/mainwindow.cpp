#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    data= new QVector<QString>();
    numopertion= 6/*existingOperation().size();*/;
    QGridLayout* layout= new QGridLayout(this);
    layout->setObjectName("Main_Layout");

    //Drop menu creation and set
    QComboBox* drop_type1= new QComboBox(this);
    QComboBox* drop_type2= new QComboBox(this);
    drop_type1->setObjectName("Type_Left");
    drop_type2->setObjectName("Type_Right");
    layout->addWidget(drop_type1, 1, 0);
    layout->addWidget(drop_type2, 1, 1);
    //End drop menu setting

    QButtonGroup* numpad= new QButtonGroup(this);
    numpad->setObjectName("Num_Pad");

    QButtonGroup* operation= new QButtonGroup(this);
    operation->setObjectName("Op_Pad");

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setNumPad(){
    QGridLayout* layout= this->findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* numpad= this->findChild<QButtonGroup*>("Num_Pad");
    QPushButton* temp= nullptr;
    int i=0;
    for(; i<9; ++i){
        temp= new QPushButton(QChar('1'+i), this);
        temp->setObjectName(QChar('1'+i));
        temp->setFocusPolicy(Qt::NoFocus);
        numpad->addButton(temp, i+1);
        layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
        this->connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    }
    temp=new QPushButton(".", this);
    temp->setObjectName(".");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i+1);
    layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
    this->connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("0", this);
    temp->setObjectName("0");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, 0);
    layout->addWidget(numpad->button(0),3+i/3, 2+i%3);
    this->connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("<-", this);
    temp->setObjectName("<-");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 2);///////////
    this->connect(temp, SIGNAL(clicked()), this, SLOT(delButton()));
    ++i;
    temp=new QPushButton("CE", this);
    temp->setObjectName("CE");
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 3);///////////
    this->connect(temp, SIGNAL(clicked()), this, SLOT(reset()));
    ++i;
    temp=new QPushButton("ANS", this);
    temp->setObjectName("ANS");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 4);///////////
    this->connect(temp, SIGNAL(clicked()), this, SLOT(ansButton()));
    ++i;
    temp=new QPushButton("OLD", this);
    temp->setObjectName("OLD");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),1, 7);///////////
    this->connect(temp, SIGNAL(clicked()), this, SLOT(oldButton()));
}

void MainWindow::setOperationPad(const QVector<QString> oplist){
    QGridLayout* layout= this->findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* operation= this->findChild<QButtonGroup*>("Op_Pad");
    QPushButton* button= nullptr;
    for(int i=0; i<numopertion; i++){
        button= new QPushButton(oplist[i], this);
        button->setObjectName(oplist[i]);
        operation->addButton(button, i);
        layout->addWidget(operation->button(i),2+i/2, 5+i%2);
        this->connect(operation->button(i), SIGNAL(clicked()), this, SLOT(operationPadButton()));
    }
    button= new QPushButton("=", this);
    button->setObjectName("=");
    operation->addButton(button, oplist.size()+1);
    layout->addWidget(operation->button(oplist.size()+1),2+(oplist.size())/2, 5+(oplist.size())%2);
    this->connect(operation->button(oplist.size()+1), SIGNAL(clicked()), this, SLOT(resultButton()));
}

void MainWindow::setDrop(const QVector<QString> typelist){
    for(int i=0; i!=typelist.size(); i++){
        this->findChild<QComboBox*>("Type_Left")->addItem(typelist[i]);
        this->findChild<QComboBox*>("Type_Right")->addItem(typelist[i]);
    }
}

void MainWindow::showResult(const QVector<QString> result){
    int i=0;
    while(this->findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        this->findChild<QLineEdit*>("Result_Line"+QString('0'+i))->setText(result[i]);
        i++;
    }
}

////SLOT////

void MainWindow::updateInputLineL(const QString type){
    QGridLayout* layout= this->findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))!=nullptr){
        temp= this->findChild<QLineEdit*>("Data_Line_L"+QString('0'+i));
        delete temp;
        ++i;
    }
    for(i=0; i</*int num_data_type(type)*/3; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Data_Line_L"+QString('0'+i));
        temp->setValidator(new QDoubleValidator(temp));
        layout->addWidget(temp,2+i,0);
    }
}

void MainWindow::updateInputLineR(const QString type){
    QGridLayout* layout= this->findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))!=nullptr){
        temp= this->findChild<QLineEdit*>("Data_Line_R"+QString('0'+i));
        delete temp;
        i++;
    }
    for(i=0; i</*int num_data_type(type)*/2; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Data_Line_R"+QString('0'+i));
        temp->setValidator(new QDoubleValidator(temp));
        layout->addWidget(temp,2+i,1);
    }
}

void MainWindow::updateResultLine(const QString type){
    QGridLayout* layout= this->findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        temp= this->findChild<QLineEdit*>("Result_Line"+QString('0'+i));
        delete temp;
        i++;
    }
    for(i=0; i</*int num_data_type(type)*/3; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Result_Line"+QString('0'+i));
        temp->setAlignment(Qt::AlignRight);
        temp->setPlaceholderText("Result");
        temp->setReadOnly(true);
        layout->addWidget(temp, 2+i, 7);
    }
}

void MainWindow::numPadButton(){
    QWidget* focus= this->focusWidget();
    QPushButton* bs = qobject_cast<QPushButton*>(sender());
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->insert(bs->text());
    }
}

void MainWindow::delButton(){
    QWidget* focus= this->focusWidget();
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->backspace();
    }
}

void MainWindow::operationPadButton(){
    data->clear();
    int i=0;
    while(this->findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    QPushButton* bs = qobject_cast<QPushButton*>(sender());
    for(int j=0; j<i; ++j){
        templine= this->findChild<QLineEdit*>("Data_Line_L"+QString('0'+j));
        data->append(templine->text());
    }
    if(!data->isEmpty())
        data->append(bs->text());
}

void MainWindow::resultButton(){
    if(!data->isEmpty()){
    int i=0;
    while(this->findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    for(int j=0; j<i; ++j){
        templine= this->findChild<QLineEdit*>("Data_Line_R"+QString('0'+j));
        data->append(templine->text());
    }
    //Send_Data(QVector<QString> data);
    }
}

void MainWindow::togglableButton(const QString type){
    QVector<QString> oppermitted(2,"+")/*permitted_operation(type)*/;
    QButtonGroup* operation= this->findChild<QButtonGroup*>("Op_Pad");
    bool finded;
    for(int j=0; j<numopertion; ++j){
        operation->button(j)->setEnabled(false);
        dynamic_cast<QPushButton*>(operation->button(j))->setFlat(true);
    }
    for(int i=0; i<oppermitted.size(); ++i){
        finded= false;
        for(int j=0; j<numopertion && !finded; ++j){
            if(operation->button(j)->text()==oppermitted[i]){
                finded= true;
                operation->button(j)->setEnabled(true);
                dynamic_cast<QPushButton*>(operation->button(j))->setFlat(false);
            }
        }
    }
}

void MainWindow::ansButton(){
    QComboBox* left= this->findChild<QComboBox*>("Type_Left");
    QVector<QString> lastop{"color", "00", "00", "00"};//= lastOperationResult();
    left->setCurrentIndex(left->findText(lastop[0]));
    left->activated(lastop[0]);
    for(int i=1; i<lastop.size(); i++){
        this->findChild<QLineEdit*>("Data_Line_L"+QString('0'+(i-1)))->insert(lastop[i]);
    }
}

void MainWindow::oldButton(){
    QLineEdit* old= new QLineEdit();
    old->setReadOnly(true);
    old->setText("test");
    //todo
    old->show();
}

void MainWindow::reset(){
    qDeleteAll(this->findChildren<QLineEdit*>());
}
