#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
   try
   {
      Bureaucrat bart( "garmon", 137 );
      ShrubberyCreationForm a( "damn" );
      bart.signAForm( a );
      bart.executeForm( a );
   }
   catch ( const std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }

   std::cout << std::endl;
   std::cout << "---------------------------------------------------------"
             << std::endl;

   std::cout << std::endl;
   try
   {
      Bureaucrat __( "hornet", 45 );
      RobotomyRequestForm b( "garry" );
      __.signAForm( b );
      __.executeForm( b );
   }
   catch ( const std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }

   std::cout << std::endl;
   std::cout << "---------------------------------------------------------"
             << std::endl;

   std::cout << std::endl;
   try
   {
      PresidentialPardonForm b( "garry" );
      Bureaucrat __( "hornet", 5 );
      b.beSigned( __ );
      __.executeForm( b );
   }
   catch ( const std::exception &e )
   {
      std::cerr << e.what() << std::endl;
   }
   return 0;
}
