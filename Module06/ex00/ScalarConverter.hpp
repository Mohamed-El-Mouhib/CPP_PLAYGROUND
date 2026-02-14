#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Converter.hpp"

class ScalarConverter
{
   private:
      ScalarConverter( void );
      ScalarConverter( const ScalarConverter & );
      ScalarConverter &operator=( const ScalarConverter & );
      ~ScalarConverter( void );

   public:
      static void convert( std::string & );
};

#endif
