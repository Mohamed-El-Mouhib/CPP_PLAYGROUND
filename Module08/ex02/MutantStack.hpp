#ifndef _MUTANT_STACK_HPP__
#define _MUTANT_STACK_HPP__

#include <deque>
#include <stack>

template <typename A, typename B = std::deque<A> >
class MutantStack : public std::stack<A, B>
{
   public:
      typedef typename B::iterator iterator;
      typedef typename B::const_iterator const_iterator;
      typedef typename B::reverse_iterator reverse_iterator;
      typedef typename B::const_reverse_iterator const_reverse_iterator;

      MutantStack( void ) : std::stack<A, B>()
      {
      }

      MutantStack( const MutantStack &other ) : std::stack<A, B>( other )
      {
      }
      /*for normal iterator*/
      iterator begin( void )
      {
         return this->c.begin();
      }

      iterator end( void )
      {
         return this->c.end();
      }

      /*for const iterator*/
      const_iterator begin( void ) const
      {
         return this->c.begin();
      }
      const_iterator end( void ) const
      {
         return this->c.end();
      }

      /*for reverse iterator*/
      reverse_iterator rbegin()
      {
         return this->c.rbegin();
      }
      reverse_iterator rend()
      {
         return this->c.rend();
      }

      /*for const reverse iterator*/
      const_reverse_iterator rbegin() const
      {
         return this->c.rbegin();
      }

      const_reverse_iterator rend() const
      {
         return this->c.rend();
      }

      MutantStack &operator=( const MutantStack &other )
      {
         if ( this != &other )
            std::stack<A, B>::operator=( other );

         return *this;
      }

      ~MutantStack( void )
      {
      }
};

#endif
