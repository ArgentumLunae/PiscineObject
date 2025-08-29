/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:12:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:22:56 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Shovel.hpp"

int main(void)
{
	//IV1
	{
		std::cout << "\tIV1 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};

		Worker WS1;
		WS1.set_position(pos);
		WS1.set_statistic(stat);

		pos.x = 5;
		pos.y = -3;
		stat.experience += 864;

		Worker WS2(pos, stat);
	}

	//IV2
	{
		std::cout << "\tIV2 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};
		Shovel Steve;

		Worker DirtDestroyer9001;
		Worker SnowSlinger;
		DirtDestroyer9001.set_position(pos);
		DirtDestroyer9001.set_statistic(stat);
		DirtDestroyer9001.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.~Worker();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
	}

	//IV3
	{
		std::cout << "\tIV2 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};
		Shovel Steve;

		Worker DirtDestroyer9001;
		Worker SnowSlinger;
		DirtDestroyer9001.set_position(pos);
		DirtDestroyer9001.set_statistic(stat);
		DirtDestroyer9001.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.~Worker();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.take_shovel(Steve);
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
	}
}