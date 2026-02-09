#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
   private:
      AForm *( Intern::*_forms[ 3 ] )( std::string const & );
      std::string _formNames[ 3 ];

   public:
      Intern( void );
      Intern( const Intern & );
      Intern &operator=( const Intern & );
      ~Intern( void );

      AForm *makeForm( const std::string &, const std::string & );
      AForm *CreateRobotomy( std::string const & );
      AForm *CreateShrubbery( std::string const & );
      AForm *CreatePresidentailPardon( std::string const & );
};

#endif
