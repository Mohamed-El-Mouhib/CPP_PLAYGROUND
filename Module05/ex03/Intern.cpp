#include "Intern.hpp"

Intern::Intern( void )
{
   _forms[ 0 ]     = &Intern::CreateRobotomy;
   _forms[ 1 ]     = &Intern::CreateShrubbery;
   _forms[ 2 ]     = &Intern::CreatePresidentailPardon;
   _formNames[ 0 ] = "robotomy request";
   _formNames[ 1 ] = "shrubbery request";
   _formNames[ 2 ] = "presidentail pardon request";
}

Intern::Intern( const Intern &other )
{
   _forms[ 0 ]     = other._forms[ 0 ];
   _forms[ 1 ]     = other._forms[ 1 ];
   _forms[ 2 ]     = other._forms[ 2 ];
   _formNames[ 0 ] = other._formNames[ 0 ][ 0 ];
   _formNames[ 1 ] = other._formNames[ 1 ][ 1 ];
   _formNames[ 2 ] = other._formNames[ 2 ][ 2 ];
}

Intern &Intern::operator=( const Intern &other )
{
   (void)other;
   return *this;
}

Intern::~Intern( void )
{
}

AForm *Intern::CreateRobotomy( std::string const &target )
{
   return new RobotomyRequestForm( target );
}

AForm *Intern::CreateShrubbery( std::string const &target )
{
   return new ShrubberyCreationForm( target );
}

AForm *Intern::CreatePresidentailPardon( std::string const &target )
{
   return new PresidentialPardonForm( target );
}

AForm *Intern::makeForm( const std::string &formName,
                         const std::string &formTarget )
{
   AForm *ptr;

   ptr = NULL;
   for ( int i = 0; i < 3; ++i )
   {
      if ( formName == _formNames[ i ] )
         ptr = ( this->*_forms[ i ] )( formTarget );
   }
   if ( !ptr )
      throw std::invalid_argument( "Invalid Form name" );
   return ptr;
}
