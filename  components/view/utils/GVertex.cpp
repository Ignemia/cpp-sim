//
// Created by adam on 7/21/2021.
//

#include <iostream>
#include "GVertex.hpp"

float GVertex::s_Origin[2]{0, 0};
GVertex GVertex::s_OriginVertex(GVertex(GVertex::s_Origin[0], GVertex::s_Origin[1]));

void GVertex::Set_Origin(const float& in_X, const float& in_Y)
{
	GVertex::s_Origin[0] = in_X;
	GVertex::s_Origin[1] = in_Y;
	std::cout << "[ " << s_Origin[0] << " : " << s_Origin[1] << " ]" << std::endl;
	GVertex::s_OriginVertex = GVertex(GVertex::s_Origin[0], GVertex::s_Origin[1]);
}

const GVertex* GVertex::Get_Origin_Vertex()
{
	return &GVertex::s_OriginVertex;
}

sf::Vector2f GVertex::GetVector() const
{
	
	float t_X = GVertex::s_Origin[0] + this->m_X;
	float t_Y = GVertex::s_Origin[1] - this->m_Y;
	
	if (this->m_RelationPoint != Get_Origin_Vertex())
	{
		t_X += this->m_RelationPoint->m_X;
		t_Y += this->m_RelationPoint->m_Y;
	}
	
	return sf::Vector2f(t_X, t_Y);
}

void GVertex::SetX(const float& in_X)
{
	this->m_X = in_X;
}

void GVertex::SetY(const float& in_Y)
{
	this->m_Y = in_Y;
}

void GVertex::SetRelationPoint(const GVertex* in_Vertex)
{
	this->m_RelationPoint = in_Vertex;
}

void GVertex::TranslateX(const float& in_Amount)
{
	this->m_X += in_Amount;
}

void GVertex::TranslateY(const float& in_Amount)
{
	this->m_Y += in_Amount;
}

void GVertex::Translate(const float in_Amounts[2])
{
	this->TranslateX(in_Amounts[0]);
	this->TranslateY(in_Amounts[1]);
}
