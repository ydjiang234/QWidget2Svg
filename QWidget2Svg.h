#ifndef QWIDGET2SVG_H
#define QWIDGET2SVG_H


class QWidget2Svg
{
public:
    QWidget2Svg();
    ~QWidget2Svg();
    bool save(QWidget *w, QString path);
};

#endif // QWIDGET2SVG_H
