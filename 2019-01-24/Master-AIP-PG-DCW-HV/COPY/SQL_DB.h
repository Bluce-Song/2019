#ifndef SQL_DB_H
#define SQL_DB_H

#include <QThread>
#include <QDir>
#include <QProcess>
#include <linux_sql.h>
#include <QEventLoop>
#include <QDateTime>
#include <QTextCodec>
#include <define.h>
#include <QTimer>

class SQL_DB : public QThread
{
    Q_OBJECT
public:
 //   SQL_DB();
    explicit SQL_DB(QObject *parent = 0);
    void run();

private:
    int System_currentProj_Number;
    QStringList currentProj_Real;
    QStringList currentProj;
    int ACW_Display;
    QString Motor_PG_Commmon;

    bool sdcard_exist;
    LINUX_SQL SQL_U;
    void Save_U_Data();
    void Max_Id_Data();
    void Test_CountData();
    void Delete_Data_Data();
    void Big_DataForm();
    int  Get_BigData_Row;

    QStringList Search;

    QString  list_name;
    QString  list_start_time;
    QString  list_stop_time;   // 得到搜索数据
    QString  USB_name;
    QStringList Big_List;

    bool DB_Save_run;
    bool DB_MaxID_run;
    bool Test_Checking;
    bool Big_Data_run;
    int  data_length;
signals:
    void Singal_Data_Scale(QStringList,int,int);

public slots:
     void Slot_Data_to_SQLDB(QString,QStringList,int);
};

#endif // SQL_DB_H
