/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Worker.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 13:47:49 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:11:24 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

#include <iostream>
#include <list>
#include "Tool.hpp"
#include "Workshop.hpp"
#include "ToolTypes.h"

class Tool;
class Shovel;
class Workshop;
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
		std::string _name = "Worker";
		Position	_pos;
		Statistic	_stat;

		std::list<Tool*>		_tools;
		std::set<Workshop*>	_workshops;
	
	public:
	
		Worker();
		Worker(Position &pos, Statistic const &stat);
		~Worker();

		std::list<Tool*> get_tools() const;
		void set_position(Position const &pos);
		void set_name(std::string const name);
		std::string get_name() const;
		void set_statistic(Statistic const &stat);
		void take_tool(Tool &tool);
		void drop_tool(Tool *tool);
		void use_shovel();
		void use_hammer();
		void work(std::set<eToolTypes> requiredTools);

		template <typename T>
		T* get_tool()
		{
			std::list<Tool*>::iterator begin = _tools.begin();
			std::list<Tool*>::iterator end = _tools.end();


			for (std::list<Tool*>::iterator iter = begin; iter != end; iter++)
			{
				if (dynamic_cast<T*>(*iter) != NULL)
				{
					std::cout << "\t\t" << _name << " has correct tool." << std::endl;
					return dynamic_cast<T*>(*iter);
				}
			}
			return nullptr;
 		}
};

#endif
