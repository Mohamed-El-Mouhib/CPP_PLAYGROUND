#ifndef _IMPLFUNCTION_HPP_
#define _IMPLFUNCTION_HPP_

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base;

Base *generate( void );
void identify( Base *p );
void identify( Base &p );

#endif
