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
  xFrom_ = xFrom;
}

void Mandelbrot::setXTo(const float xTo)    {
    xTo_ = xTo;
}

void Mandelbrot::setYFrom(const float yFrom)    {
    yFrom_ = yFrom;
}

void Mandelbrot::setYTo(const float yTo)    {
  yTo_ = yTo;
}

int Mandelbrot::xRes() const    {
    return xRes_;
}

int Mandelbrot::yRes() const    {
    return yRes();
}

void Mandelbrot::setXRes(const int xRes)    {
    xRes_ = xRes;
}


void Mandelbrot::setYRes(const int yRes)    {
    yRes_ = yRes;
}
