//
// Created by adam on 7/21/2021.
//
#pragma once
#ifndef SIM_GVERTEX_HPP
#define SIM_GVERTEX_HPP

#include <SFML/Graphics.hpp>

class GVertex
{
private:
	static float s_Origin[2];
	static GVertex s_OriginVertex;

private:
	float m_X = 0;
	float m_Y = 0;
	GVertex* m_RelationPoint = (GVertex*) GVertex::Get_Origin_Vertex();
public:
	GVertex()
	{}
	
	explicit GVertex(const float& XY)
			: m_X(XY), m_Y(XY)
	{};
	
	GVertex(const float& X, const float& Y)
			: m_X(X), m_Y(Y)
	{};
	
	GVertex(const float& X, const float& Y, GVertex* in_RelationPoint)
			: m_X(X), m_Y(Y), m_RelationPoint(in_RelationPoint)
	{};
	
	static const GVertex* Get_Origin_Vertex();
	static void Set_Origin(const float& in_X, const float& in_Y);
	sf::Vector2f GetVector() const;
	void SetX(const float& in_X);
	void SetY(const float& in_Y);
	float GetX() const;
	float GetY() const;
	float GetAbsoluteX() const;
	float GetAbsoluteY() const;
	void SetRelationPoint(GVertex* in_Vertex);
	void TranslateX(const float& in_Amount);
	void TranslateY(const float& in_Amount);
	void Translate(const float in_Amounts[2]);
};

#endif //SIM_GVERTEX_HPP
