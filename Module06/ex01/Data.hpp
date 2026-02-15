#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
   private:
      std::string _name;
      std::string _secret;

   public:
      Data( void );
      Data( const Data & );
      Data( const std::string &, const std::string & );
      Data &operator=( const Data & );
      ~Data( void );

      void exposeSecret( void );
};

#endif
