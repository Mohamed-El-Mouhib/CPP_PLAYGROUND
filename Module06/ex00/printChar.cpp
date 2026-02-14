#include "Converter.hpp"

void checkCharBoundariesAndPrint( long int value, bool hasNoLeft )
{
   if ( !hasNoLeft || value > 255 )
      std::cout << "char: Impossible\n";
   else if ( value >= 32 && value <= 127 )
      std::cout << "char: '" << static_cast<char>( value ) << "'\n";
   else
      std::cout << "char: Non displayable\n";
}

void printChar( std::string &str, InType type )
{
   long ascii;
   int endIter;
   char *endptr;
   bool hasNoLeft;

   if ( type == _CHAR )
      checkCharBoundariesAndPrint( str[ 0 ], true );
   else if ( type != _NAVT )
   {
      if ( type == _INT )
      {
         ascii     = strtoint( str.c_str(), &endIter );
         hasNoLeft = isEmptyStr( str.c_str() + endIter );
      }
      else
      {
         ascii = round( strtod( str.c_str(), &endptr ) );
         if ( type == _FLOAT )
            hasNoLeft = isEmptyStr( endptr + 1 );
         else
            hasNoLeft = isEmptyStr( endptr );
      }
      checkCharBoundariesAndPrint( ascii, hasNoLeft );
   }
   else
      std::cout << "char: Impossible\n";
}
