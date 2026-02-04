#ifndef _FORM_HPP
#define _FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class form
{
   private:
      std::string _name; // name
      bool _IsSigned;    // A boolean indicating whether it is signed
      Grade _reqGrade;   // required grade to signe
      Grade _excGrade;   // required grade to execute it

   public:
      form( void );
      form( const form & );
      form( const std::string &, Grade, Grade );
      form &operator=( const form & );
      ~form( void );

      void beSigned( void );

      class GradeTooHighException : public std::exception
      {
            const char *what( void ) const throw()
            {
               return "bureaucrat's grade IS TOO HIGH !!";
            }
      };

      class GradeTooLowException : public std::exception
      {
            const char *what( void ) const throw()
            {
               return "bureaucrat's grade IS TOO LOW !!";
            }
      };
};

std::ostream &operator<<( std::ostream &out, const bureaucrat &c );

#endif
