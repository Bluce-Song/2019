#include "w_data.h"
#include "ui_w_data.h"

w_Data::w_Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::w_Data)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去掉标题栏
    ui->setupUi(this);

    ui->button_in->hide();
    ui->button_put->hide();
    ui->button_out_model->hide();
    ui->lineEdit->hide();

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:#191919;color: white;padding-left: 4px;border: 1px solid #447684;}");
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0,138);
    ui->tableWidget->setColumnWidth(1,160);
    ui->tableWidget->setColumnWidth(2,160);
    ui->tableWidget->setColumnWidth(3,160);
    ui->tableWidget->setColumnWidth(4,160);

    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    label_Waring = new QLabel(this);  // 建立
    label_Waring->setGeometry(0,0,800,600);
    label_Waring->setWindowFlags(Qt::WindowStaysOnTopHint);
    label_Waring->hide();

    u_disk = new QLabel(this);        // 寤虹珛
    u_disk->setGeometry(250,250,300,100);
    u_disk->setWindowFlags(Qt::WindowStaysOnTopHint);
    u_disk->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;color: white;");
    u_disk->setText(tr("正在导出数据,请稍候..."));
    u_disk->setAlignment(Qt::AlignCenter);
    u_disk->hide();

    U_Exporting =  new QLabel(this);  // 建立
    U_Exporting->setGeometry(0,0,800,600);
    U_Exporting->setWindowFlags(Qt::WindowStaysOnTopHint);
    U_Exporting->hide();

    calendarWidget = new QCalendarWidget(this);     //显示日历
    calendarWidget->setGeometry(20, 75, 525, 270);  //(20, 75, 350, 180);
    if(ui->button_check->text()=="查询")
    {
       calendarWidget->setLocale(QLocale(QLocale::Chinese,QLocale::China));
    }
    else
    {
        calendarWidget->setLocale(QLocale(QLocale::English,QLocale::AnyCountry));
    }

    calendarWidget->setHidden(true);
    connect(calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(join_setData()));

    QString CurrentDateTime = QDateTime::currentDateTime().toString("yyyy/MM/dd"); //设置显示格式
    ui->button_start->setText(CurrentDateTime);
    ui->button_stop->setText(CurrentDateTime);

    dropdown_List = new QTableWidget(this);
    dropdown_List->setGeometry(ui->Model->x(),ui->Model->y()+ui->Model->height(),141,241);
    dropdown_List->insertColumn(0);
    dropdown_List->horizontalHeader()->setStretchLastSection(true);  //  充满整个宽度
    dropdown_List->horizontalHeader()->setVisible(false);            //  隐藏列头
    dropdown_List->verticalHeader()->setVisible(false);
    dropdown_List->hide();

    connect(dropdown_List,SIGNAL(cellClicked(int,int)),this,SLOT(join_getData(int,int)));

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:#191919;color: white;padding-left: 4px;border: 1px solid #447684;}");
    ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:#191919;color: white;padding-left: 4px;}");//border: 1px solid #447684;
 // ui->tableView->verticalHeader()->setVisible(false);  //

    FILE *fp;
    fp = fopen("/dev/mmcblk0","r");
    if(fp!=NULL)
    {
        qDebug()<<"存在 SD";
        ui->label_SD->show();
        struct statfs diskInfo;
        statfs("/mnt/sdcard",&diskInfo);
        unsigned long long blocksize = diskInfo.f_bsize;                  // 每个block里包含的字节数
        unsigned long long availableDisk = diskInfo.f_bavail * blocksize; // 可用空间大小
        ui->label_SD->setText(QString(tr("SD-%1 M")).arg(availableDisk>>20));
    }
    else
    {
        qDebug()<<"不存在 SD";
        ui->label_SD->hide();
    }

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("/mnt/nandflash/aip.db");
//    db.open();

//  model = new QSqlTableModel(this);
    student_model = new QStandardItemModel(this);
    ui->tableView->hide();
