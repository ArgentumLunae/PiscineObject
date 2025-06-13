/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 23:39:54 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/06/13 12:22:06 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.h"

int main(void)
{
    Graph graph1;
    Vector2 vect1;
    Vector2 vect2(2.0f, 2.0f);

    graph1.addVector(vect1);
    graph1.addVector(vect2);
    graph1.addVector(4.0f, 2.0f);
    graph1.addVector(2.0f, 4.0f);
    graph1.displayGraph();

	Graph graph2;
	Vector2 vect3;
	vect3.x = vect1.y;
	vect3.y = vect2.x;

	graph2.addVector(vect3);
	graph2.addVector(-12.5f, 17.77f);
	graph2.displayGraph();

    return (0);
}