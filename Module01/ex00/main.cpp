/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:12:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:19:56 by mteerlin      ########   odam.nl         */
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
	}

	//IV2
	if (argc == 1 || argv[1][0] == '2')
	{
		if (argc == 1) {std::cout << std::endl << std::endl;}
		std::cout << "\tIV2 : " << std::endl;
		Position pos = { 1, 2, 3 };
		Statistic stat = {10, 19863};
		Shovel Steve;

		Worker DirtDestroyer9001;
		DirtDestroyer9001.set_position(pos);
		DirtDestroyer9001.set_statistic(stat);
		DirtDestroyer9001.take_tool(Steve);
		DirtDestroyer9001.use_shovel();
		{
			Worker SnowSlinger;
			SnowSlinger.set_name("Bartholomew Kuma");
			SnowSlinger.take_tool(Steve);
		}
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.take_tool(Steve);
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
		DirtDestroyer9001.use_shovel();
	}
	//IV3
	if (argc == 1 || argv[1][0] == '3')
	{
		if (argc == 1) {std::cout << std::endl << std::endl;}
		std::cout << "\tIV3 : " << std::endl;
		Shovel Steve;
		Hammer Charles;

		Worker workerA;
		Worker workerB;

		workerA.set_name("Jimbob");
		workerB.set_name("Bobert");
		workerA.take_tool(Steve);
		workerA.take_tool(Charles);

		workerB.take_tool(Steve);
		workerB.take_tool(Charles);
	}

	//IV4
	if (argc == 1 || argv[1][0] == '4')
	{
		if (argc == 1) {std::cout << std::endl << std::endl;}
		std::cout << "\tIV3 : " << std::endl;

		std::set<eToolTypes> workshopReqs1;
		workshopReqs1.insert(TT_HAMMER);

		Workshop workshop1(workshopReqs1);
		Workshop workshop2;
		
		workshop2.add_requirement(TT_SHOVEL);
		workshop2.add_requirement(TT_HAMMER);
	}
	return 0;
}