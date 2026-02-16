#ifndef _IMPL_TEMPLATE__
#define _IMPL_TEMPLATE__

template <class T> void swap( T &First, T &Second )
{
   T tmp;

   tmp    = First;
   First  = Second;
   Second = tmp;
}

template <class T> T &min( T &First, T &Second )
{
   return Second <= First ? Second : First;
}

template <class T> T &max( T &First, T &Second )
{
   return Second >= First ? Second : First;
}

#endif
