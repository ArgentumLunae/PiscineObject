/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tool.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 15:50:24 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:22:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"

Tool::Tool() {};
Tool::~Tool() {};

std::string Tool::get_type() { return _type; };

void Tool::picked_up(Worker &worker)
{
	if (_heldBy)
	{
		std::cout << _type << " exchanges hands" << std::endl;
		_heldBy->drop_tool(*this);
	}
	_heldBy = &worker;
}