#include "widget.h"

#include<QFile>

#include<QTextStream>

#include <QApplication>

QString readTextFile(QString path)

{

    QFile file(path);

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))

    {

        QTextStream in(&file);

        return in.readAll();

    }

    return " ";

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString css=readTextFile(":/style/sheet.txt");//Copy the path of text document[shown in steps video]

    if(css.length()>0)
    {

      a.setStyleSheet(css);

}
    Widget w;
    w.show();
    return a.exec();
}
