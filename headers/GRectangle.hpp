//
// Created by adam on 7/20/2021.
//

#ifndef SIM_GRECTANGLE_HPP
#define SIM_GRECTANGLE_HPP

#include <Window.hpp>
#include <SFML/Graphics.hpp>
#include "GVertex.hpp"

class GRectangle
{
private:
	float* m_Sizes = new float[2];
	GVertex m_Position;
	GVertex* m_Vertices = new GVertex[4];
public:
	GRectangle(const float& in_OriginX, const float& in_OriginY, const float& in_Width, const float& in_Height);
	sf::VertexArray GetVertexArray();
	void Draw(GWindow& in_Window);
};

#endif //SIM_GRECTANGLE_HPP
