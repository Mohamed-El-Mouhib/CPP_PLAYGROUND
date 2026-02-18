#ifndef _SPAN_HPP__
#define _SPAN_HPP__

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class Span
{
   private:
      size_t _size;
      size_t _capacity;
      int *_arr;

   public:
      Span( void );
      Span( unsigned int );
      Span( int *, int * );
      Span &operator=( const Span & );
      Span( const Span & );

      void addNumber( int );
      void printNumbers( void )
      {
         std::cout << "_size: " << _size << std::endl;
         for ( size_t i = 0; i < _size; ++i )
         {
            std::cout << "_arr[" << i << "]: " << _arr[ i ] << std::endl;
         }
         std::cout << std::endl;
      }
      unsigned int shortestSpan( void ) const;
      unsigned int longestSpan( void ) const;

      ~Span( void );
};

#endif
