#ifndef _BUREAUCRAT_HPP
#define _BUREAUCRAT_HPP

#include "AForm.hpp"

class Bureaucrat
{
   private:
      std::string _name;
      Grade _grade;

   public:
      Bureaucrat( void );
      Bureaucrat( const Bureaucrat & );
      Bureaucrat( const std::string &, Grade );
      Bureaucrat &operator=( const Bureaucrat & );
      ~Bureaucrat( void );

      class GradeTooHighException : public std::exception
      {
         public:
            const char *what( void ) const throw()
            {
               return "Bureaucrat's grade IS TOO HIGH !!";
            }
      };

      class GradeTooLowException : public std::exception
      {
         public:
            const char *what( void ) const throw()
            {
               return "Bureaucrat's grade IS TOO LOW !!";
            }
      };

      std::string getName( void ) const;
      Grade getGrade( void ) const;

      void incGrade( void );
      void decGrade( void );
      void signAForm( AForm & );
      void executeForm( AForm const & );
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &c );

#endif
