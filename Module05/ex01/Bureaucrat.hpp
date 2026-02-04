#ifndef _BUREAUCRAT_HPP
#define _BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

typedef int Grade;

class bureaucrat
{
   private:
      std::string _name;
      Grade _grade;

   public:
      bureaucrat( void );
      bureaucrat( const bureaucrat & );
      bureaucrat( const std::string &, Grade );
      bureaucrat &operator=( const bureaucrat & );
      ~bureaucrat( void );

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

      std::string getName( void ) const;
      Grade getGrade( void ) const;

      void incGrade( void );
      void decGrade( void );
};

std::ostream &operator<<( std::ostream &out, const bureaucrat &c );

#endif
