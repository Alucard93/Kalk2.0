#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : View(parent){

    QGridLayout* layout= new QGridLayout(this);
    layout->setObjectName("Main_Layout");
    setLayout(layout);

    //Drop menu creation and set
    QComboBox* drop_type1= new QComboBox(this);
    drop_type1->setObjectName("Type_Left");
    layout->addWidget(drop_type1, 1, 0);
    connect(drop_type1, SIGNAL(activated(type)), this, SLOT(leftType(type)));

    QComboBox* drop_type2= new QComboBox(this);
    drop_type2->setObjectName("Type_Right");
    layout->addWidget(drop_type2, 1, 1);
    connect(drop_type2, SIGNAL(activated(type)), this, SLOT(rightType(type)));
    //End drop menu setting
}

MainWindow::~MainWindow()
{

}

//Public slots

/*add various type to the drop menu, connect the selected item to the slots*/
void MainWindow::setLeftTypes(const QVector<QString> types){
    findChild<QComboBox*>("Type_Left")->clear();
    for(int i=0; i!=types.size(); i++)
        findChild<QComboBox*>("Type_Left")->addItem(types[i]);
}

/*add various type to the drop menu, connect the selected item to the slots*/
void MainWindow::setRightTypes(const QVector<QString> types){
    findChild<QComboBox*>("Type_Right")->clear();
    if(types.size()==0)
        emit getResult();
    else
        for(int i=0; i!=types.size(); i++)
            findChild<QComboBox*>("Type_Right")->addItem(types[i]);
}

void MainWindow::setLeftFields(const int& fields){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))!=nullptr){
        temp= findChild<QLineEdit*>("Data_Line_L"+QString('0'+i));
        delete temp;
        ++i;
    }
    for(i=0; i<fields; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Data_Line_L"+QString('0'+i));
        temp->setValidator(new QDoubleValidator(temp));
        layout->addWidget(temp,2+i,0);
    }
}

void MainWindow::setRightFields(const int& fields){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))!=nullptr){
        temp= findChild<QLineEdit*>("Data_Line_R"+QString('0'+i));
        delete temp;
        i++;
    }
    for(i=0; i<fields; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Data_Line_R"+QString('0'+i));
        temp->setValidator(new QDoubleValidator(temp));
        layout->addWidget(temp,2+i,1);
    }
}

void MainWindow::setResultFields(const int& fields){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    int i=0;
    while(findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        temp= findChild<QLineEdit*>("Result_Line"+QString('0'+i));
        delete temp;
        i++;
    }
    for(i=0; i<fields; i++){
        temp= new QLineEdit(this);
        temp->setObjectName("Result_Line"+QString('0'+i));
        temp->setAlignment(Qt::AlignRight);
        temp->setPlaceholderText("Result");
        temp->setReadOnly(true);
        layout->addWidget(temp, 2+i, 7);
    }
}

void MainWindow::setAvailableOperations(const QVector<QString> oplist){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* operation= new QButtonGroup(this);
    operation->setObjectName("Op_Pad");
    QPushButton* button= nullptr;
    numopertion= oplist.size();
    for(int i=0; i<numopertion; i++){
        button= new QPushButton(oplist[i], this);
        button->setObjectName(oplist[i]);
        operation->addButton(button, i);
        layout->addWidget(operation->button(i),2+i/2, 5+i%2);
        connect(operation->button(i), SIGNAL(clicked()), this, SLOT(operationPadButton()));
    }
    button= new QPushButton("=", this);
    button->setObjectName("=");
    operation->addButton(button, oplist.size()+1);
    layout->addWidget(operation->button(oplist.size()+1),2+(oplist.size())/2, 5+(oplist.size())%2);
    connect(operation->button(oplist.size()+1), SIGNAL(clicked()), this, SLOT(resultButton()));
}

/*toggle the operation buttons that are not aviable for that type*/
void MainWindow::setPermittedOperations(const QVector<QString> operations){
    QButtonGroup* operation= findChild<QButtonGroup*>("Op_Pad");
    bool finded;
    for(int j=0; j<numopertion; ++j){
        operation->button(j)->setEnabled(false);
        dynamic_cast<QPushButton*>(operation->button(j))->setFlat(true);
    }
    for(int i=0; i<operations.size(); ++i){
        finded= false;
        for(int j=0; j<numopertion && !finded; ++j){
            if(operation->button(j)->text()==operations[i]){
                finded= true;
                operation->button(j)->setEnabled(true);
                dynamic_cast<QPushButton*>(operation->button(j))->setFlat(false);
            }
        }
    }
}

