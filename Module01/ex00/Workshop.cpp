/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Workshop.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/03 15:19:36 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/10/03 16:29:54 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Workshop.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

Workshop::Workshop() : _requirement(SR_NONE)
{
	std::cout << "New workshop created." << std::endl;
};

Workshop::Workshop(tShopRequirements requirement) : _requirement(requirement)
{
	std::cout << "New workshop created with requirement: ";
	switch (_requirement)
	{
	case SR_NONE:
		std::cout << "None";
		break;
	case SR_SHOVEL:
		std::cout << "Shovel";
		break;
	case SR_HAMMER:
		std::cout << "Hammer";
		break;
	case SR_BOTH:
		std::cout << "Hammer and Shovel";
		break;
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
	switch (_requirement)
	{
	case SR_NONE:
		return true;
	case SR_SHOVEL:
		if (worker.get_tool<Shovel>() != nullptr)
			return true;
	case SR_HAMMER:
		if (worker.get_tool<Hammer>() != nullptr)
			return true;
	case SR_BOTH:
		if (worker.get_tool<Shovel>() != nullptr && worker.get_tool<Hammer>() != nullptr)
			return true;
	default:
		return false;
	}
	return false;
}

void Workshop::register_worker(Worker &worker)
{
	_workers.insert(&worker);
}

void Workshop::ungegister_worker(Worker &worker)
{
	_workers.erase(&worker);
}
