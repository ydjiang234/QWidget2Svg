#include "QWidget2Svg.h"
#include <QSvgGenerator>
#include <QTemporaryFile>
#include <QFile>
#include <QPainter>
#include <QDataStream>

QWidget2Svg::QWidget2Svg() {}

QWidget2Svg::~QWidget2Svg() {}



bool QWidget2Svg::save(QWidget *w, QString path)
{
    QFile *file = new QFile(path);
    file->open(QFile::WriteOnly);
    file = this->render<QFile>(w, file);
    //QByteArray array = file->readAll();
    //std::cout<<array.isEmpty()<<std::endl;
    return true;
}

QByteArray QWidget2Svg::getBytes(QWidget *w)
{
    QTemporaryFile *file = new QTemporaryFile();
    file->open();
    file = this->render<QTemporaryFile>(w, file);
    file->seek(0);
    QByteArray array = file->readAll();
    return array;
}


template <class T>
T* QWidget2Svg::render(QWidget *w, T *file)
{
    QSvgGenerator *svg = new QSvgGenerator();
    svg->setOutputDevice(file);
    QPainter *painter = new QPainter(svg);
    w->render(painter);
    painter->end();
    return file;
}
template QFile* QWidget2Svg::render(QWidget *w, QFile *file);
template QTemporaryFile* QWidget2Svg::render(QWidget *w, QTemporaryFile *file);
