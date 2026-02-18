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
      unsigned int shortestSpan( void ) const;
      unsigned int longestSpan( void ) const;

      ~Span( void );
};

#endif
