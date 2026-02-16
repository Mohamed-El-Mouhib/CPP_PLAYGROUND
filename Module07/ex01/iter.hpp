#ifndef _ITER_HPP__
#define _ITER_HPP__

#include <cstddef>

template <typename A, typename B, typename C>
void iter( A *arr, const size_t length, B ( *ptrFunc )( C & ) )
{
   for ( std::size_t i = 0; i < length; ++i )
      ptrFunc( arr[ i ] );
}

template <typename A, typename B, typename C>
void iter( A *arr, const size_t length, B ( *ptrFunc )( const C & ) )
{
   for ( std::size_t i = 0; i < length; ++i )
      ptrFunc( arr[ i ] );
}

#endif
