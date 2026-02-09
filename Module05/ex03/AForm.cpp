#include "AForm.hpp"
#include "Bureaucrat.hpp"

static Grade GradeValidate( Grade grade )
{
   if ( grade > 150 )
      throw AForm::GradeTooLowException();
   else if ( grade < 1 )
      throw AForm::GradeTooHighException();
   return grade;
}

AForm::AForm( void )
  : _name( "defaultAForm" ), _IsSigned( false ), _reqGrade( 150 ),
    _excGrade( 1 )
{
}

AForm::AForm( const AForm &other )
  : _name( other._name ), _IsSigned( other._IsSigned ),
    _reqGrade( other._reqGrade ), _excGrade( other._excGrade )
{
}

AForm::AForm( const std::string &name, Grade reqGrade, Grade excuteGrade )
  : _name( name ), _IsSigned( false ), _reqGrade( GradeValidate( reqGrade ) ),
    _excGrade( GradeValidate( excuteGrade ) )
{
}

AForm &AForm::operator=( const AForm &other )
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

void AForm::beSigned( const Bureaucrat &target )
{
   Grade targetGrade;

   targetGrade = target.getGrade();
   if ( targetGrade <= _reqGrade )
   {
      _IsSigned = true;
      return;
   }
   throw AForm::GradeTooLowException();
}

std::string AForm::getName( void ) const
{
   return _name;
}

bool AForm::isSigned( void ) const
{
   return _IsSigned;
}

Grade AForm::getRequiredGrade( void ) const
{
   return _reqGrade;
}

Grade AForm::getExecuteGrade( void ) const
{
   return _excGrade;
}

std::ostream &operator<<( std::ostream &out, const AForm &c )
{
   out << "AForm: " << c.getName() << " require grade " << c.getRequiredGrade()
       << ", execute grade " << c.getExecuteGrade();
   if ( c.isSigned() )
      out << "it is signed";
   else
      out << "not signed yet";
   return out;
}

AForm::~AForm( void )
{
}
