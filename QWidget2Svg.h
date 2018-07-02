#ifndef QWIDGET2SVG_H
#define QWIDGET2SVG_H
#include <QWidget>
#include <QByteArray>


class QWidget2Svg
{
public:
    QWidget2Svg();
    ~QWidget2Svg();
    bool save(QWidget *w, QString path);
    QByteArray getStream(QWidget *w);
private:
    template <class T>
    T* render(QWidget *w, T *file);
};

#endif // QWIDGET2SVG_H
