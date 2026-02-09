#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void getApardon( const std::string &target )
{
   std::cout << target << " has been pardoned by " << "Zaphod Beeblebrox"
             << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( void )
  : AForm( "PresidentialPardonForm", 25, 5 )
{
   _target = "defaultPardonedTarget";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target )
  : AForm( "PresidentialPardonForm", 25, 5 )
{
   _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other )
  : AForm( "PresidentialPardonForm", 25, 5 )
{
   _target = other._target;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
{
   if ( this != &other )
   {
      AForm::operator=( other );
      _target = other._target;
   }

   return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

void PresidentialPardonForm::execute( const Bureaucrat &executer ) const
{
   if ( !isSigned() )
      throw AForm::NotSignedException();
   if ( executer.getGrade() <= getExecuteGrade() )
      getApardon( _target );
   else
      throw Bureaucrat::GradeTooLowException();
}
