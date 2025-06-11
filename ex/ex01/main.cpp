/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 23:39:54 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/06/12 00:07:53 by argentumlun   ########   odam.nl         */
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
    graph1.addVector(10.0f, 2.0f);
    graph1.addVector(7.0f, 1.0f);
    graph1.addVector(3.0f, 4.0f);
    graph1.displayGraph();

    return (0);
}