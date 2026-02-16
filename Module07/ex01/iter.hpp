#ifndef _ITER_HPP__
#define _ITER_HPP__

#include <cstddef>

template <typename A, typename B, typename C, typename D>
void iter( A *arr[], const B length, C ( *ptrFunc )( D & ) )
{
   for ( std::size_t i = 0; i < length; ++i )
   {
      ptrFunc( arr[ i ] );
   }
}

template <typename A, typename B, typename C, typename D>
void iter( const A *arr[], const B length, C ( *ptrFunc )( const D & ) )
{
   for ( std::size_t i = 0; i < length; ++i )
   {
      ptrFunc( arr[ i ] );
   }
}

#endif
