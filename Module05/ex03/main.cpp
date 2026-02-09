#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
   Bureaucrat _( "Bender", 15 );
   try
   {
      Intern someRandomIntern;
      AForm *rrf;
      rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
      _.signAForm( *rrf );
      rrf->execute( _ );
      delete rrf;
   }
   catch ( const std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }

   try
   {
      Intern someRandomIntern;
      AForm *rrf;
      rrf = someRandomIntern.makeForm( "join club request", "Travler" );
      _.signAForm( *rrf );
      rrf->execute( _ );
      delete rrf;
   }
   catch ( const std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }
}
