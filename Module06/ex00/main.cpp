#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
   if ( ac != 2 )
   {
      std::cerr << "invalid number of arguements" << "\n"
                << "try something like" << "\t" << av[ 0 ] << " \"42.0f\""
                << std::endl;
      return 1;
   }
   std::string str( av[ 1 ] );
   ScalarConverter::convert( str );
}
