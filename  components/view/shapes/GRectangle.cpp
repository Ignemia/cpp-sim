//
// Created by adam on 7/20/2021.
//

#include "GRectangle.hpp"

void GRectangle::Draw(GWindow &in_Window)
{
	in_Window.root.clear();
	sf::VertexArray l_Vertices = sf::VertexArray(sf::Quads, 4);
	l_Vertices[0] = (sf::Vector2f(this->m_Position[0] - this->m_Sizes[0], this->m_Position[1] - this->m_Sizes[1]));
	l_Vertices[1] = (sf::Vector2f(this->m_Position[0] - this->m_Sizes[0], this->m_Position[1] + this->m_Sizes[1]));
	l_Vertices[2] = (sf::Vector2f(this->m_Position[0] + this->m_Sizes[0], this->m_Position[1] + this->m_Sizes[1]));
	l_Vertices[3] = (sf::Vector2f(this->m_Position[0] + this->m_Sizes[0], this->m_Position[1] - this->m_Sizes[1]));
	
	// We going RGB bitch
	l_Vertices[0].color = sf::Color::Red;
	l_Vertices[1].color = sf::Color::Cyan;
	l_Vertices[2].color = sf::Color::Green;
	l_Vertices[3].color = sf::Color::Blue;
	in_Window.root.draw(l_Vertices);
	in_Window.root.display();
}