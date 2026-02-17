#ifndef _IMPL_TEMPLATE__
#define _IMPL_TEMPLATE__

template <typename T> void swap( T &First, T &Second )
{
   T tmp;

   tmp    = First;
   First  = Second;
   Second = tmp;
}

template <typename T> T &min( T &First, T &Second )
{
   return Second <= First ? Second : First;
}

template <typename T> T &max( T &First, T &Second )
{
   return Second >= First ? Second : First;
}

#endif
