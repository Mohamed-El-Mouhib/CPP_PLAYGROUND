#ifndef _EASY_FIND_HPP__
#define _EASY_FIND_HPP__

#include <algorithm>
#include <cstdio>
#include <stdexcept>

template <typename T> int easyfind( T &cnT, int rTp )
{
   typename T::iterator occ = std::find( cnT.begin(), cnT.end(), rTp );

   if ( occ != cnT.end() )
      return *occ;

   std::string funcName( __func__ );
   throw std::runtime_error( funcName + ": didn't found any occurence" );
}

#endif
