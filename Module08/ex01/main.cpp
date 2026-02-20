#include "Span.hpp"
#include <iostream>

int main()
{
   {
      int arr[]     = { 6, 3, 17, 9, 11 };
      const Span sp = Span( arr, arr + ( sizeof( arr ) / sizeof( int ) ) );

      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
   }
   // SCOP!!!
   {
      Span sp = Span( 5 );

      sp.addNumber( 6 );
      sp.addNumber( 3 );
      sp.addNumber( 17 );
      sp.addNumber( 9 );
      sp.addNumber( 11 );

      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
   }
   {
      int _s[] = { 6, 3, 17, 9, 11 };
      Span __  = Span( 5 );
      __.addNumber( _s, _s + ( sizeof( _s ) ) );

      std::cout << __.shortestSpan() << std::endl;
      std::cout << __.longestSpan() << std::endl;
   }
}
