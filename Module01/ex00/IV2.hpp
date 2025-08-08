/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IV2.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:58:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/08 15:26:34 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Shovel
{
	private:
		int numberOfUses;

	public:
		Shovel() { std::cout << "Shovel - Default constructor" << std::endl; };
		~Shovel() { std::cout << "Shovel - Default destructor" << std::endl; };

		int use() 
		{
			std::cout << "Shovel - use" << std::endl;
			--numberOfUses;
			if (numberOfUses <= 0)
			{
				std::cout << "Shovel - has broken" << std::endl;
				this->~Shovel();
			}
			return numberOfUses;
		}
};
