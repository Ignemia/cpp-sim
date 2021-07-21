//
// Created by adam on 7/21/2021.
//

#ifndef SIM_GVERTEX_HPP
#define SIM_GVERTEX_HPP
#pragma once

#include <SFML/Graphics.hpp>

class GVertex
{
private:
	static float s_Origin[2]{0, 0};
	float m_X;
	float m_Y;

public:
	GVertex(float x, float y) : m_X(x), m_Y(y)
	{
	
	}
	
	sf::Vector2f GetVector() const
	{
		
		return sf::Vector2f(GVertex::s_Origin[0] + this->m_X, GVertex::s_Origin[1] - this->m_Y);
	}
	
};

#endif //SIM_GVERTEX_HPP
