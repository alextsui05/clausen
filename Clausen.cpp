#include "Clausen.h"
#include <boost/math/special_functions/zeta.hpp>
namespace ucd {

double Clausen( double theta )
{
    if ( theta == 0 )
        return 0;
    while ( theta < 0 )
        theta += 2*M_PI;
    while ( theta > 2*M_PI )
        theta -= 2*M_PI;
    if ( theta > M_PI )
    {
        theta -= M_PI;
        double diff = theta - M_PI/2;
        theta -= 2*diff;
        return -Clausen( theta );
    }

    // precompute coefficients for the partial sum part of the Clausen
    // function
    static std::vector< double > coeff;
    if ( coeff.size( ) == 0 )
    {
        std::vector< double > num, den, frac;
        for ( int i = 1; i < 20; ++i )
        {
            num.push_back( boost::math::zeta( 2*i ) );
            den.push_back( i*(2*i + 1) );
            frac.push_back( num.back( ) / den.back( ) );
        }

        coeff.push_back( 0 );
        for ( int i = 0; i < frac.size( ); ++i )
        {
            coeff.push_back( 0 );
            coeff.push_back( frac[i] );
        }
    }

    double res = 1 - log( theta );

    double hornerSum = 0.0;
    double term = theta / (2 * M_PI);
    for ( int i = coeff.size( ) - 1; i >= 0; --i )
    {
        if ( i == coeff.size( ) - 1 )
            hornerSum = coeff[i];
        else
            hornerSum = coeff[i] + hornerSum*term;
    }
    res += hornerSum;

    return theta*res;
}

} // namespace ucd
