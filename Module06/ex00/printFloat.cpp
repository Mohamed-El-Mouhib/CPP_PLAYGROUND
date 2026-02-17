#include "Converter.hpp"

void checkFloatBoundariesAndPrint( float value, bool hasNoLeft )
{
   if ( !hasNoLeft )
      std::cout << "float: nanf\n";
   else
      std::cout << "float: " << std::fixed << std::setprecision( 1 ) << value
                << "f\n";
}

void printFloat( std::string &str, InType type )
{
   double value;
   int endIter;
   char *endptr;
   bool hasNoLeft;

   if ( type == _CHAR )
      checkFloatBoundariesAndPrint( static_cast<float>( str[ 0 ] ), true );
   else if ( type == _INT )
   {
      value     = static_cast<float>( strtoint( str.c_str(), &endIter ) );
      hasNoLeft = isEmptyStr( str.c_str() + endIter );
      checkFloatBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _FLOAT )
   {
      value     = strtod( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr + 1 );
      checkFloatBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _DOUBLE )
   {
      value     = strtod( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr );
      checkFloatBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( str == "+inf" || str == "-inf" || str == "nanf" )
      std::cout << "float: " << str << "\n";
   else
      std::cout << "float: nanf\n";
}
