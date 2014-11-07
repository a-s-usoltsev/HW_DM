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
        file->close();
    }
//    int size=sections.size();
//    cout<<"size="<<size<<endl;
//    for(int i=0;i<size;i++)
//    {
//        cout<<"section"<<i<<" is "<<sections[i].toStdString()<<endl;
//    }
    const QStringList subsection=conf.allKeys();
    foreach(const QString &punkt,subsection)
    {
        cout<<punkt.toStdString()<<endl;
    }

//    QString app = QApplication::applicationDirPath();
//    cout<<app.toStdString();
    return a.exec();
}
