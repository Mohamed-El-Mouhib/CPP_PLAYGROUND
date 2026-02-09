#ifndef _AFORM_HPP
#define _AFORM_HPP

#include <cmath>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

typedef int Grade;
class Bureaucrat;

class AForm
{
   private:
      std::string _name; // name
      bool _IsSigned;    // A boolean indicating whether it is signed
      Grade _reqGrade;   // required grade to signe
      Grade _excGrade;   // required grade to execute it

   public:
      AForm( void );
      AForm( const AForm & );
      AForm( const std::string &, Grade, Grade );
      AForm &operator=( const AForm & );
      virtual ~AForm( void );

      void beSigned( const Bureaucrat & );
      virtual void execute( const Bureaucrat & ) const = 0;

      class GradeTooHighException : public std::exception
      {
         public:
            const char *what( void ) const throw()
            {
               return "grade IS HIGH !!";
            }
      };

      class GradeTooLowException : public std::exception
      {
         public:
            const char *what( void ) const throw()
            {
               return "grade IS LOW !!";
            }
      };

      class NotSignedException : public std::exception
      {
         public:
            const char *what() const throw()
            {
               return "Form is not signed";
            }
      };

      std::string getName( void ) const;
      bool isSigned( void ) const;
      Grade getRequiredGrade( void ) const;
      Grade getExecuteGrade( void ) const;
};

std::ostream &operator<<( std::ostream &out, const AForm &c );

#endif
