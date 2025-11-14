/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Hammer.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 16:17:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/10/10 15:36:00 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Hammer.hpp"

Hammer::Hammer()
{
	_numberOfUses = 10;
	_type = "Hammer";
	std::cout << "\t\tHammer (" << _numberOfUses << ") - Default constructor" << std::endl;
}
Hammer::~Hammer() { std::cout << "Hammer - Default destructor" << std::endl; }

int Hammer::use() 
{
	std::cout << "\t\tHammer(" << --_numberOfUses << ") - use" << std::endl;
	if (_numberOfUses <= 0)
	{
		std::cout << "\t\tHammer - has broken" << std::endl;
		_heldBy->drop_tool(*this);
		this->~Hammer();
	}
	return _numberOfUses;
}