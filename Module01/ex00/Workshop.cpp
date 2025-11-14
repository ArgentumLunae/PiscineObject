/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Workshop.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/03 15:19:36 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:18:14 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Workshop.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

Workshop::Workshop()
{
	std::cout << "New workshop created." << std::endl;
};

Workshop::Workshop(std::set<eToolTypes> requirement) : _requirement(requirement)
{
	std::cout << "New workshop created with requirement: ";
	if (requirement.empty())
		std::cout << "none";
	
	std::set<eToolTypes>::iterator begin = requirement.begin();
	std::set<eToolTypes>::iterator end = requirement.end();

	for (std::set<eToolTypes>::iterator iter = begin; begin != end; begin++)
	{
		switch (*iter)
		{
			case TT_SHOVEL: std::cout << "Shovel,"; break;
			case TT_HAMMER: std::cout << "Hammer,"; break;
			default: std::cout << "Unknown Tool Type";
		};
	}
	std::cout << std::endl;
}

Workshop::~Workshop()
{
	_workers.clear();
	std::cout << "Workshop Closed" <<std::endl;
}

bool Workshop::has_required_tools(Worker &worker)
{
	std::set<eToolTypes>::iterator begin = _requirement.begin();
	std::set<eToolTypes>::iterator end = _requirement.end();

	std::cout << "Confirm " << worker.get_name() << " has the correct tools." << std::endl;
	for (std::set<eToolTypes>::iterator iter = begin; begin != end; begin++)
	{
		switch (*iter)
		{
			case TT_SHOVEL:
				if (worker.get_tool<Shovel>() == nullptr)
					return false;
			case TT_HAMMER:
				if (worker.get_tool<Hammer>() == nullptr)
					return false;
			default: std::cout << "Unknown Tool Type";
		};
	}
	return true;
}

void Workshop::add_requirement(eToolTypes type)
{
	_requirement.insert(type);
}

void Workshop::remove_requirement(eToolTypes type)
{
	_requirement.erase(type);
}

void Workshop::register_worker(Worker &worker)
{
	_workers.insert(&worker);
}

void Workshop::ungegister_worker(Worker &worker)
{
	_workers.erase(&worker);
}

void Workshop::executeWorkDay()
{
	std::set<Worker*>::iterator first = _workers.begin();
	std::set<Worker*>::iterator last = _workers.end();

	std::cout << "Start the workday." << std::endl;
	for (std::set<Worker*>::iterator iter = first; first != last; first++)
	{
		(*iter)->work(_requirement);
	}
}