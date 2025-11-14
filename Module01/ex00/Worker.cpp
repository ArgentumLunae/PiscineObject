/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Worker.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 14:44:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:09:13 by mteerlin      ########   odam.nl         */
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
	std::cout << "\t" << _name << " - Default deconstruction" << std::endl;
	if (!_tools.empty())
	{
		std::list<Tool*>::iterator begin = _tools.begin();
		std::list<Tool*>::iterator end = _tools.end();
		for(std::list<Tool*>::iterator iter = begin; iter != end; iter++)
		{
			if (*iter != NULL)
				(*iter)->dropped(*this);
		}
		_tools.clear();
	}
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
	std::cout << "\t" << _name << " has taken the " << tool.get_type() << std::endl;
	Worker *previous = tool.get_holder();
	if (previous != NULL)
		previous->drop_tool(&tool);
	_tools.push_back(&tool);
	tool.set_holder(this);
}

void Worker::drop_tool(Tool *tool)
{
	std::cout << "\t" << _name << " has dropped the " << tool->get_type() << std::endl;
	tool->dropped(*this);
	_tools.remove(tool);
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

void Worker::work(std::set<eToolTypes> requiredTools)
{
	std::set<eToolTypes>::iterator begin = requiredTools.begin();
	std::set<eToolTypes>::iterator end = requiredTools.end();
	
	std::cout << "\t" << _name << " starts their workday." << std::endl;
	for (std::set<eToolTypes>::iterator iter = begin; begin != end; begin++)
	{
		switch (*iter)
		{
		case TT_SHOVEL: use_shovel(); break;
		case TT_HAMMER: use_hammer(); break;
		default:
			std::cout << "Unrecognised type of tool required" << std::endl;
			break;
		}
	}
}
