#ifndef MANDELBROTC_H
#define MANDELBROTC_H



#include <complex>
#include <QPainter>

class MandelbrotCalculator
{


public:

    static void setColour(QPainter* painter, float max,float count);
    static void calcJulia(QPainter* painter,std::complex<float> c, int xres, int yres, float  xmin,float xmax , float ymin, float ymax);
    static void calcMandelbrot(QPainter* painter, int xres, int yres, float  xmin,float xmax , float ymin, float ymax);


};

#endif // MANDELBROTC_H
