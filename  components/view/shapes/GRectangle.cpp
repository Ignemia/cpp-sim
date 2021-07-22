//
// Created by adam on 7/20/2021.
//

#include <iostream>
#include "GRectangle.hpp"

GRectangle::GRectangle(const float& in_OriginX, const float& in_OriginY, const float& in_Width, const float& in_Height)
{
//	std::cout << "[ " << in_OriginX << " : " << in_OriginY  << " ]"<< std::endl;
	this->m_Sizes[0] = in_Width;
	this->m_Sizes[1] = in_Height;
	this->m_Position = GVertex(in_OriginX, in_OriginY);
//	std::cout << "[ " << m_Position.GetX() << " : " << m_Position.GetY()  << " ]"<< std::endl;
	float t_X = float(this->m_Sizes[0] / 2.0);
	float t_Y = float(this->m_Sizes[1] / 2.0);
//	std::cout << "[ " << t_X << " : " << t_Y  << " ]"<< std::endl;
	this->m_Vertices[0] = GVertex(-t_X, -t_Y, &this->m_Position);   // -x -y
	this->m_Vertices[1] = GVertex(-t_X, t_Y, &this->m_Position);    // -x +y
	this->m_Vertices[2] = GVertex(t_X, t_Y, &this->m_Position);     // +x +y
	this->m_Vertices[3] = GVertex(t_X, -t_Y, &this->m_Position);    // +x -y
}

sf::VertexArray GRectangle::GetVertexArray()
{
	sf::VertexArray out_VertexArray = sf::VertexArray(sf::Quads, 4);
	for (size_t i = 0; i < 4; i++)
	{
		out_VertexArray[i] = this->m_Vertices[i].GetVector();

//		std::cout << m_Vertices[i].GetY() << std::endl;
		
		out_VertexArray[i].color = sf::Color::White;
	}
	return out_VertexArray;
}

void GRectangle::Draw(sf::RenderWindow& in_Window)
{
	in_Window.draw(GetVertexArray());
}

float GRectangle::GetHeight()
{
	return this->m_Sizes[1];
}