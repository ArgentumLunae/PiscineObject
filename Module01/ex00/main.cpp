/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:12:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/08 14:37:44 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "IV1.hpp"

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
}