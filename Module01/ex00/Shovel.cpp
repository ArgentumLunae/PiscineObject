/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Shovel.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 14:08:22 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:22:12 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

Shovel::Shovel()
{
	_type = "shovel";
	_numberOfUses = 10;
	std::cout << "Shovel (" << _numberOfUses << ") - Default constructor" << std::endl;
}
Shovel::~Shovel() { std::cout << "Shovel - Default destructor" << std::endl; }

int Shovel::use() 
{
	std::cout << _type << "(" << --_numberOfUses << ") - use" << std::endl;
	if (_numberOfUses <= 0)
	{
		std::cout << "Shovel - has broken" << std::endl;
		_heldBy->drop_tool(*this);
		this->~Shovel();
	}
	return _numberOfUses;
}