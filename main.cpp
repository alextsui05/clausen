#include <iostream>
#include <cmath>
#include "Clausen.h"

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        std::cout << "Give a value between 0 and M_PI\n";
        return 0;
    }
    double theta = atof( argv[1] );

    std::cout.precision( 16 );
    double actual = ucd::Clausen( theta );
    std::cout << actual << "\n";

    return 0;
}
