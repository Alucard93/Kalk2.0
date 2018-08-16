#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){

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

    QButtonGroup* numpad= new QButtonGroup(dynamic_cast<QWidget*>(this));
    numpad->setObjectName("Num_Pad");

    QButtonGroup* operation= new QButtonGroup(dynamic_cast<QWidget*>(this));
    operation->setObjectName("Op_Pad");

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setNumPad(){
    QGridLayout* layout= this->QWidget::findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* numpad= this->QWidget::findChild<QButtonGroup*>("Num_Pad");
    QPushButton* temp= nullptr;
    int i=0;
    for(; i<9; ++i){
        temp= new QPushButton(QChar('1'+i), dynamic_cast<QWidget*>(numpad));
        temp->setObjectName(QChar('1'+i));
        temp->setFocusPolicy(Qt::NoFocus);
        numpad->addButton(temp, i+1);
        layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
        this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(numPadButton()));
    }
    temp=new QPushButton(".", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName(".");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i+1);
    layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("0", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName("0");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, 0);
    layout->addWidget(numpad->button(0),3+i/3, 2+i%3);
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("<-", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName("<-");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 2);///////////
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(delButton()));
    ++i;
    temp=new QPushButton("CE", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName("CE");
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 3);///////////
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(reset()));
    ++i;
    temp=new QPushButton("ANS", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName("ANS");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 4);///////////
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(ansButton()));
    ++i;
    temp=new QPushButton("OLD", dynamic_cast<QWidget*>(numpad));
    temp->setObjectName("OLD");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),1, 7);///////////
    this->QWidget::connect(temp, SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(oldButton()));
}
/*
void MainWindow::setAvailableOperations(const QVector<QString> oplist){
    QGridLayout* layout= this->QWidget::findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* operation= this->QWidget::findChild<QButtonGroup*>("Op_Pad");
    QPushButton* button= nullptr;
    for(int i=0; i<numopertion; i++){
        button= new QPushButton(oplist[i], dynamic_cast<QWidget*>(operation));
        button->setObjectName(oplist[i]);
        operation->addButton(button, i);
        layout->addWidget(operation->button(i),2+i/2, 5+i%2);
        this->QWidget::connect(operation->button(i), SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(operationPadButton()));
    }
    button= new QPushButton("=", dynamic_cast<QWidget*>(operation));
    button->setObjectName("=");
    operation->addButton(button, oplist.size()+1);
    layout->addWidget(operation->button(oplist.size()+1),2+(oplist.size())/2, 5+(oplist.size())%2);
    this->QWidget::connect(operation->button(oplist.size()+1), SIGNAL(clicked()), dynamic_cast<QWidget*>(this), SLOT(resultButton()));
}

void MainWindow::setAvailableTypes(const QVector<QString> typelist){
    for(int i=0; i!=typelist.size(); i++){
        this->QWidget::findChild<QComboBox*>("Type_Left")->addItem(typelist[i]);
        this->QWidget::findChild<QComboBox*>("Type_Right")->addItem(typelist[i]);
    }
    this->QWidget::connect(this->QWidget::findChild<QComboBox*>("Type_Left"),SIGNAL(activated(QString)), dynamic_cast<QWidget*>(this), SLOT(updateInputLineL(QString)));
    this->QWidget::connect(this->QWidget::findChild<QComboBox*>("Type_Left"),SIGNAL(activated(QString)), dynamic_cast<QWidget*>(this), SLOT(updateResultLine(QString)));
    this->QWidget::connect(this->QWidget::findChild<QComboBox*>("Type_Right"),SIGNAL(activated(QString)), dynamic_cast<QWidget*>(this), SLOT(updateInputLineR(QString)));
    this->QWidget::connect(this->QWidget::findChild<QComboBox*>("Type_Left"),SIGNAL(activated(QString)), dynamic_cast<QWidget*>(this), SLOT(togglableButton(QString)));
}

void MainWindow::setResult(const QVector<QString> result){
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        this->QWidget::findChild<QLineEdit*>("Result_Line"+QString('0'+i))->setText(result[i]);
        i++;
    }
}

void MainWindow::show(){
    /*?*/
    this->setNumPad();
    this->setAvailableTypes(/*existingType()*/);
    this->setAvailableOperations(/*existingOperation()*/);
    this->show();
}

////SLOT////

void MainWindow::updateInputLineL(const QString type){
    this->leftTypeIsSet(type);
    QGridLayout* layout= this->QWidget::findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))!=nullptr){
        temp= this->QWidget::findChild<QLineEdit*>("Data_Line_L"+QString('0'+i));
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
    this->rightTypeIsSet(type);
    QGridLayout* layout= this->QWidget::findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))!=nullptr){
        temp= this->QWidget::findChild<QLineEdit*>("Data_Line_R"+QString('0'+i));
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
    QGridLayout* layout= this->QWidget::findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        temp= this->QWidget::findChild<QLineEdit*>("Result_Line"+QString('0'+i));
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
    QPushButton* bs= qobject_cast<QPushButton*>(QWidget::sender());
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
    QVector<QString> data;
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    QPushButton* bs = qobject_cast<QPushButton*>(QWidget::sender());
    for(int j=0; j<i; ++j){
        templine= this->QWidget::findChild<QLineEdit*>("Data_Line_L"+QString('0'+j));
        data.append(templine->text());
    }
    this->leftValuesAreSet(data);
    if(!data.isEmpty()){
        data.append(bs->text());
        this->operationIsSet(bs->text());
    }
}

void MainWindow::resultButton(){
    QVector<QString> data;
    int i=0;
    while(this->QWidget::findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    for(int j=0; j<i; ++j){
        templine= this->QWidget::findChild<QLineEdit*>("Data_Line_R"+QString('0'+j));
        data.append(templine->text());
    }
    this->rightValuesAreSet(data);
    this->getResult();
}

void MainWindow::togglableButton(const QString type){
    QVector<QString> oppermitted(2,"+")/*permitted_operation(type)*/;
    QButtonGroup* operation= this->QWidget::findChild<QButtonGroup*>("Op_Pad");
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
    QComboBox* left= this->QWidget::findChild<QComboBox*>("Type_Left");
    QVector<QString> lastop{"color", "00", "00", "00"};//= lastOperationResult();
    left->setCurrentIndex(left->findText(lastop[0]));
    left->activated(lastop[0]);
    for(int i=1; i<lastop.size(); i++){
        this->QWidget::findChild<QLineEdit*>("Data_Line_L"+QString('0'+(i-1)))->insert(lastop[i]);
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
    qDeleteAll(this->QWidget::findChildren<QLineEdit*>());
}
*/
