#include "Bureaucrat.hpp"

static Grade GradeValidate( Grade grade )
{
   if ( grade > 150 )
      throw Bureaucrat::GradeTooLowException();
   else if ( grade < 1 )
      throw Bureaucrat::GradeTooHighException();
   return grade;
}

Bureaucrat::Bureaucrat( void ) : _name( "Bureaucrat' default" ), _grade( 150 )
{
}

Bureaucrat::Bureaucrat( const Bureaucrat &other )
  : _name( other._name ), _grade( GradeValidate( other._grade ) )
{
}

Bureaucrat::Bureaucrat( const std::string &name, Grade grade )
  : _name( name ), _grade( GradeValidate( grade ) )
{
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
   if ( this != &other )
   {
      _name  = other._name;
      _grade = other._grade;
   }
   return *this;
}

Bureaucrat::~Bureaucrat( void )
{
}

void Bureaucrat::incGrade( void )
{
   _grade--;
   GradeValidate( _grade );
}

void Bureaucrat::decGrade( void )
{
   _grade++;
   GradeValidate( _grade );
}

void Bureaucrat::signForm( Form &form )
{
   try
   {
      form.beSigned( *this );
      std::cout << _name << " signed " << form << std::endl;
   }
   catch ( std::exception &e )
   {
      std::cout << _name << " couldn’t sign " << form << " because " << e.what()
                << std::endl;
   }
}

std::string Bureaucrat::getName( void ) const
{
   return _name;
}

Grade Bureaucrat::getGrade( void ) const
{
   return _grade;
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &c )
{
   out << c.getName() << ", Bureaucrat grade " << c.getGrade() << "."
       << std::endl;
   return out;
}
