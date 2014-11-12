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
#include <QSettings>
#include <QFile>
#include <QCryptographicHash>

using namespace std;

class Serial{
public:
    int j;
    static QList<QSerialPortInfo> com_ports_info;
    QList<QSerialPort> com_ports;
//    QSerialPort COM;
    Serial();
    void update_com_list(QList<QSerialPortInfo> com_ports);
    void newserial(const QSerialPortInfo &portname, QSerialPort *COM);
};
Serial::Serial(){

    cout<<"THis is SPARTA"<<endl;
    QMessageBox Msg;
    Msg.setText("Constructor executed");
    Msg.exec();
}

void Serial::update_com_list(QList<QSerialPortInfo> com_ports=com_ports_info){
    com_ports.clear();
    QList<QSerialPortInfo> info=QSerialPortInfo::availablePorts();
    int size=info.size();
    for(int i = 0;i<size;i++){
        com_ports.insert(i,info[i]);
    }
}

void Serial::newserial(const QSerialPortInfo &portname,QSerialPort* COM)
{
    COM->setPort(portname);
    COM->open(QIODevice::ReadWrite);
    COM->setBaudRate(2400);
    COM->setDataBits(QSerialPort::Data8);
    COM->setParity(QSerialPort::NoParity);
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    cout<<"Hello QT"<<endl;
//    Serial ser;
//    ser.j=7;
    cout<<"after sp"<<endl;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            QString qs=info.portName();
            cout<<qs.toStdString();
    }

    QSettings conf("E:/Projects/QT/HW/config.ini",QSettings::IniFormat);
    conf.sync();
    const QStringList sections=conf.childGroups();
    foreach(const QString &section,sections)
    {
//        QString sec=section.childGroups();
        cout<<section.toStdString()<<endl;
    }

    conf.beginGroup("files");
    const QStringList files=conf.childKeys();
    foreach(const QString &punkt,files)
    {
        cout<<punkt.toStdString()<<endl;
        cout<<conf.value(punkt).toString().toStdString()<<endl;
        QFile *file=new QFile(conf.value(punkt).toString());
        if(file->open(QFile::ReadWrite)){
            cout<<"opaned"<<endl;
        }
        QByteArray income=file->readAll();
        QByteArray hash=QCryptographicHash::hash(income,QCryptographicHash::Md5);
        cout<<"hash:"<<endl;
        QByteArray hash_hex=hash.toHex();
        for(int i=0;i<hash_hex.size();i++){
            cout<<hash_hex[i];
        }
        cout<<endl<<"hash end"<<endl;
        file->close();
        delete file;
    }

    const QStringList subsection=conf.allKeys();
    foreach(const QString &punkt,subsection)
    {
        cout<<punkt.toStdString()<<endl;
    }

//    QString app = QApplication::applicationDirPath();
//    cout<<app.toStdString();
    return a.exec();
}
