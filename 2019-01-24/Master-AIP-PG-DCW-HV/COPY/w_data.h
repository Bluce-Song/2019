#ifndef W_DATA_H
#define W_DATA_H

#include <QDialog>
#include <QTimer>
#include <QDebug>
#include <linux_can.h>
#include <QDir>
#include <QProcess>
#include <stdio.h>
#include <define.h>
#include <qcalendarwidget.h>
#include <QMessageBox>
#include <QTableWidget>
#include <pwm_api.h>
#include <QSqlTableModel>
#include <QTextCodec>
#include <linux_sql.h>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <sys/statfs.h>
#include <stdio.h>
#include <linux_Thread.h>
#include <QThread>

namespace Ui {
class w_Data;
}

class w_Data : public QDialog
{
    Q_OBJECT
    
public:
    explicit w_Data(QWidget *parent = 0);
    ~w_Data();
    QStringList Data_Count;
    QStringList Data_All;
    QStringList File;
    void  Pub_Set_TableAll();
    void  Pub_Set_Data(QStringList);
    void  UDisk_Test(int,QString);
    void  Structure_Interface(QString,QString);

private:
    Ui::w_Data *ui;
    QTimer     *timer;
    QLabel     *label_Waring;
    QLabel     *u_disk;
    QCalendarWidget  *calendarWidget;
    QTableWidget     *dropdown_List;
//  QSqlTableModel   *model;
    QStandardItemModel *student_model;
    LINUX_CAN   can;
    LINUX_SQL   sqll;
    int         error;
    int         tableView_column;
    bool        Data_Dispaly;
    QString     usb_name;
    QString     pushbuttoned;
    QStringList model_test;
    QString  Motor_PG_Commmon;
    int     User_Data;
    int     ACW_display;

    int      scale_bar;
    int      U_time_count;
    bool     U_waiting;
    QTimer  *U_time;
    QLabel  *U_Exporting;

    void    mousePressEvent (QMouseEvent * event);
    void    Pri_Data_WMessage(QString);
    void    Judge_Max_ID(int);
    void    U_test_Finsh_time();

signals:
    void Signal_Data_to_Main(QStringList,int,int);
    void Singal_Data_to_Conf(QString,QStringList,int);

private slots:
    void on_back_clicked();
    void on_button_put_clicked();
    void on_button_start_clicked();
    void on_button_stop_clicked();
    void on_button_detailed_clicked();
    void on_button_clear_clicked();
    void on_button_change_clicked();
    void on_button_check_clicked();
    void on_button_in_clicked();
    void on_button_out_model_clicked();
    void on_Model_textChanged(const QString &arg1);
    void on_Model_editingFinished();
    void join_getData(int,int);
    void join_setData();
    void U_show_time();

public slots:
    void pubslot_display_scale(QStringList,int,int);

};

#endif // W_DATA_H
