/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.1337.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:55:38 by your_login        #+#    #+#             */
/*   Updated: 2026/02/14 20:10:45 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & )
{
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter & )
{
   return *this;
}

ScalarConverter::~ScalarConverter( void )
{
}

void ScalarConverter::convert( std::string &input )
{
   InType type = whichType( input );
   printChar( input, type );
   printInt( input, type );
   printFloat( input, type );
   printDouble( input, type );
}
