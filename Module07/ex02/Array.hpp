#ifndef _ARRAY_HPP__
#define _ARRAY_HPP__

#include <cstddef>
#include <cstring>
#include <stdexcept>

template <typename A> class Array
{
   private:
      unsigned int _size;
      A *_arr;

   public:
      Array( void ) : _size( 0 ), _arr( NULL )
      {
      }

      Array( const Array &other )
        : _size( other._size ),
          _arr(
              static_cast<A *>( operator new[]( sizeof( A ) * other.size() ) ) )
      {
         for ( size_t i = 0; i < other.size(); ++i )
            _arr[ i ] = other._arr[ i ];
      }

      Array( unsigned int n )
        : _size( n ),
          _arr( static_cast<A *>( operator new[]( sizeof( A ) * n ) ) )
      {
         for ( size_t i = 0; i < n; ++i )
            _arr[ i ] = A();
      }

      ~Array( void )
      {
         operator delete[]( _arr );
      }

      Array &operator=( const Array &other )
      {
         if ( this != &other )
         {
            operator delete[]( _arr );
            _size = other._size;
            _arr =
                static_cast<A *>( operator new[]( sizeof( A ) * other._size ) );
            for ( size_t i = 0; i < _size; ++i )
               _arr[ i ] = other._arr[ i ];
         }

         return *this;
      }

      A &operator[]( const unsigned int i )
      {
         if ( i >= _size )
            throw std::out_of_range( "out of bound index" );

         return _arr[ i ];
      }

      unsigned int size( void ) const
      {
         return _size;
      }
};

#endif
