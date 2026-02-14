#include "Converter.hpp"

void checkIntBoundariesAndPrint( long int value, bool hasNoLeft )
{
   if ( value <= INT_MAX && value >= INT_MIN && hasNoLeft )
      std::cout << "int: " << value << "\n";
   else
      std::cout << "int: " << "Impossible\n";
}

void printInt( std::string &str, InType type )
{
   long value;
   int endIter;
   char *endptr;
   bool hasNoLeft;

   if ( type == _CHAR )
      std::cout << "int: " << static_cast<int>( str[ 0 ] ) << "\n";
   else if ( type == _INT )
   {
      value     = strtoint( str.c_str(), &endIter );
      hasNoLeft = isEmptyStr( str.c_str() + endIter );
      checkIntBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _FLOAT )
   {
      value     = strtof( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr + 1 );
      checkIntBoundariesAndPrint( value, hasNoLeft );
   }
   else if ( type == _DOUBLE )
   {
      value     = strtod( str.c_str(), &endptr );
      hasNoLeft = isEmptyStr( endptr );
      checkIntBoundariesAndPrint( value, hasNoLeft );
   }
   else
      std::cout << "int: Impossible\n";
}
