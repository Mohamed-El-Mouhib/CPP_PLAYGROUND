#ifndef _BUREAUCRAT
#define _BUREAUCRAT

#include <exception>
#include <iostream>
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
            const char *what( void ) const noexcept
            {
               return "The grade passed IS TOO HIGH !!";
            };
      };

      class GradeTooLowException : public std::exception
      {
            const char *what( void ) const noexcept
            {
               return "The grade passed IS TOO LOW !!";
            };
      };

      std::string getName( void ) const;
      Grade getGrade( void ) const;
};

#endif
