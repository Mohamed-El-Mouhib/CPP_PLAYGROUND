#include "Converter.hpp"

static int countDots( std::string &str )
{
   int dot = 0;

   for ( size_t i = 0; i < str.length(); ++i )
   {
      if ( str[ i ] == '.' )
         dot++;
   }

   return dot;
}

static int countF( std::string &str )
{
   int F = 0;

   for ( size_t i = 0; i < str.length(); ++i )
   {
      if ( str[ i ] == 'f' )
         F++;
   }

   return F;
}

static bool isValidNumbeer( std::string &str )
{
   for ( size_t i = 0; i < str.length(); ++i )
   {
      if ( str[ i ] != '.' && str[ i ] != 'f' && !std::isspace( str[ i ] ) &&
           !std::isdigit( str[ i ] ) && str[ i ] != '-' && str[ i ] != '+' )
         return false;
   }

   return true;
}

static bool isCharacter( std::string &str )
{
   if ( str.length() != 1 || std::isdigit( str[ 0 ] ) )
      return false;
   return true;
}

InType whichType( std::string &str )
{
   int dots;      // how many dots there
   int fInstance; // how many 'f' there

   dots      = countDots( str );
   fInstance = countF( str );
   if ( isCharacter( str ) )
      return _CHAR;
   else if ( isValidNumbeer( str ) && dots <= 1 && fInstance <= 1 )
   {
      if ( !dots && !fInstance )
         return _INT;
      if ( fInstance && dots )
         return _FLOAT;
      return _DOUBLE;
   }

   return _NAVT;
}
