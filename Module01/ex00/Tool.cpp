/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tool.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 15:50:24 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:10:14 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"

Tool::Tool() {};
Tool::~Tool() { std::cout << "\tTool default deconstructor" << std::endl;};

std::string Tool::get_type() { return _type; };

Worker *Tool::get_holder()
{
	return _heldBy;
}

void Tool::set_holder(Worker *worker)
{
	_heldBy = worker;
}

void Tool::dropped(Worker &worker)
{
	if (&worker != _heldBy)
	{
		std::cout << "\t\t" << _type << " not held by " << worker.get_name() << std::endl;
		return;
	}
	std::cout << "\t\t" << _type << "Tool dropped by " << worker.get_name() << std::endl; 
	_heldBy = NULL;
}