/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Graph.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 22:59:34 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/06/11 23:47:51 by argentumlun   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.h"

Graph::Graph() : size(0, 0) {}

Graph::~Graph() 
{
    for (std::vector<Vector2 *>::iterator iter = points.begin(); iter != points.end(); iter++)
        delete *iter;
    points.clear();
}

void Graph::addVector (const float &xPos, const float &yPos)
{
    Vector2 *newVect = new Vector2(xPos, yPos);
    points.push_back(newVect);
        if ((size_t)xPos >= (size_t)size.x)
    size.x = xPos + 1.0f;
        if ((size_t)yPos >= (size_t)size.y)
    size.y = yPos + 1.0f;
}

void Graph::addVector (const Vector2 &cpyVect)
{
    Vector2 *newVect = new Vector2(cpyVect);
    points.push_back(newVect);
    if ((size_t)newVect->x >= (size_t)size.x)
        size.x = newVect->x + 1.0f;
    if ((size_t)newVect->y >= (size_t)size.y)
        size.y = newVect->y + 1.0f;
}

void Graph::displayGraph(void)
{
    std::cout << "Display Graph:" << std::endl;
    for (int i = (int)size.y; i >= 0; i--)
    {
        std::cout << i;
        for (size_t j = 0; j <= (size_t)size.x; j++)
        {
            std::vector<Vector2 *>::iterator iter;
            for (iter = points.begin(); iter != points.end(); iter++)
            {
                if (j == (size_t)(*iter)->x && i == (int)(*iter)->y)
                {
                    std::cout << " X";
                    break;
                }
            }
            if (iter == points.end())
               std::cout << " .";
        }
        std::cout << std::endl;
    }
    std::cout << ' ';
    for (size_t j = 0; j <= (size_t)size.x; j++)
        std::cout << ' ' << j;
    std::cout << std::endl;
}
