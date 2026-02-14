#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

enum InType
{
   _NAVT = 0, // not a type
   _INT,      // not a type
   _DOUBLE,   // floating number type
   _FLOAT,    // floating number type
   _CHAR      // character type
};

void printDouble( std::string &str, InType type );
void printFloat( std::string &str, InType type );
void printChar( std::string &str, InType type );
void printInt( std::string &str, InType type );
InType whichType( std::string &str );

inline bool isEmptyStr( const char *str )
{
   if ( !str )
      return true;
   for ( int i = 0; str[ i ]; ++i )
   {
      if ( !std::isspace( str[ i ] ) )
         return false;
   }
   return true;
}

inline long int strtoint( const char *str, int *endptr )
{
   int i;
   long int numbers;
   int sign;
   int offs;

   i       = 0;
   numbers = 0;
   offs    = 0;
   sign    = 1;
   while ( std::isspace( str[ i ] ) )
      i++;
   if ( str[ i ] == '-' || str[ i ] == '+' )
   {
      if ( str[ i ] == '+' )
         ;
      if ( str[ i ] == '-' )
         sign *= -1;
      i++;
   }

   while ( str[ i ] && std::isdigit( str[ i ] ) )
   {
      if ( offs > 11 )
      {
         if ( endptr )
            *endptr = i;
         return 0;
      }
      numbers = numbers * 10 + ( str[ i ] - '0' );
      offs++;
      i++;
   }
   if ( endptr )
      *endptr = i;
   return ( numbers * sign );
}

#endif
