#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main( void )
{
   int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
   size_t const amounts_size( sizeof( amounts ) / sizeof( int ) );

   std::vector<int> cnT( amounts, amounts + amounts_size );

   try
   {
      int a = easyfind( cnT, 1 );
      std::cout << a << std::endl;
   }
   catch ( const std::exception &_ )
   {
      std::cerr << _.what() << std::endl;
      return 1;
   }

   return 0;
}
