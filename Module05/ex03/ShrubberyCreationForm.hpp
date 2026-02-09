#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
   private:
      std::string _target;

   public:
      ShrubberyCreationForm( void );
      ShrubberyCreationForm( const std::string & );
      ShrubberyCreationForm( const ShrubberyCreationForm & );
      ShrubberyCreationForm &operator=( const ShrubberyCreationForm & );
      ~ShrubberyCreationForm( void );

      void execute( const Bureaucrat & ) const;
};

#endif
