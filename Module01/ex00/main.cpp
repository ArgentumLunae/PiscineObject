/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:12:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/07 12:26:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main(int argc, char* argv[])
{
	//IV1
	if (argc == 1 || argv[1][0] == '1')
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
		std::cout << std::endl << std::endl;
	}

	//IV2
	if (argc == 1 || argv[1][0] == '2')
	{
		std::cout << "\tIV2 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};
		Shovel Steve;

		Worker DirtDestroyer9001;
		Worker SnowSlinger;
		DirtDestroyer9001.set_position(pos);
		DirtDestroyer9001.set_statistic(stat);
		DirtDestroyer9001.take_tool(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.set_name("Bartholomew Kuma");
		SnowSlinger.take_tool(Steve);
		DirtDestroyer9001.use_shovel();
		SnowSlinger.~Worker();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.take_tool(Steve);
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		std::cout << std::endl << std::endl;
	}

	//IV3
	if (argc == 1 || argv[1][0] == '3')
	{
		std::cout << "\tIV2 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};
		Shovel Steve;
		Hammer Charles;

		Worker workerA;
		Worker workerB;
		
	}

	if (argc == 1 || argv[1][0] == '4')
		return -1;
	return 0;
}