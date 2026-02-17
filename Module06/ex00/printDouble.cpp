#include "Converter.hpp"
#include "ScalarConverter.hpp"

void checkDoubleBoundariesAndPrint( float value, bool hasNoLeft )
{
   if ( !hasNoLeft )
      std::cout << "double: nanf\n";
   else
      std::cout << "double: " << std::fixed << std::setprecision( 1 ) << value
                << "\n";
}

void printDouble( std::string &str, InType type )
{
   double value;
   int endIter;
   char *endptr;
   bool hasNoLeft;

   if ( type == _CHAR )
      checkDoubleBoundariesAndPrint( static_cast<double>( str[ 0 ] ), true );
   else if ( type == _INT )
   {
      value     = static_cast<double>( strtoint( str.c_str(), &endIter ) );
      hasNoLeft = isEmptyStr( str.c_str() + endIter );
      checkDoubleBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _FLOAT )
   {
      value     = strtod( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr + 1 );
      checkDoubleBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _DOUBLE )
   {
      value     = strtod( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr );
      checkDoubleBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( str == "+inf" || str == "-inf" || str == "nan" )
      std::cout << "double: " << str << "\n";
   else
      std::cout << "double: nan\n";
}
