#include "implFunction.hpp"

int main( void )
{
   {
      srand( time( NULL ) );
      Base *ptr;

      ptr = generate();
      identify( ptr );

      delete ptr;
   }
   {
      A _;
      B __;
      C ___;
      Base KhadGar;

      identify( _ );
      identify( __ );
      identify( ___ );
      identify( KhadGar );
   }
}