/*shows the recived result in the appropriate line*/
void MainWindow::setResult(const QVector<QString> result){
    int i=0;
    while(findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        findChild<QLineEdit*>("Result_Line"+QString('0'+i))->setText(result[i]);
        i++;
    }
}

/*set the result of the last operation as left value*/
void MainWindow::ansIsSet(QVector<QString> values){
    findChild<QComboBox*>("Type_Left")->setCurrentIndex(findChild<QComboBox*>("Type_Left")->findText(values[0]));
    emit findChild<QComboBox*>("Type_Left")->activated(values[0]);
    for(int i=1; i<values.size(); i++)
        findChild<QLineEdit*>("Data_Line_L"+QString('0'+(i-1)))->insert(values[i]);
}

void MainWindow::setNumPad(){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* numpad= new QButtonGroup(this);
    numpad->setObjectName("Num_Pad");
    QPushButton* temp= nullptr;
    int i=0;
    for(; i<9; ++i){
        temp= new QPushButton(QChar('1'+i), this);
        temp->setObjectName(QChar('1'+i));
        temp->setFocusPolicy(Qt::NoFocus);
        numpad->addButton(temp, i+1);
        layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
        connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    }
    temp=new QPushButton(".", this);
    temp->setObjectName(".");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i+1);
    layout->addWidget(numpad->button(i+1),3+i/3, 2+i%3);
    connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("0", this);
    temp->setObjectName("0");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, 0);
    layout->addWidget(numpad->button(0),3+i/3, 2+i%3);
    connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
    ++i;
    temp=new QPushButton("<-", this);
    temp->setObjectName("<-");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 2);
    connect(temp, SIGNAL(clicked()), this, SLOT(delButton()));
    ++i;
    temp=new QPushButton("CE", this);
    temp->setObjectName("CE");
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 3);
    connect(temp, SIGNAL(clicked()), this, SLOT(resetButton()));
    ++i;
    temp=new QPushButton("ANS", this);
    temp->setObjectName("ANS");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 4);
    connect(temp, SIGNAL(clicked()), this, SLOT(ansButton()));
    ++i;
    temp=new QPushButton("OLD", this);
    temp->setObjectName("OLD");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),1, 7);
    connect(temp, SIGNAL(clicked()), this, SLOT(oldButton()));
}

void MainWindow::show(){
    QWidget::show();
}

//Private slots

/*insert the selected number in the focused line*/
void MainWindow::numPadButton(){
    QWidget* focus= focusWidget();
    QPushButton* bs= qobject_cast<QPushButton*>(QWidget::sender());
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->insert(bs->text());
    }
}

/*delete the last number from the focused line*/
void MainWindow::delButton(){
    QWidget* focus= focusWidget();
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->backspace();
    }
}

/*delete all the edit line and clean the drop menu*/
void MainWindow::resetButton(){
    qDeleteAll(findChildren<QLineEdit*>());
    findChild<QComboBox*>("Type_Left")->clear();
    findChild<QComboBox*>("Type_Right")->clear();
    emit MainWindow::reset();
}

/*set the result of the last operation as left value*/
void MainWindow::ansButton(){
    emit MainWindow::lastOperation();
}

void MainWindow::oldButton(){
    QLineEdit* old= new QLineEdit();
    old->setReadOnly(true);
    old->setText("test");
    //todo
}

/*send the left values and the operation selected*/
void MainWindow::operationPadButton(){
    QVector<QString> data;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    QPushButton* bs = qobject_cast<QPushButton*>(QWidget::sender());
    for(int j=0; j<i; ++j){
        templine= findChild<QLineEdit*>("Data_Line_L"+QString('0'+j));
        data.append(templine->text());
    }
    emit MainWindow::leftValuesAreSet(data);
    emit MainWindow::operationIsSet(bs->text());
}

/*send the right values*/
void MainWindow::resultButton(){
    QVector<QString> data;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    for(int j=0; j<i; ++j){
        templine= findChild<QLineEdit*>("Data_Line_R"+QString('0'+j));
        data.append(templine->text());
    }
    emit MainWindow::rightValuesAreSet(data);
    emit MainWindow::getResult();
}

void MainWindow::leftType(const QString type){
    emit leftTypeIsSet(type);
}

void MainWindow::rightType(const QString type){
    emit rightTypeIsSet(type);
}
