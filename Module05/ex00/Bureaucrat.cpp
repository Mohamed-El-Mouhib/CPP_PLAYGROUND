#include "Bureaucrat.hpp"

Grade GradeValidate( Grade grade )
{
   if ( grade > 150 )
      throw bureaucrat::GradeTooLowException();
   else if ( grade < 1 )
      throw bureaucrat::GradeTooHighException();
   return grade;
}

bureaucrat::bureaucrat( void ) : _name( "default bureaucrat" ), _grade( 150 )
{
}

bureaucrat::bureaucrat( const bureaucrat &other )
  : _name( other._name ), _grade( GradeValidate( other._grade ) )
{
}

bureaucrat::bureaucrat( const std::string &name, Grade grade )
  : _name( name ), _grade( GradeValidate( grade ) )
{
}

bureaucrat &bureaucrat::operator=( const bureaucrat &other )
{
   if ( this != &other )
   {
      _name  = other._name;
      _grade = other._grade;
   }
   return *this;
}

bureaucrat::~bureaucrat( void )
{
}

void bureaucrat::incGrade( void )
{
   _grade--;
   GradeValidate( _grade );
}

void bureaucrat::decGrade( void )
{
   _grade++;
   GradeValidate( _grade );
}

std::string bureaucrat::getName( void ) const
{
   return _name;
}

Grade bureaucrat::getGrade( void ) const
{
   return _grade;
}

std::ostream &operator<<( std::ostream &out, const bureaucrat &c )
{
   out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
   return out;
}
