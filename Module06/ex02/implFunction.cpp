#include "implFunction.hpp"
#include <exception>
#include <iostream>

Base *generate( void )
{
   int randNbr;

   randNbr = rand() % 4;
   switch ( randNbr )
   {
   case 0:
      return new A;
   case 1:
      return new B;
   case 2:
      return new C;
   default:
      return new Base;
   }
}

void identify( Base *p )
{
   if ( dynamic_cast<A *>( p ) )
      std::cout << "this is 'A' Instance" << std::endl;
   else if ( dynamic_cast<B *>( p ) )
      std::cout << "this is 'B' Instance" << std::endl;
   else if ( dynamic_cast<C *>( p ) )
      std::cout << "this is 'C' Instance" << std::endl;
   else if ( dynamic_cast<Base *>( p ) )
      std::cout << "this is 'Base' Instance" << std::endl;
}

// clang-format off
void identify( Base &p )
{
   try
   {
      (void)dynamic_cast<A &>( p );
      std::cout << "this is 'A' Instance" << std::endl;
		return;
   }
   catch ( const std::exception &e )
	{ }

   try
   {
      (void)dynamic_cast<B &>( p );
      std::cout << "this is 'B' Instance" << std::endl;
		return;
   }
   catch ( const std::exception &e )
	{ }

   try
   {
      (void)dynamic_cast<C &>( p );
      std::cout << "this is 'C' Instance" << std::endl;
		return;
   }
   catch ( const std::exception &e )
	{ }

   try
   {
      (void)dynamic_cast<Base &>( p );
      std::cout << "this is 'Base' Instance" << std::endl;
		return;
   }
   catch ( const std::exception &e )
	{ }
}
// clang-format on
