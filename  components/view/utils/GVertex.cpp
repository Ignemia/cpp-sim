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
	GVertex::s_OriginVertex = GVertex(GVertex::s_Origin[0], GVertex::s_Origin[1]);
}

const GVertex* GVertex::Get_Origin_Vertex()
{
	return &GVertex::s_OriginVertex;
}

sf::Vector2f GVertex::GetVector() const
{
	float t_X = GetAbsoluteX();
	float t_Y = GetAbsoluteY();
	sf::Vector2f out_Vector = sf::Vector2f(t_X, t_Y);
	return out_Vector;
}

void GVertex::SetX(const float& in_X)
{
	this->m_X = in_X;
}

void GVertex::SetY(const float& in_Y)
{
	this->m_Y = in_Y;
}

float GVertex::GetX() const
{
	return this->m_X;
}

float GVertex::GetY() const
{
	return this->m_Y;
}

float GVertex::GetAbsoluteX() const
{
	float out_X = 0;
	GVertex* t_Traversal = this->m_RelationPoint;
	do
	{
		out_X += t_Traversal->GetX();
		t_Traversal = t_Traversal->m_RelationPoint;
	} while (t_Traversal != GVertex::Get_Origin_Vertex());
	return out_X + this->GetX();
}

float GVertex::GetAbsoluteY() const
{
	float out_Y = 0;
	GVertex* t_Traversal = this->m_RelationPoint;
	do
	{
		out_Y -= t_Traversal->GetY();
		t_Traversal = t_Traversal->m_RelationPoint;
	} while (t_Traversal != GVertex::Get_Origin_Vertex());
	out_Y += t_Traversal->GetY();
	return out_Y - this->GetY();
}

void GVertex::SetRelationPoint(GVertex* in_Vertex)
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
