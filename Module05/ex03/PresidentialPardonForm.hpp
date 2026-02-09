#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
   private:
      std::string _target;

   public:
      PresidentialPardonForm( void );
      PresidentialPardonForm( const std::string & );
      PresidentialPardonForm( const PresidentialPardonForm & );
      PresidentialPardonForm &operator=( const PresidentialPardonForm & );
      ~PresidentialPardonForm( void );

      void execute( const Bureaucrat & ) const;
};

#endif
