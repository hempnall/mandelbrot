#include "mandelbrot.h"
#include "MandelbrotCalculator.h"
#include <QDebug>

float proportionOfZoom(int x, int xrange,float start, float end) {
    return ((float) x / xrange) * (end - start) + start;
}


Mandelbrot::Mandelbrot(QQuickPaintedItem* parent)
    : QQuickPaintedItem(parent)
{

}

Mandelbrot::~Mandelbrot()
{

}

void Mandelbrot::paint(QPainter *painter) {

    MandelbrotCalculator::calcMandelbrot(
                    painter,
                    xRes_,yRes_,
                    xFrom_,xTo_,
                    yFrom_,yTo_
                );


}

void Mandelbrot::zoomIn(int x, int y, int width, int height) {

    float xStart = proportionOfZoom(x , xRes_ , xFrom_,xTo_);
    float xEnd = proportionOfZoom(x + width, xRes_ , xFrom_,xTo_);
    float yStart = proportionOfZoom(y , yRes_ , yFrom_,yTo_);
    float yEnd = proportionOfZoom(y + height, yRes_ , yFrom_,yTo_);

    setXFrom( xStart);
    setXTo( xEnd);
    setYFrom( yStart);
    setYTo( yEnd);

    update();

}

float Mandelbrot::xFrom() const {
    return xFrom_;
}

float Mandelbrot::yFrom() const {
   return yFrom_;
}

float Mandelbrot::xTo() const   {
  return xTo_;
}

float Mandelbrot::yTo() const   {
  return yTo_;
}

void Mandelbrot::setXFrom(const float xFrom)    {
  if (xFrom_ != xFrom) {
    xFrom_ = xFrom;
    emit xFromChanged();
  }
}

void Mandelbrot::setXTo(const float xTo)    {
    if (xTo_ != xTo) {
        xTo_ = xTo;
        emit xToChanged();
    }
}

void Mandelbrot::setYFrom(const float yFrom)    {
    if (yFrom != yFrom_) {
        yFrom_ = yFrom;
        emit yFromChanged();
    }
}

void Mandelbrot::setYTo(const float yTo)    {
    if (yTo != yTo_)    {
        yTo_ = yTo;
        emit yToChanged();
    }
}

int Mandelbrot::xRes() const    {

    return xRes_;
}

int Mandelbrot::yRes() const    {
    return yRes();
}

void Mandelbrot::setXRes(const int xRes)    {
    if (xRes != xRes_) {
        xRes_ = xRes;
        emit xResChanged();
    }
}


void Mandelbrot::setYRes(const int yRes)    {
    if (yRes != yRes_) {
        yRes_ = yRes;
        emit yResChanged();
    }
}
