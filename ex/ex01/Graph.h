/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Graph.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 22:43:27 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/06/13 00:11:14 by argentumlun   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

struct Vector2
{
    public:
        float x;
        float y;

        Vector2() : x(0.0f), y(0.0f) {}
        Vector2(const float &a, const float &b) : x(a), y(b) {}
        Vector2(const Vector2 &src) 
        {
            x = src.x;
            y = src.y;
        }

        friend std::ostream &operator<<(std::ostream& p_os, const Vector2 &vect2)
        {
            p_os << "{" << (size_t)vect2.x << "," << (size_t)vect2.y << "}";
			return (p_os);
        }
};

class Graph
{
    private:
        Vector2 size;
        std::vector<Vector2 *>  points;

    public:
        Graph();
        ~Graph(); 

        void addVector (const float &xPos, const float &yPos);
        void addVector (const Vector2 &cpyVect);
        void displayGraph(void);
};
