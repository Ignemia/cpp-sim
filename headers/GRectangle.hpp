//
// Created by adam on 7/20/2021.
//

#ifndef SIM_GRECTANGLE_HPP
#define SIM_GRECTANGLE_HPP

#include <Window.hpp>
#include <SFML/Graphics.hpp>

class GRectangle
{
public:
	float m_Sizes[2] = {50, 100};
	
	float m_Position[2] = {480, 260};
	
	void Draw(GWindow &in_Window);
};

#endif //SIM_GRECTANGLE_HPP
