#ifndef _FORM_HPP
#define _FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

typedef int Grade;
class Bureaucrat;

class Form
{
   private:
      std::string _name; // name
      bool _IsSigned;    // A boolean indicating whether it is signed
      Grade _reqGrade;   // required grade to signe
      Grade _excGrade;   // required grade to execute it

   public:
      Form( void );
      Form( const Form & );
      Form( const std::string &, Grade, Grade );
      Form &operator=( const Form & );
      ~Form( void );

      void beSigned( const Bureaucrat & );

      class GradeTooHighException : public std::exception
      {
            const char *what( void ) const throw()
            {
               return "Form's grade IS HIGH !!";
            }
      };

      class GradeTooLowException : public std::exception
      {
            const char *what( void ) const throw()
            {
               return "Form's grade IS LOW !!";
            }
      };

      std::string getName( void ) const;
      bool isSigned( void ) const;
      Grade getRequiredGrade( void ) const;
      Grade getExecuteGrade( void ) const;
};

std::ostream &operator<<( std::ostream &out, const Form &c );

#endif
