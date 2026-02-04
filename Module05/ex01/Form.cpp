#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static Grade GradeValidate( Grade grade )
{
   if ( grade > 150 )
      throw Form::GradeTooLowException();
   else if ( grade < 1 )
      throw Form::GradeTooHighException();
   return grade;
}

Form::Form( void )
  : _name( "default Form" ), _IsSigned( false ), _reqGrade( 150 ),
    _excGrade( 1 )
{
}

Form::Form( const Form &other )
  : _name( other._name ), _IsSigned( other._IsSigned ),
    _reqGrade( other._reqGrade ), _excGrade( other._excGrade )
{
}

Form::Form( const std::string &name, Grade reqGrade, Grade excuteGrade )
  : _name( name ), _IsSigned( false ), _reqGrade( GradeValidate( reqGrade ) ),
    _excGrade( GradeValidate( excuteGrade ) )
{
}

Form &Form::operator=( const Form &other )
{
   if ( this != &other )
   {
      _name     = other._name;
      _IsSigned = other._IsSigned;
      _reqGrade = other._reqGrade;
      _excGrade = other._excGrade;
   }

   return *this;
}

void Form::beSigned( const Bureaucrat &target )
{
   Grade targetGrade;

   targetGrade = target.getGrade();
   if ( targetGrade <= _reqGrade )
   {
      _IsSigned = true;
      return;
   }
   throw Form::GradeTooLowException();
}

std::string Form::getName( void ) const
{
   return _name;
}

bool Form::isSigned( void ) const
{
   return _IsSigned;
}

Grade Form::getRequiredGrade( void ) const
{
   return _reqGrade;
}

Grade Form::getExecuteGrade( void ) const
{
   return _excGrade;
}

std::ostream &operator<<( std::ostream &out, const Form &c )
{
   out << "Form: " << c.getName() << " require grade " << c.getRequiredGrade()
       << ", execute grade " << c.getExecuteGrade();
   return out;
}

Form::~Form( void )
{
}
