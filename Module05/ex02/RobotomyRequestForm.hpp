#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
   private:
      std::string _target;

   public:
      RobotomyRequestForm( void );
      RobotomyRequestForm( const std::string & );
      RobotomyRequestForm( const RobotomyRequestForm & );
      RobotomyRequestForm &operator=( const RobotomyRequestForm & );
      ~RobotomyRequestForm( void );

      void execute( const Bureaucrat & ) const;
};

#endif
