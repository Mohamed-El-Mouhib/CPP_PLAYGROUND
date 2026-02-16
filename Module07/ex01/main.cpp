#include "iter.hpp"
#include <iostream>

void print( int &nbr )
{
   static size_t i;

   nbr++;
   std::cout << "parameter [" << i << "]: " << nbr << std::endl;
   ++i;
}

void print( const int &nbr )
{
   static size_t i;

   std::cout << "parameter [" << i << "]: " << nbr << std::endl;
   ++i;
}

int main( void )
{
   int arr[]         = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   const size_t size = sizeof( arr ) / sizeof( arr[ 0 ] );

   iter( arr, size, print );
}
