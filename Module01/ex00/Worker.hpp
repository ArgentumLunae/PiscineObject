/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Worker.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 13:47:49 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:37:31 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

#include <iostream>
#include <set>
#include "Tool.hpp"

class Tool;
class Shovel;

struct Position
{
	int x;
	int y;
	int z;

	~Position() { std::cout << "Position - Default destructor" << std::endl; };

	friend std::ostream& operator<<(std::ostream& os, Position const &pos)
	{
		os << "{" << pos.x << ", " << pos.y << ", " << pos.z << "}";		
		return os;
	}
};

struct Statistic
{
	int level;
	int experience;

	~Statistic() { std::cout << "Statistic - Default destructor" << std::endl; };

	friend std::ostream& operator<<(std::ostream& os, Statistic const &stat)
	{
		os << "Level: " << stat.level << "\tExp: " << stat.experience << std::endl;
		return os;
	}
};

class Worker
{
	private:
		std::string _name;
		Position	_pos;
		Statistic	_stat;

		std::set<Tool>	_tools;

	public:
		Worker();
		Worker(Position &pos, Statistic const &stat);
		~Worker();

		Shovel& get_shovel() const;
		void set_position(Position const &pos);
		void set_statistic(Statistic const &stat);
		void take_shovel(Shovel &shovel);
		void drop_tool(Tool &tool);
		void use_shovel();
		void use_hammer();
};

#endif
