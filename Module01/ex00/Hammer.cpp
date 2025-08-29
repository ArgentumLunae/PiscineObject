/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Hammer.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 16:17:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:31:56 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Hammer.hpp"

Hammer::Hammer()
{
	_type = "Hammer";
	_numberOfUses = 10;
	std::cout << "Hammer (" << _numberOfUses << ") - Default constructor" << std::endl;
}
Hammer::~Hammer() { std::cout << "Hammer - Default destructor" << std::endl; }

int Hammer::use() 
{
	std::cout << _type << "(" << --_numberOfUses << ") - use" << std::endl;
	if (_numberOfUses <= 0)
	{
		std::cout << "Hammer - has broken" << std::endl;
		_heldBy->drop_tool(*this);
		this->~Hammer();
	}
	return _numberOfUses;
}