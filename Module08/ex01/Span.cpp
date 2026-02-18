#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span( void ) : _size( 0 ), _capacity( 0 ), _arr( NULL )
{
}

Span::Span( unsigned int N )
  : _size( 0 ), _capacity( N ), _arr( new int[ N ]() )
{
}

Span::Span( int *beginPtr, int *endPtr )
  : _size( 0 ), _capacity( static_cast<size_t>( endPtr - beginPtr ) ),
    _arr( new int[ _capacity ]() )
{
   size_t i = 0;

   for ( ; beginPtr < endPtr; ++beginPtr )
   {
      _arr[ i++ ] = *beginPtr;
      _size++;
   }

   std::sort( _arr, _arr + _size );
}

Span::Span( const Span &other )
  : _size( other._size ), _capacity( other._capacity ),
    _arr( new int[ _capacity ]() )
{
   for ( size_t i = 0; i < _size; ++i )
      _arr[ i ] = other._arr[ i ];
}

Span &Span::operator=( const Span &other )
{
   if ( this != &other )
   {
      delete[] _arr;
      _size     = other._size;
      _capacity = other._capacity;
      _arr      = new int[ _capacity ]();
      for ( size_t i = 0; i < _size; ++i )
         _arr[ i ] = other._arr[ i ];
   }

   return *this;
}

void Span::addNumber( int newElement )
{
   if ( _capacity == 0 || _size >= _capacity )
   {
      std::string stErr( __func__ );
      throw std::runtime_error( stErr + ": Span reach it's Capacity" );
   }

   _arr[ _size++ ] = newElement;
   std::sort( _arr, _arr + _size );
}

unsigned int Span::shortestSpan( void ) const
{
   int smalestSpan = 0;
   int currSpan;

   if ( _capacity <= 1 || _size <= 0 )
      return 0;

   smalestSpan = _arr[ 1 ] - _arr[ 0 ];
   for ( size_t i = 0; i < _size - 1; ++i )
   {
      currSpan = _arr[ i + 1 ] - _arr[ i ];
      if ( currSpan < smalestSpan )
         smalestSpan = currSpan;
   }

   return smalestSpan;
}

unsigned int Span::longestSpan( void ) const
{
   if ( _capacity <= 1 || _size <= 1 )
      return 0;

   return _arr[ _size - 1 ] - _arr[ 0 ];
}

Span::~Span( void )
{
   delete[] _arr;
}
