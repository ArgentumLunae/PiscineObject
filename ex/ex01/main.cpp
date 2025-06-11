/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 23:39:54 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/06/11 23:50:31 by argentumlun   ########   odam.nl         */
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
    return (0);
}