#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
   private:
      Serializer( void );
      Serializer( const Serializer & );
      Serializer &operator=( const Serializer & );
      ~Serializer( void );

   public:
      static uintptr_t serialize( Data *ptr );
      static Data *deserialize( uintptr_t raw );
};

#endif
