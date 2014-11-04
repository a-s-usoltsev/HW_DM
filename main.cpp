#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include <iostream>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCore/QDebug>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QList>
#include <QString>

using namespace std;

class Serial{
public:
    int j;
    Serial();
};
Serial::Serial(){

    cout<<"THis is SPARTA"<<endl;
    QMessageBox Msg;
    Msg.setText("Constructor executed");
    Msg.exec();
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    cout<<"Hello QT"<<endl;
    Serial ser;
    ser.j=7;
    cout<<"after sp"<<endl;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            QString qs=info.portName();
            cout<<qs.toStdString();
    }
//    QSerialPortInfo as;
//    as.availablePorts();
    QList<int> ports;
//    ports=QSerialPortInfo::availablePorts();

    return a.exec();
}
