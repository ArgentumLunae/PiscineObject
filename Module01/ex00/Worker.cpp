/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Worker.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 14:44:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:38:19 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Shovel.hpp"

Worker::Worker() { std::cout << "Worker - Default construction" << std::endl; };

Worker::Worker(Position &pos, Statistic const &stat) : _pos(pos), _stat(stat), _shovel(NULL)
{
	std::cout << "Worker - Parametric construction" << std::endl;
	std::cout << "\tPosition:  " << pos << std::endl;
	std::cout << "\tStatistic: " << stat << std::endl;
}

Worker::~Worker() { std::cout << "Worker - Default deconstruction" << std::endl; };

void Worker::set_position(Position const &pos)
{
	_pos.x = pos.x;
	_pos.y = pos.y;
	_pos.z = pos.z;
	std::cout << "Worker: set_position - " << _pos << std::endl;
};

void Worker::set_statistic(Statistic const &stat)
{
	_stat.level = stat.level;
	_stat.experience = stat.experience;
	std::cout << "Worker: set_statistic - " <<_stat << std::endl;
};

void Worker::take_shovel(Shovel &shovel)
{
	shovel.picked_up(*this);
	_tools.insert(shovel);
	std::cout << "Worker has taken the shovel" << std::endl;
}

void Worker::drop_tool(Tool &tool)
{
	_tools.erase(tool);
	std::cout << "Worker has dropped the " << tool.get_type() << std::endl;
}

void Worker::use_shovel()
{
	if (_tools.size() == 0)
		std::cout << "Worker does not have any tools." << std::endl;
	else
	{
		std::cout << "Worker uses shovel" << std::endl;
		_tool.find()->use();
	}
}
