/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IV1.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 13:47:49 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/08 15:26:48 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IV2.hpp"

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
		Position	_pos;
		Statistic	_stat;

		//IV2
		Shovel		*_shovel;

	public:
		Worker() : _shovel(NULL) { std::cout << "Worker - Default construction" << std::endl; };
		Worker(Position &pos, Statistic const &stat) : _pos(pos), _stat(stat), _shovel(NULL)
		{
			std::cout << "Worker - Parametric construction" << std::endl;
			std::cout << "\tPosition:  " << pos << std::endl;
			std::cout << "\tStatistic: " << stat << std::endl;
		}
		~Worker() { std::cout << "Worker - Default deconstruction" << std::endl; };

		void set_position(Position const &pos)
		{
			_pos.x = pos.x;
			_pos.y = pos.y;
			_pos.z = pos.z;
			std::cout << "Worker: set_position - " << _pos << std::endl;
		};
		void set_statistic(Statistic const &stat)
		{
			_stat.level = stat.level;
			_stat.experience = stat.experience;
			std::cout << "Worker: set_statistic - " <<_stat << std::endl;
		};

		//IV2
		void use_shovel()
		{
			if (_shovel == NULL)
				std::cout << "Worker - Has no shovel" << std::endl;
			else if (_shovel->use() <= 0)
				_shovel = NULL;				
		}
};
