//
// Created by adam on 7/20/2021.
//

#include "GRectangle.hpp"

GRectangle::GRectangle(const float& in_OriginX, const float& in_OriginY, const float& in_Width, const float& in_Height)
{
	m_Sizes[0] = in_Width;
	m_Sizes[1] = in_Height;
	m_Position = GVertex(in_OriginX, in_OriginY);
	float t_X = m_Sizes[0] / 2;
	float t_Y = m_Sizes[1] / 2;
	m_Vertices[0] = GVertex(-t_X, -t_Y, &m_Position);   // -x -y
	m_Vertices[1] = GVertex(-t_X, t_Y, &m_Position);    // -x +y
	m_Vertices[2] = GVertex(t_X, t_Y, &m_Position);     // +x +y
	m_Vertices[3] = GVertex(t_X, -t_Y, &m_Position);    // +x -y
}

sf::VertexArray GRectangle::GetVertexArray()
{
	sf::VertexArray out_VertexArray = sf::VertexArray(sf::Quads, 4);
	for (size_t i = 0; i < 4; i++) out_VertexArray[i] = m_Vertices[i].GetVector();
	return out_VertexArray;
}

void GRectangle::Draw(GWindow& in_Window)
{
	in_Window.root.clear();
	in_Window.root.draw(GetVertexArray());
	in_Window.root.display();
}