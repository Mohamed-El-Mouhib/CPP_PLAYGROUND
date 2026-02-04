#include "Bureaucrat.hpp"

int main( void )
{
   try
   {
      Bureaucrat a( "thomas", 1 );
      std::cout << a << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cout << e.what() << std::endl;
   }

   try
   {
      Bureaucrat a( "arthre", 1 );
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
      Bureaucrat a( "X Æ A-Xii", 149 );
      a.decGrade();
      Bureaucrat b( a );
      std::cout << a.getName() << " ";
      b.decGrade();
   }
   catch ( std::exception &e )
   {
      std::cout << e.what() << std::endl;
   }
}
