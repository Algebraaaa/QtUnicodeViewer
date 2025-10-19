#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) , ui(new Ui::Widget)
{
    ui->setupUi(this);
    iniSignalSlots();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::iniSignalSlots()
{
    // Qt 规定了一种自动信号槽命名约定机制（Auto-Connection by name）只要你的槽函数名符合这种格式，Qt 会在 setupUi() 时自动帮你建立连接
    // 你在ui界面“转到槽”也会自动命名为以上的格式从而自动连接信号与槽函数
    // 所以以下connect注释掉了，不然再连接一次会出现多次触发信号，这里写出部分槽函数是为了更直观
    // connect(ui->btnGetChars,&QPushButton::clicked,this,&Widget::on_btnGetChars_clicked);
    // connect(ui->btnCharJudge,&QPushButton::clicked,this,&Widget::on_btnCharJudge_clicked);
}

void Widget::on_btnGetChars_clicked()
{
    QString str=ui->editStr->text();
    if(str.isEmpty())return;
    ui->plainTextEdit->clear();
    for(qint16 i=0;i<str.size();++i)
    {
        QChar ch=str.at(i);
        char16_t uniCode=ch.unicode();
        QString chStr(ch);
        QString info=chStr+QString::asprintf("\t,Unicode编码=0x%X",uniCode);
        ui->plainTextEdit->appendPlainText(info);
    }
}

void Widget::on_btnCharJudge_clicked()
{
    QString str=ui->editChar->text();
    if(str.isEmpty())return;
    QChar ch=str[0];
    char16_t uniCode=ch.unicode();
    QString chStr(ch);
    QString info=chStr+QString::asprintf("\t,Unicode编码=0x%X",uniCode);
    ui->plainTextEdit->appendPlainText((info));
    ui->checkDigit->setChecked(ch.isDigit());                   //判断是否是数字字符（0-9）
    ui->checkLetter->setChecked(ch.isLetter());                 //判断是否是字母
    ui->checkLetterOrNumber->setChecked(ch.isLetterOrNumber()); //判断是否是字母或数字
    ui->checkUpper->setChecked(ch.isUpper());                   //判断是否是大写字母
    ui->checkLower->setChecked(ch.isLower());                   //判断是否是小写字母
    ui->checkMark->setChecked(ch.isMark());                     //判断是否是标记字符
    ui->checkSpace->setChecked(ch.isSpace());                   //判断是否是空白字符
    ui->checkSymbol->setChecked(ch.isSymbol());                 //判断是否是符号字符
    ui->checkPunct->setChecked(ch.isPunct());                   //判断是否是标点符号
}


void Widget::on_btn_Clear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnCovLatin1_clicked()
{
    QString str="Dimple";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(str);
    QChar chP=QChar::fromLatin1(('P'));
    //  QChar chP=QChar('P');
    str[0]=chP;
    ui->plainTextEdit->appendPlainText("\n"+str);
}


void Widget::on_btnCovUTF16_clicked()
{
    QString str="Hello,北京";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(str);
    str[6]=QChar(0x9752);
    str[7]=QChar::fromUcs2(0x5C9B);
    ui->plainTextEdit->appendPlainText("\n"+str);
}


void Widget::on_btnCompare_clicked()
{
    QString str="他们来自于河南或者河北";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(str);
    QString HuStr="河to湖";
    QChar He=QChar::fromUcs2(HuStr[0].unicode());
    QChar Hu=QChar(HuStr[3].unicode());
    for(qint16 i=0;i<str.size();i++)
    {
        if(str.at(i)==He)str[i]=Hu;
    }
    ui->plainTextEdit->appendPlainText("\n"+str);
}

