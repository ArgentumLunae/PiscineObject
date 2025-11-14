/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Worker.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 14:44:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/07 12:30:21 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Worker::Worker() { std::cout << "\t" << _name << " - Default construction" << std::endl; };

Worker::Worker(Position &pos, Statistic const &stat) : _pos(pos), _stat(stat)
{
	std::cout << "\t" << _name << " - Parametric construction" << std::endl;
	std::cout << "\t\tPosition:  " << pos << std::endl;
	std::cout << "\t\tStatistic: " << stat << std::endl;
}

Worker::~Worker()
{
	std::list<Tool*>::iterator begin = _tools.begin();
	std::list<Tool*>::iterator end = _tools.end();
	for(std::list<Tool*>::iterator iter = begin; iter != end; iter++)
	{
		if (*iter != NULL)
		{
			std::cout << "Deconstructor - tool drop." << std::endl;
			this->drop_tool(**iter);
		}
		else
			std::cout << "How did this item become NULL?" << std::endl;
	}
	std::cout << "\t" << _name << " - Default deconstruction" << std::endl;
};

std::list<Tool*> Worker::get_tools() const
{
	return _tools;
}

void Worker::set_name(std::string const name)
{
	_name = name;
}

std::string Worker::get_name() const
{
	return _name;
}

void Worker::set_position(Position const &pos)
{
	std::cout << "\t" << _name << ": set_position - " << _pos << std::endl;
	_pos.x = pos.x;
	_pos.y = pos.y;
	_pos.z = pos.z;
};

void Worker::set_statistic(Statistic const &stat)
{
	std::cout << "\t" << _name << " set_statistic - " <<_stat << std::endl;
	_stat.level = stat.level;
	_stat.experience = stat.experience;
};

void Worker::take_tool(Tool &tool)
{
	std::cout << "\t" << _name << " has taken the shovel" << std::endl;
	tool.picked_up(*this);
	_tools.push_back(&tool);
}

void Worker::drop_tool(Tool &tool)
{
	std::cout << "\t" << _name << " has dropped the " << tool.get_type() << std::endl;
	_tools.remove(&tool);
}

void Worker::use_shovel()
{
	if (_tools.size() == 0)
		std::cout << "\t" << _name << " does not have any tools." << std::endl;
	else
	{
		Shovel *shovel = get_tool<Shovel>();

		if (shovel != nullptr)
		{
			std::cout << "\t" << _name << " uses shovel" << std::endl;
			shovel->use();
		}
		else
			std::cout << "\t" << _name << " doesn't have a shovel" << std::endl;
	}
}

void Worker::use_hammer()
{
	if (_tools.size() == 0)
		std::cout << "\t" << _name << " does not have any tools." << std::endl;
	else
	{
		Hammer *hammer = get_tool<Hammer>();

		if (hammer != nullptr)
		{
			std::cout << "\t" << _name << " uses hammer" << std::endl;
			hammer->use();
		}
		else
			std::cout << "\t" << _name << " doesn't have a shovel" << std::endl;
	}
}
