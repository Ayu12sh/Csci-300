// CReadFile.cpp
#include <QtDebug>
#include "CReadFile.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFile>

CReadFile::CReadFile(QObject *parent) : QObject(parent) {}


void CReadFile::readAndOrganizeMovies()
{
    QDir directory("//Users/ayushsilwal/Documents/CS200_finalQT");

    QFile file(directory.filePath("input.txt"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QStack<QString> stackOdd;
    QStack<QString> stackEven;

    QTextStream in(&file);
    int lineNumber = 1;
    while (!in.atEnd()) {
        QString title = in.readLine();
        //qDebug() << "Processing line: " << title;

        if (lineNumber % 2 == 0) {
            stackEven.push(title);
        } else {
            stackOdd.push(title);
        }
        ++lineNumber;
    }
    qDebug() << "Odd stack size:" << stackOdd.size();
    qDebug() << "Even stack size:" << stackEven.size();
    file.close();


    emit moviesLoaded(stackOdd, stackEven);
}
