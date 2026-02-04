#include "Bureaucrat.hpp"

int main()
{
   try
   {
      Bureaucrat bob( "Bob", 2 );
      Form a( "A", 1, 1 );

      std::cout << bob;
      bob.incGrade();
      bob.signForm( a );
   }
   catch ( const std::exception &e )
   {
      std::cout << e.what() << std::endl;
      return 1;
   }
   return 0;
}
