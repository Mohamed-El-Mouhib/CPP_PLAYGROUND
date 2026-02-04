#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main( void )
{
   bureaucrat c( "thomas", 1 );
   try
   {
      bureaucrat a( "tom", 55 );
      bureaucrat b( "albert", 150 );
      bureaucrat d( c );

      std::cout << d << std::endl;
      std::cout << b << std::endl;
      std::cout << a << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }

   try
   {
      bureaucrat d( c );
      d.incGrade();
      std::cout << d << std::endl;
      d.decGrade();
      std::cout << d << std::endl;
      d.decGrade();
      std::cout << d << std::endl;
      d.decGrade();
      std::cout << d << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }
}
