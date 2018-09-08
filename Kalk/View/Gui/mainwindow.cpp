#include "mainwindow.h"
/**
 * @brief MainWindow::MainWindow constructor
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : View(parent){

    QGridLayout* layout= new QGridLayout(this);
    layout->setObjectName("Main_Layout");
    setLayout(layout);

    //Drop menu creation and set
    QComboBox* drop_type1= new QComboBox(this);
    drop_type1->setObjectName("Type_Left");
    drop_type1->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    layout->addWidget(drop_type1, 1, 0);
    connect(drop_type1, SIGNAL(activated(QString)), this, SLOT(leftType(QString)));
    connect(drop_type1, SIGNAL(activated(QString)), this, SLOT(resultType(QString)));

    QComboBox* drop_type2= new QComboBox(this);
    drop_type2->setObjectName("Type_Right");
    drop_type2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    layout->addWidget(drop_type2, 1, 1);
    connect(drop_type2, SIGNAL(activated(QString)), this, SLOT(rightType(QString)));

    QComboBox* drop_type3= new QComboBox(this);
    drop_type3->setObjectName("Type_Result");
    drop_type3->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    layout->addWidget(drop_type3, 1, 7);
    connect(drop_type3, SIGNAL(activated(QString)), this, SLOT(resultType(QString)));

    setNumPad();

}

/**
 * @brief MainWindow::MainWindow virtual destructor
 */
MainWindow::~MainWindow()
{
    QObjectList children = this->children();
    QVector<QObject*> toDelete = children.toVector();
    QObject* child;
    foreach(child,toDelete)
        delete child;
}

//Public slots
/**
 * @brief MainWindow::setLeftTypes add various types to the left drop menu
 * @param types
 */
void MainWindow::setLeftTypes(const QVector<QString> types){
    findChild<QComboBox*>("Type_Left")->clear();
    findChild<QComboBox*>("Type_Left")->addItem("Select type");
    for(int i=0; i!=types.size(); i++)
        findChild<QComboBox*>("Type_Left")->addItem(types[i]);
    setResultTypes(types);
}

/**
 * @brief MainWindow::setRightTypes add various types to the right drop menu
 * @param types
 */
void MainWindow::setRightTypes(const QVector<QString> types){
    findChild<QComboBox*>("Type_Right")->clear();
    if(types[0]=="Select Operation")
        findChild<QComboBox*>("Type_Right")->addItem(types[0]);
    else{
        findChild<QComboBox*>("Type_Right")->addItem("Select type");
        if(types[0]=="non disponibile")
            emit getResult();
        else
            for(int i=0; i!=types.size(); i++)
                findChild<QComboBox*>("Type_Right")->addItem(types[i]);
    }
}

/**
 * @brief MainWindow::setResultTypes add various types to the result drop menu
 * @param types
 */
void MainWindow::setResultTypes(const QVector<QString> types){
    findChild<QComboBox*>("Type_Result")->clear();
    findChild<QComboBox*>("Type_Result")->addItem("Select type");
    for(int i=0; i!=types.size(); i++)
        findChild<QComboBox*>("Type_Result")->addItem(types[i]);
}

/**
 * @brief MainWindow::setLeftFields add #fields entry lines for the selected left type
 * @param fields
 */
void MainWindow::setLeftFields(const int& fields, const QVector<QString>& limits){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    bool limitsInt= (fields==limits.size()/3);
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
        if(limitsInt){
            temp->setPlaceholderText(limits[i*3]);
            temp->setToolTip("min: "+limits[i*3+1]+" max: "+limits[i*3+2]);
        }
        temp->adjustSize();
        layout->addWidget(temp,2+i,0);
    }
    setRightFields(0,{});
    setRightTypes({"Select Operation"});

}

/**
 * @brief MainWindow::setRightFields add #fields entry lines for the selected right type
 * @param fields
 */
void MainWindow::setRightFields(const int& fields, const QVector<QString>& limits){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QLineEdit* temp= nullptr;
    bool limitsInt= (fields==limits.size()/3);
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
        if(limitsInt){
            temp->setPlaceholderText(limits[i*3]);
            temp->setToolTip("min: "+limits[i*3+1]+" max: "+limits[i*3+2]);
        }
        temp->adjustSize();
        layout->addWidget(temp,2+i,1);
    }
}

/**
 * @brief MainWindow::setResultFields add #fields lines for the result
 * @param fields
 */
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
        temp->adjustSize();
        layout->addWidget(temp, 2+i, 7);
    }
}

/**
 * @brief MainWindow::setAvailableOperations create and connect the given operation to the buttons
 * @param oplist
 */
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

/**
 * @brief MainWindow::setPermittedOperations toggle the operation buttons that are not aviable for that type
 * @param operations
 */
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

/**
 * @brief MainWindow::setResult shows the recived result in the appropriate line
 * @param result
 */
void MainWindow::setResult(const QVector<QString> result){
    int i=0;
    while(findChild<QLineEdit*>("Result_Line"+QString('0'+i))!=nullptr){
        findChild<QLineEdit*>("Result_Line"+QString('0'+i))->setText(result[i]);
        i++;
    }
}

/**
 * @brief MainWindow::setNumPad set the numbers buttons and the utility buttons, then connect them to the appropriate input
 */