//    Data_Dispaly=0;
    tableView_column=0;

    scale_bar = 0;
    U_waiting = false;
    U_time_count = 0;
    U_time = new QTimer(this);
    connect(U_time,SIGNAL(timeout()),this,SLOT(U_show_time()));

    model_test.clear();
    model_test.append(QString::number(0));
}
w_Data::~w_Data()
{
    delete ui;
}
void w_Data::mousePressEvent (QMouseEvent *event) //处理鼠标被按下事件
{
    calendarWidget->setHidden(true);
    label_Waring->hide();
}
void w_Data::on_back_clicked()
{
    Signal_Data_to_Main(QStringList(""),wMain_Surface,1);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.2
  * brief:      检测U盘显示和按键使能
******************************************************************************/
void w_Data::UDisk_Test(int a,QString USB)
{
    if((a==1)||(a==2))
    {
        ui->label_Udiak->setText(tr("U盘 OK"));
        usb_name=USB;
    //  ui->button_in->show();
        ui->button_put->show();
    //  ui->button_out_model->show();
    //  ui->lineEdit->show();

        QDir *temp = new QDir;
        if(temp->exists(QString("/mnt/%1/AIP-Debug").arg(USB))) //导出调试文件
        {
        //    Singal_Data_to_Conf(usb_name,QStringList(""),4);  qDebug()<<"AIP-Debug  存在";
        }
        else
        {
            qDebug()<<"AIP-Debug  不存在";
        }

        if(temp->exists(QString("/mnt/%1/AIP-DayRecord").arg(USB))) //导出日志记录文件
        { 
        //    Singal_Data_to_Conf(usb_name,QStringList(""),5); qDebug()<<"AIP-DayRecord  存在";
        }
        else
        {
            qDebug()<<"AIP-DayRecord  不存在";
        }
    }
    if((a==3)||(a==4))
    {
        ui->label_Udiak->setText(tr("U盘 已卸载"));
        ui->button_in->hide();
        ui->button_put->hide();
        ui->button_out_model->hide();
        ui->lineEdit->hide();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.5
  * brief:      保存U盘数据
******************************************************************************/
void w_Data::on_button_put_clicked()
{
    U_Exporting->show();
       U_time_count = 0;  U_time->start(1000); // 1s触发
       u_disk->setText(tr("正在导出数据,请稍候..."));
       u_disk->show();
       qApp->processEvents();
       U_waiting = true;

       QStringList U_Message;
       U_Message.clear();
       U_Message.append(ui->Model->text());
       U_Message.append(ui->button_start->text());
       U_Message.append(ui->button_stop->text());
       U_Message.append(usb_name);
       qDebug()<<"U_Message--6"<<U_Message;
       emit Signal_Data_to_Main(U_Message,3,3);

       qDebug() << "Test";
}

void w_Data::U_test_Finsh_time() {
    QEventLoop eventloop; // 延时等待2s
    for (int j=0;j<20;j++) {
        QTimer::singleShot(100, &eventloop, SLOT(quit()));
        eventloop.exec();
        system("sync");
    }

    U_time_count = 0;  U_time->stop();
    u_disk->hide();
    Pri_Data_WMessage(tr("      导出数据完成      "));
    U_Exporting->hide();
}

void w_Data::U_show_time() {
    U_time_count++;
    if(U_waiting) {
        pubslot_display_scale(QStringList(""),scale_bar,1);
    }
    else {
        u_disk->setText(QString(tr("正在查询数据,请稍候...")+QString::number(U_time_count)+"s"));
    }
}

void w_Data::on_button_in_clicked()
{
//    Singal_Data_to_Conf(usb_name,QStringList(""),1);
}
void w_Data::on_button_out_model_clicked()
{
//    Singal_Data_to_Conf(usb_name,QStringList(""),2);
//  Singal_Data_to_Conf(usb_name,ui->lineEdit->text(),2);
}
void w_Data::pubslot_display_scale(QStringList list,int scale,int value)
{
    int i,x;
    switch (value)
    {
    case 1:
        scale_bar = scale;
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        u_disk->setText(QString(tr("正在导出数据,请稍候%1...").arg(QString::number(scale_bar)+"% "))+QString::number(U_time_count)+"s");

        qApp->processEvents();
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
        break;
    case 2:
        for(x=0;x<list.size()/tableView_column;x++)
        {
            for(i=0;i<tableView_column;i++) // 设置数据
            {
                student_model->setItem((scale-1)*100+x,i,new QStandardItem(list.at(x*tableView_column+i))); // 行 列 数据
            }
        }
//        label_Waring->setText(QString(tr("正在查询详细数据%1，请稍候")).arg(scale*100));
//        qApp->processEvents();   //  立即显示生效
        break;
    case 3:
        U_waiting = false;
        break;
    case 4:
        Judge_Max_ID(scale);
        break;
    case 5:
        qDebug()<<"5---5";
        Data_Count = list;
        Structure_Interface("wData","");
        Pub_Set_TableAll();

        qDebug()<<"6-6";
        break;
    case 6:
        label_Waring->hide();
        u_disk->hide();
        U_Exporting->hide();
        U_time_count = 0;  U_time->stop(); // 1s触发
        break;
    default:
        break;
    }
}

void w_Data::Judge_Max_ID(int Max_count) {
    QStringList search;
    search.append(ui->Model->text());
    search.append(ui->button_start->text());
    search.append(ui->button_stop->text());

    if (Max_count<1000000) {
        U_Exporting->show();
        u_disk->setText(QString(tr("正在查询数据,请稍候...")+QString::number(U_time_count)+"s"));
        u_disk->show();
        U_time_count = 0;  U_time->start(1000); // 1s触发
        Signal_Data_to_Main(search,2,2); // 执行查询
        qDebug()<<"数据记录表格完成";
        qApp->processEvents(); // 立即显示生效
    }
    else {
        QMessageBox *message=new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;padding:2px 4px;background-color: gray;height:390px;width:375px;}");
        message->setText(QString(tr("     当前数据量较大，建议导出查询。      \n     是否继续查询？      ")));
        message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
        message->addButton(QMessageBox::Cancel)->setStyleSheet("height:39px;width:75px;border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok,QString(tr("确 定")));
        message->setButtonText(QMessageBox::Cancel,QString(tr("取 消")));
        message->setIcon(QMessageBox::Warning);
        int ret=message->exec();
        if(ret==QMessageBox::Ok) {
            U_Exporting->show();
            u_disk->setText(QString(tr("正在查询数据,请稍候...")+QString::number(U_time_count)+"s"));
            u_disk->show();
            U_time_count = 0;  U_time->start(1000); // 1s触发
            Signal_Data_to_Main(search,2,2); // 执行查询
            qDebug()<<"数据记录表格完成";
            qApp->processEvents(); // 立即显示生效
        }
        else {

        }
    }
}

void w_Data::on_button_check_clicked()
{
    ui->tableWidget->setRowCount(0);
    student_model->clear();
    dropdown_List->hide();
    qApp->processEvents(); // 隐藏下拉
    Signal_Data_to_Main(QStringList(""),4,4);
}
void w_Data::Pub_Set_Data(QStringList list) {

    User_Data = list.at(0).toInt();
    ACW_display  = list.at(1).toInt();
    Motor_PG_Commmon = list.at(2);
}

void w_Data::Pub_Set_TableAll()
{
    int i,x;
//    User_Data = list.at(0).toInt();
//    ACW_display  = list.at(1).toInt();
//    Motor_PG_Commmon = list.at(2);
    QStringList  tableviewfield;
    QStringList  Table_head;

    student_model->clear();

    ui->button_change->setText(tr("查询中..."));    qApp->processEvents();   //  立即显示生效

    tableviewfield<<tr("data")<<tr("电机型号")<<tr("总结果")<<tr("时间")<<tr("温度")<<tr("工位")<<tr("编号")<<tr("用户")<<tr("总项目");
    for(i=0;i<(Data_Count.size()-3)/3;i++)
    {
        if(Data_Count.at((i+1)*3)==tr("电阻"))
        {
            for(x=0;x<8;x++)
            {
                Table_head += QString(tr("电阻%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("电阻%1(ohm)")).arg(QString::number(x+1));
                Table_head += QString(tr("电阻%1判定")).arg(QString::number(x+1));
            }
            Table_head += QString(tr("电阻不平衡度参数"));   Table_head += QString(tr("不平衡度"));  Table_head += QString(tr("不平衡度判定"));
        }
        else if(Data_Count.at((i+1)*3)==tr("反嵌"))
        {
            for(x=0;x<8;x++)
            {
                Table_head += QString(tr("反嵌%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("反嵌%1")).arg(QString::number(x+1));
                Table_head += QString(tr("反嵌%1判定")).arg(QString::number(x+1));
            }
            Table_head += QString(tr("磁旋参数"));     Table_head += QString(tr("磁旋"));    Table_head += QString(tr("磁旋判定"));
        }
        else if(Data_Count.at((i+1)*3)==tr("绝缘"))
        {
            if(ACW_display==1)
            {
                for(x=0;x<4;x++)
                {
                    Table_head += QString(tr("绝缘%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("绝缘%1(M ohm)")).arg(QString::number(x+1));
                    Table_head += QString(tr("绝缘%1判定")).arg(QString::number(x+1));
                }
            }
            else
            {
                Table_head += QString(tr("绝缘参数"));  Table_head += QString(tr("绝缘(M ohm)"));   Table_head += QString(tr("绝缘判定"));
            }
        }
        else if(Data_Count.at((i+1)*3)==tr("交耐"))
        {
            if(ACW_display==1)
            {
                for(x=0;x<4;x++)
                {
                    Table_head += QString(tr("交耐%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("交耐%1(M ohm)")).arg(QString::number(x+1));
                    Table_head += QString(tr("交耐%1判定")).arg(QString::number(x+1));
                }
            }
            else
            {
                Table_head += QString(tr("交耐参数"));  Table_head += QString(tr("交耐(mA)"));   Table_head += QString(tr("交耐判定"));
            }
        }
        else if(Data_Count.at((i+1)*3)==tr("直耐"))
        {

        }
        else if(Data_Count.at((i+1)*3)==tr("匝间"))
        {
            for(x=0;x<8;x++)
            {
                Table_head += QString(tr("匝间%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("面积%1")).arg(QString::number(x+1));
                Table_head += QString(tr("差积%1")).arg(QString::number(x+1));
                Table_head += QString(tr("电晕%1")).arg(QString::number(x+1));
                Table_head += QString(tr("相位%1")).arg(QString::number(x+1));
                Table_head += QString(tr("匝间%1判定")).arg(QString::number(x+1));
            }
        }
        else if(Data_Count.at((i+1)*3)==tr("电参"))
        {
            for(x=0;x<6;x++)
            {
                Table_head += QString(tr("电参%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("电流%1(A)")).arg(QString::number(x+1));
                Table_head += QString(tr("功率%1(W)")).arg(QString::number(x+1));
                Table_head += QString(tr("容压%1(V)")).arg(QString::number(x+1));
                Table_head += QString(tr("电参%1判定")).arg(QString::number(x+1));
            }
            for(x=0;x<6;x++)
            {
                Table_head += QString(tr("转向%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("转向%1")).arg(QString::number(x+1));
                Table_head += QString(tr("转向%1判定")).arg(QString::number(x+1));
            }
        }

        else if(Data_Count.at((i+1)*3)==tr("PG"))
        {
            if(Motor_PG_Commmon==QString("PG"))
            {
                for(x=0;x<3;x++)
                {
                    Table_head += QString(tr("PG %1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("PG %1")).arg(QString::number(x+1));
                    Table_head += QString(tr("PG %1判定")).arg(QString::number(x+1));
                }
            }
        }
        else if(Data_Count.at((i+1)*3)==tr("电感"))
        {
            for(x=0;x<8;x++)
            {
                Table_head += QString(tr("电感%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("电感%1(H)")).arg(QString::number(x+1));
                Table_head += QString(tr("Q值%1")).arg(QString::number(x+1));
                Table_head += QString(tr("电感%1判定")).arg(QString::number(x+1));
            }
            Table_head += QString(tr("电感不平衡度参数"));  Table_head += QString(tr("不平衡度"));   Table_head += QString(tr("不平衡度判定"));
        }
        else if(Data_Count.at((i+1)*3)==tr("堵转"))
        {
            Table_head += QString(tr("堵转参数"));
            Table_head += QString(tr("电流(A)"));
            Table_head += QString(tr("功率(W)"));
            Table_head += QString(tr("堵转判定"));
        }
        else if(Data_Count.at((i+1)*3)==tr("低启"))
        {
            Table_head += QString(tr("低启参数"));
            Table_head += QString(tr("电流(A)"));
            Table_head += QString(tr("功率(W)"));
            Table_head += QString(tr("低启判定"));
        } else if(Data_Count.at((i+1)*3)==tr("空载")) {
            Table_head += QString(tr("空载参数"));
            Table_head += QString(tr("空载"));
            Table_head += QString(tr("空载判定"));
        } else if(Data_Count.at((i+1)*3)==tr("HALL")) {
            for(x=0;x<5;x++)
            {
                Table_head += QString(tr("HALL%1参数")).arg(QString::number(x+1));
                Table_head += QString(tr("HALL%1(A)")).arg(QString::number(x+1));
                Table_head += QString(tr("HALL%1判定")).arg(QString::number(x+1));
            }
        } else {

        }
    }
    tableviewfield.append(Table_head);
    tableView_column = tableviewfield.size(); // 得到列数
    for(i=0;i<tableView_column;i++) // 设置表头
    {
        student_model->setHorizontalHeaderItem(i, new QStandardItem(tableviewfield.at(i)));
    }

    ui->tableView->setModel(student_model);     qDebug()<<"Second---";
    //   ui->tableView->resizeColumnsToContents();   qDebug()<<"Three";  // 自动填充列宽度
    for(i=0;i<tableView_column;i++) // 设置表头宽度
    {
        ui->tableView->setColumnWidth(i,200);
    }
    ui->tableView->scrollToBottom();            qDebug()<<"Four";   // 滚动条移动到最下面
    ui->button_change->setText(tr("详细数据"));
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.11
  * brief:      设置界面数据
******************************************************************************/
void w_Data::Structure_Interface(QString InterFace,QString SetName)
{
    int number;
    ui->tableWidget->setRowCount(0);
    student_model->clear();
    qApp->processEvents();

    if(InterFace=="wMain")
    {
        QString CurrentDateTime = QDateTime::currentDateTime().toString("yyyy/MM/dd"); //设置显示格式
        ui->Model->setText(SetName);
        ui->button_start->setText(CurrentDateTime);
        ui->button_stop->setText(CurrentDateTime);
        dropdown_List->hide();
        return;
    }

    number=QString(Data_Count.mid(Data_Count.indexOf("Model")+1,1).at(0)).toInt();
    model_test.clear();
    model_test<<QString::number(number)<<Data_Count.mid(Data_Count.indexOf("Model")+2,number);
 /* completer = new QCompleter(model_test, this);
    ui->comboBox->clear();
    ui->comboBox->addItems(model_test);
    ui->comboBox->setEditable(true);
    ui->comboBox->setCompleter(completer); */
    Data_Count=Data_Count.mid(0,Data_Count.indexOf("Model"));

    if(ui->button_start->text().compare(ui->button_stop->text())<=0)
    {
        int i,j;  QString str;
        int row=(Data_Count.size()/3);   //读取行数
        ui->tableWidget->setRowCount(0);
        if(row<=10)
        {
            ui->tableWidget->setRowCount(10);
            for(i=0; i<10; i++)
            {
                ui->tableWidget->setRowHeight(i,39);
            }
        }
        else
        {
            ui->tableWidget->setRowCount(row);
            for(i=0; i<row; i++)
            {
                ui->tableWidget->setRowHeight(i,39);
            }
        }

        if(Data_Count.at(1)=="0")
        {
            if(InterFace=="wData")
            {
                u_disk->hide();
                label_Waring->hide();
                U_Exporting->hide();
                qApp->processEvents();
                Pri_Data_WMessage(QString(tr("   查询文件无记录   ")));
            }
        }
        else
        {
            for(i=0; i<row; i++)
            {
                for(j=0;j<5;j++)
                {
                    if(j==0)
                    {
                        str=Data_Count.at(i*3);
                    }
                    else if(j==1)
                    {
                        str=Data_Count.at(i*3+1);
                    }
                    else if(j==2)
                    {
                        str=QString::number(Data_Count.at(i*3+1).toInt()-Data_Count.at(i*3+2).toInt());
                    }
                    else if(j==3)
                    {
                        str=Data_Count.at(i*3+2);
                    }
                    else if(j==4)
                    {
                        if(Data_Count.at(i*3+1).toInt()==0)
                        {
                            str="---";
                        }
                        else
                        {
                            str=QString::number((int)((Data_Count.at(i*3+1).toDouble()-Data_Count.at(i*3+2).toDouble())/(Data_Count.at(i*3+1).toDouble())*100))+"%";
                        }
                    }
              //      qDebug()<<"str"<<str;
                    QTableWidgetItem *pItem = new QTableWidgetItem(str);
                    pItem->setTextAlignment(Qt::AlignCenter);
                    pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                    ui->tableWidget->setItem(i,j,pItem);
                }
            }
        }
    }
    else
    {
        Pri_Data_WMessage(QString(tr("   设置日期错误   ")));
    }
    ui->tableWidget->show();
    ui->tableView->hide();
    ui->button_change->setText(tr("详细数据"));
    qApp->processEvents(); // 立即显示生效
}
//  获取序列号
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      点击设置日历数据
******************************************************************************/
void w_Data::join_setData()
{
    calendarWidget->setHidden(true);
    label_Waring->hide();
    QDate date = calendarWidget->selectedDate();
    QString str = date.toString("yyyy/MM/dd");
    if(pushbuttoned=="Start")
    {
       ui->button_start->setText(str);
    }
    else if(pushbuttoned=="Stop")
    {
       ui->button_stop->setText(str);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      开始时间--设置
******************************************************************************/
void w_Data::on_button_start_clicked()
{
    calendarWidget->setHidden(false);
    label_Waring->show();
    pushbuttoned="Start";
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      结束时间--设置
******************************************************************************/
void w_Data::on_button_stop_clicked()
{
    calendarWidget->setHidden(false);
    label_Waring->show();
    pushbuttoned="Stop";
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      设置警告弹出框
******************************************************************************/
void  w_Data::Pri_Data_WMessage(QString Waring_Text)  // QMessageBox message;
{
    label_Waring->show();
    QMessageBox *message=new QMessageBox(this);
    message->setWindowFlags(Qt::FramelessWindowHint);
    message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;padding:2px 4px;background-color: gray;height:390px;width:375px;}");
    message->setText(Waring_Text+"\n");
    message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
    message->setButtonText(QMessageBox::Ok,QString(tr("确 定")));
    message->setIcon(QMessageBox::Warning);
    message->exec();
    label_Waring->hide();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      单击按键 显示详细信息
******************************************************************************/
void w_Data::on_button_detailed_clicked()
{
    QString time=QString(tr("时间"))+ui->button_start->text()+QString(tr("至"))+ui->button_stop->text();
    QString str1=QString(tr("包含有---%1个型号")).arg(model_test.at(0));
    QString str2;
    int i;
    for(i=1;i<model_test.size();i++)
    {
        str2+=model_test.at(i)+" ";
    }
    Pri_Data_WMessage(time+"\n"+str1+"\n"+str2);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      Model_text的文本改变，设置 dropdown_List 变化
******************************************************************************/
void w_Data::on_Model_textChanged(const QString &arg1)
{
    if(ui->Model->text()!="")
    {
        int i;  QStringList Display;
        for(i=0;i<File.size();i++)
        {
            if(File.at(i).indexOf(ui->Model->text())>=0)
            {
                Display.append(File.at(i));
            }
        }
        dropdown_List->setRowCount(0);
        if(Display.size()>0)
        {
            dropdown_List->show();
            dropdown_List->setRowCount(Display.size());
            for(i=0;i<Display.size();i++)
            {
                QTableWidgetItem *pItem = new QTableWidgetItem(Display.at(i));
                pItem->setTextAlignment(Qt::AlignCenter);
                pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                dropdown_List->setItem(i,0,pItem);
            }
        }
        else
        {
            dropdown_List->hide();
        }
    }
    else {

    }

    qApp->processEvents();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      确定输入数据，dropdown_List设置隐藏
******************************************************************************/
void w_Data::on_Model_editingFinished()
{
    if(ui->Model->text()=="")
    {
       dropdown_List->hide();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.12
  * brief:      单击选择提示数据
******************************************************************************/
void w_Data::join_getData(int row,int colum=0)
{
    ui->Model->setText(dropdown_List->item(row,0)->text());
    dropdown_List->hide();
    colum = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.11
  * brief:      删除数据库的操作
******************************************************************************/
void w_Data::on_button_clear_clicked()
{
    int i,x;
    if(User_Data==User_Operator) {
        qDebug()<<"on_button_clear_clicked";
        Pri_Data_WMessage(tr("          当前用户模式为操作员     \n      无权限进行保存和修改       "));
        return;
    }
    QStringList tableviewfield;
    QStringList Table_head;
    label_Waring->show();
    QMessageBox *message=new QMessageBox(this);
    message->setWindowFlags(Qt::FramelessWindowHint);
    message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;padding:2px 4px;background-color: gray;height:390px;width:375px;}");
    message->setText(QString(tr("       确定删除数据库全部数据？     \n       删除完成后请重新开启机器       ")));
    message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
    message->addButton(QMessageBox::Cancel)->setStyleSheet("height:39px;width:75px;border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
    message->setButtonText(QMessageBox::Ok,QString(tr("确 定")));
    message->setButtonText(QMessageBox::Cancel,QString(tr("取 消")));
    message->setIcon(QMessageBox::Warning);
    int ret=message->exec();
    if(ret==QMessageBox::Ok)
    {
        Signal_Data_to_Main(QStringList(""),5,5);
        ui->tableWidget->setRowCount(0);

        student_model->clear();
        tableviewfield<<tr("data")<<tr("电机型号")<<tr("总结果")<<tr("时间")<<tr("温度")<<tr("工位")<<tr("编号")<<tr("用户")<<tr("总项目");
        for(i=0;i<(Data_Count.size()-3)/3;i++)
        {
            if(Data_Count.at((i+1)*3)==tr("电阻"))
            {
                for(x=0;x<8;x++)
                {
                    Table_head += QString(tr("电阻%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("电阻%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("电阻%1判定")).arg(QString::number(x+1));
                }
                Table_head += QString(tr("电阻不平衡度参数"));   Table_head += QString(tr("不平衡度"));  Table_head += QString(tr("不平衡度判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("反嵌"))
            {
                for(x=0;x<8;x++)
                {
                    Table_head += QString(tr("反嵌%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("反嵌%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("反嵌%1判定")).arg(QString::number(x+1));
                }
                Table_head += QString(tr("磁旋参数"));     Table_head += QString(tr("磁旋"));    Table_head += QString(tr("磁旋判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("绝缘"))
            {
                Table_head += QString(tr("绝缘参数"));  Table_head += QString(tr("绝缘"));   Table_head += QString(tr("绝缘判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("交耐"))
            {
                Table_head += QString(tr("交耐参数"));  Table_head += QString(tr("交耐"));   Table_head += QString(tr("交耐判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("直耐"))
            {

            }
            else if(Data_Count.at((i+1)*3)==tr("匝间"))
            {
                for(x=0;x<8;x++)
                {
                    Table_head += QString(tr("匝间%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("匝间%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("匝间%1判定")).arg(QString::number(x+1));
                }
            }
            else if(Data_Count.at((i+1)*3)==tr("电参"))
            {
                for(x=0;x<6;x++)
                {
                    Table_head += QString(tr("电参%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("电参%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("电参%1判定")).arg(QString::number(x+1));
                }
                for(x=0;x<6;x++)
                {
                    Table_head += QString(tr("转向%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("转向%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("转向%1判定")).arg(QString::number(x+1));
                }
            }
            else if(Data_Count.at((i+1)*3)==tr("PG"))
            {
                for(x=0;x<3;x++)
                {
                    Table_head += QString(tr("PG%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("PG%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("PG%1判定")).arg(QString::number(x+1));
                }
            }
            else if(Data_Count.at((i+1)*3)==tr("电感"))
            {
                for(x=0;x<8;x++)
                {
                    Table_head += QString(tr("电感%1参数")).arg(QString::number(x+1));
                    Table_head += QString(tr("电感%1")).arg(QString::number(x+1));
                    Table_head += QString(tr("电感%1判定")).arg(QString::number(x+1));
                }
                Table_head += QString(tr("电感不平衡度参数"));  Table_head += QString(tr("不平衡度"));   Table_head += QString(tr("不平衡度判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("堵转"))
            {
                Table_head += QString(tr("堵转参数"));  Table_head += QString(tr("堵转"));   Table_head += QString(tr("堵转判定"));
            }
            else if(Data_Count.at((i+1)*3)==tr("低启"))
            {
                Table_head += QString(tr("低启参数"));  Table_head += QString(tr("低启"));   Table_head += QString(tr("低启判定"));
            }
        }
        tableviewfield.append(Table_head);
        tableView_column = tableviewfield.size(); // 得到列数
        for(i=0;i<tableView_column;i++) // 设置表头
        {
            student_model->setHorizontalHeaderItem(i, new QStandardItem(tableviewfield.at(i)));
        }

        ui->tableView->setModel(student_model);
        ui->tableView->resizeColumnsToContents();   //  自动填充列宽度
//      model->setTable("TestDa");
//      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//      model->select();                            //  选取整个表的所有行
//      ui->tableView->setModel(model);
    }
    if(ret==QMessageBox::Cancel)
    {

    }
    label_Waring->hide();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.11
  * brief:      进行两个表格的轮流显示操作
******************************************************************************/
void w_Data::on_button_change_clicked()
{
    if(ui->button_change->text()==QString(tr("详细数据")))
    {
        ui->button_change->setText(tr("总数据"));
//        if(Data_Dispaly==1)
//        {
//            Pri_Data_WMessage(tr("      数据量较大，建议导出数据查看      "));
//        }
        ui->tableWidget->hide();
        ui->tableView->show();
    }
    else if(ui->button_change->text()==QString(tr("总数据")))
    {
        ui->button_change->setText(tr("详细数据"));
        ui->tableWidget->show();
        ui->tableView->hide();
    }
}



