#include "Data.hpp"

Data::Data( void ) : _name( "DefauleDataName" ), _secret( "NoSecret" )
{
}

Data::Data( const Data &other ) : _name( other._name ), _secret( other._secret )
{
}

Data::Data( const std::string &name, const std::string &secret )
  : _name( name ), _secret( secret )
{
}

Data::~Data( void )
{
   std::cout << "Forgeting about " << _name << " and his secret FOREVER\n";
}

Data &Data::operator=( const Data &other )
{
   if ( this != &other )
   {
      _name   = other._name;
      _secret = other._secret;
   }

   return *this;
}

void Data::exposeSecret( void )
{
   std::cout << "<" << _name << "> did " << _secret << std::endl;
}