void MainWindow::setNumPad(){
    QGridLayout* layout= findChild<QGridLayout*>("Main_Layout");
    QButtonGroup* numpad= new QButtonGroup(this);
    numpad->setObjectName("Num_Pad");
    QPushButton* temp= nullptr;
    int i=0;
    int j=8;
    for(; i<9; ++i){
        temp= new QPushButton(QChar('1'+i), this);
        temp->setObjectName(QChar('1'+i));
        temp->setFocusPolicy(Qt::NoFocus);
        numpad->addButton(temp, i+1);
        layout->addWidget(numpad->button(i+1),5-i/3, 2+i%3);
        connect(temp, SIGNAL(clicked()), this, SLOT(numPadButton()));
        --j;
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
    temp=new QPushButton("OLD", this);
    temp->setObjectName("OLD");
    temp->setFocusPolicy(Qt::NoFocus);
    numpad->addButton(temp, i);
    layout->addWidget(numpad->button(i),2, 4);
    connect(temp, SIGNAL(clicked()), this, SLOT(oldButton()));
}

/**
 * @brief MainWindow::show shows the windows
 */
void MainWindow::show(){
    QWidget::show();
}

/**
 * @brief MainWindow::setHistory create a new window with history
 * @param h
 */
void MainWindow::setHistory(const QVector<QVector<QString>>& h){
    HistoryWindow * history = new HistoryWindow(h);
}

/**
 * @brief MainWindow::error create a new window with error message
 * @param error_message
 */
void MainWindow::error(const QString& error_message){
    QErrorMessage * error = new QErrorMessage(this);
    error->showMessage(error_message);
}


//Private slots

/**
 * @brief MainWindow::numPadButton insert the selected number in the focused line
 */
void MainWindow::numPadButton(){
    QWidget* focus= focusWidget();
    QPushButton* bs= qobject_cast<QPushButton*>(QWidget::sender());
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->insert(bs->text());
    }
}

/**
 * @brief MainWindow::delButton delete the last number from the focused line
 */
void MainWindow::delButton(){
    QWidget* focus= focusWidget();
    if(dynamic_cast<QLineEdit*>(focus)){
        QLineEdit* line= static_cast<QLineEdit*>(focus);
        line->backspace();
    }
}

/**
 * @brief MainWindow::resetButton delete all the edit line and clean the drop menu
 */
void MainWindow::resetButton(){
    qDeleteAll(findChildren<QLineEdit*>());
    findChild<QComboBox*>("Type_Left")->clear();
    findChild<QComboBox*>("Type_Right")->clear();
    emit MainWindow::reset();
}

/**
 * @brief MainWindow::oldButton show the history
 */
void MainWindow::oldButton(){
    emit getHistory();
}

/**
 * @brief MainWindow::operationPadButton send the left values and the operation selected
 */
void MainWindow::operationPadButton(){
    setRightFields(0,{});
    QVector<QString> l_data;
    QLineEdit* templine = nullptr;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))){
        ++i;
    }

    for(int j=0; j<i; ++j){
        templine= findChild<QLineEdit*>("Data_Line_L"+QString('0'+j));
        l_data.append(templine->text());
    }
    emit MainWindow::leftValuesAreSet(l_data);
    QPushButton* bs = qobject_cast<QPushButton*>(QWidget::sender());
    emit MainWindow::operationIsSet(bs->text());
}

/**
 * @brief  MainWindow::resultButton send the right and left and asks for result values
 */
void MainWindow::resultButton(){
    QVector<QString> r_data;
    int i=0;
    while(findChild<QLineEdit*>("Data_Line_R"+QString('0'+i))){
        ++i;
    }
    QLineEdit* templine= nullptr;
    for(int j=0; j<i; ++j){
        templine= findChild<QLineEdit*>("Data_Line_R"+QString('0'+j));
        r_data.append(templine->text());
    }

    QVector<QString> l_data;
    templine = nullptr;
    i=0;
    while(findChild<QLineEdit*>("Data_Line_L"+QString('0'+i))){
        ++i;
    }

    for(int j=0; j<i; ++j){
        templine= findChild<QLineEdit*>("Data_Line_L"+QString('0'+j));
        l_data.append(templine->text());
    }
    emit MainWindow::leftValuesAreSet(l_data);
    emit MainWindow::rightValuesAreSet(r_data);
    emit MainWindow::getResult();
}

/**
 * @brief MainWindow::leftTyper send the selected type from the left drop menu
 * @param type
 */
void MainWindow::leftType(QString type){
    emit leftTypeIsSet(type);
}

/**
 * @brief MainWindow::rightType send the selected type from the right drop menu
 * @param type
 */
void MainWindow::rightType(QString type){
    emit rightTypeIsSet(type);
}

/**
 * @brief MainWindow::resultType
 * @param type
 */
void MainWindow::resultType(QString type){
    findChild<QComboBox*>("Type_Result")->setCurrentText(type);
    emit resultTypeIsSet(type);
}

/**
 * @brief MainWindow::resetType
 * @param drop
 * @param type
 */
void MainWindow::resetType(QString drop, QString type){
    findChild<QComboBox*>(drop)->setCurrentText(type);
}
