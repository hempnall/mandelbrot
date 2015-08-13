#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QQuickPaintedItem>






class Mandelbrot
        : public QQuickPaintedItem
{
    Q_OBJECT


    Q_PROPERTY(float xFrom READ xFrom WRITE setXFrom)
    Q_PROPERTY(float xTo READ xTo WRITE setXTo)
    Q_PROPERTY(float yFrom READ yFrom WRITE setYFrom)
    Q_PROPERTY(float yTo READ yTo WRITE setYTo)
    Q_PROPERTY(int xRes READ xRes WRITE setXRes)
    Q_PROPERTY(int yRes READ yRes WRITE setYRes)




public:


    Mandelbrot(QQuickPaintedItem* parent = 0);
    ~Mandelbrot();

    float xFrom() const;
    float yFrom() const;
    float xTo() const;
    float yTo() const;
    int xRes() const;
    int yRes() const;

    void setXFrom(const float xFrom);
    void setXTo(const float xTo);
    void setYFrom(const float yFrom);
    void setYTo(const float yTo);
    void setXRes(const int xRes);
    void setYRes(const int yRes);


    void paint(QPainter *painter);

    Q_INVOKABLE void zoomIn(int x,int y,int width , int height);

private:


    float xFrom_;
    float xTo_;
    float yFrom_;
    float yTo_;
    int xRes_;
    int yRes_;

};

#endif // MANDELBROT_H
