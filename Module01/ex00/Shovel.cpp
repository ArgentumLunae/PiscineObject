/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Shovel.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 14:08:22 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 15:27:00 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

Shovel::Shovel()
{
	_numberOfUses = 5;
	_type = "Shovel";
	std::cout << "\t\tShovel (" << _numberOfUses << ") - Default constructor" << std::endl;
}
Shovel::~Shovel() { std::cout << "\t\tShovel - Default destructor" << std::endl; }

int Shovel::use() 
{
	std::cout << "\t\tShovel(" << --_numberOfUses << ") - use" << std::endl;
	if (_numberOfUses <= 0)
	{
		std::cout << "\t\tShovel - has broken" << std::endl;
		if (_heldBy)
			_heldBy->drop_tool(this);
	}
	return _numberOfUses;
}