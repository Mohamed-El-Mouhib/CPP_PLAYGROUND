#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main( void )
{
   try
   {
      bureaucrat a( "thomas", 1 );
      std::cout << a << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cout << e.what() << std::endl;
   }

   try
   {
      bureaucrat a( "arthre", 1 );
      std::cout << a.getName() << " ";
      a.incGrade();
      std::cout << a << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cout << e.what() << std::endl;
   }

   try
   {
      bureaucrat a( "X Æ A-Xii", 149 );
      a.decGrade();
      bureaucrat b( a );
      std::cout << a.getName() << " ";
      b.decGrade();
   }
   catch ( std::exception &e )
   {
      std::cout << e.what() << std::endl;
   }
}
