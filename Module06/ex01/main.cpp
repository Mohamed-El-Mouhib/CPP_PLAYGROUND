#include "Serializer.hpp"

void printHex( unsigned long int value )
{
   std::cout << "0x" << std::hex << value << std::endl;
}
int main( void )
{
   std::string name, secret;
   uintptr_t addrHolder;
   Data *__;

   secret = "Play World of Warcraft instead of studying";
   name   = "Mohamed";

   std::cout << "---------------------------------" << std::endl;
   __         = new Data( name, secret );
   addrHolder = Serializer::serialize( __ );

   __         = NULL;
   std::cout << "OOOPS you lose the address to theData XD" << std::endl;

   std::cout << "---------------------------------" << std::endl;
   __ = Serializer::deserialize( addrHolder );
   __->exposeSecret();
   std::cout << "DAMN :O" << std::endl;
   std::cout << "---------------------------------" << std::endl;

   std::cout << __ << std::endl;
   printHex( addrHolder );
   delete reinterpret_cast<Data *>( addrHolder );
}
