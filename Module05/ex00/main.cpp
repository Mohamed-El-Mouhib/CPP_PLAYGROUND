#include "Bureaucrat.hpp"
#include <exception>

int main( void )
{
   try
   {
      bureaucrat a( "tom", 555 );
   }
   catch ( std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }
}
