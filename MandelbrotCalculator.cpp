#include "MandelbrotCalculator.h"
#include <QPen>
#include <QPainter>

void MandelbrotCalculator::calcMandelbrot(QPainter *painter, int xres, int yres, float xmin, float xmax, float ymin, float ymax) {


    QPen red(Qt::red);
    QPen qblack(Qt::black);

    painter->setPen(red);

    float xstep = (xmax - xmin) / xres;
    float ystep = (ymax - ymin) / yres;


    for (int x = 0;x<xres ; ++x) {
        for (int y  = 0 ; y < yres ; ++y) {

            painter->setPen(qblack);
            painter->drawPoint(x,y);

            std::complex<float> c(xmin + x * xstep, ymin + y * ystep);
            std::complex<float> z(0,0);

            for (int iter =0 ; iter < 25 ; ++iter) {

                z = (z * z) + c;

                if (std::abs(z) > 1000000) {

                    MandelbrotCalculator::setColour(painter,30,iter);
                    painter->drawPoint(x,y);
                    break;
                }
            }

        }
    }

}




void MandelbrotCalculator::calcJulia(QPainter* painter , std::complex<float> c, int xres, int yres, float  xmin,float xmax , float ymin, float ymax)   {


    QPen red(Qt::red);
    painter->setPen(red);

    float xstep = (xmax - xmin) / xres;
    float ystep = (ymax - ymin) / yres;


    for (int x = 0;x<xres ; ++x) {
        for (int y  = 0 ; y < yres ; ++y) {



            std::complex<float> z(xmin + x * xstep, ymin + y * ystep);

            for (int iter =0 ; iter < 100 ; ++iter) {

                z = (z * z) + c;

                if (std::abs(z) > 1000000) {
                    painter->drawPoint(x,y);
                    break;
                }
            }

        }
    }

}

void MandelbrotCalculator::setColour(QPainter* painter, float max,float count) {

    float rat = count / max ;

    if ( rat > 0.8f  ) {

        painter->setPen(Qt::red);

    } else if ( rat > 0.7f ) {

        painter->setPen(Qt::yellow);

    } else if ( rat > 0.6f ) {

        painter->setPen(Qt::green);

    } else if ( rat > 0.5f ) {

        painter->setPen(Qt::blue);

    } else if ( rat > 0.4f ) {

        painter->setPen(Qt::white);

    } else if ( rat > 0.3f ) {

        painter->setPen(Qt::gray);

//    } else if ( rat > 0.2f ) {

    } else {

        painter->setPen(Qt::black);

    }

}



