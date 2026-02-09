#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void setRandomness( void )
{
   srand( time( NULL ) );
}

static void drillSound( void )
{
   std::cout << ".......... HOLE MAKING SOUND.............\n";
}

static void RobotizedTarget( const std::string &target )
{
   if ( rand() % 2 )
      std::cout << target << " has been robotomized successfull" << std::endl;
   else
      std::cout << target << "'s Robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( void )
  : AForm( "RobotomyRequestForm", 72, 45 )
{
   _target = "RobotomyDefault";
   setRandomness();
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target )
  : AForm( "RobotomyRequestForm", 72, 45 )
{
   _target = target;
   setRandomness();
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
  : AForm( other.getName(), other.getRequiredGrade(), other.getExecuteGrade() )
{
   _target = other._target;
   setRandomness();
}

RobotomyRequestForm &
RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
   if ( this != &other )
   {
      AForm::operator=( other );
      _target = other._target;
   }

   return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

void RobotomyRequestForm::execute( const Bureaucrat &executer ) const
{
   if ( !isSigned() )
      throw AForm::NotSignedException();
   if ( executer.getGrade() <= getExecuteGrade() )
   {
      drillSound();
      RobotizedTarget( _target );
   }
   else
      throw Bureaucrat::GradeTooLowException();
}
