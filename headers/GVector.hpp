//
// Created by adam on 7/26/2021.
//
#pragma once
#ifndef SIM_GVECTOR_HPP
#define SIM_GVECTOR_HPP

#include "GVertex.hpp"

class GVector : GVertex
{
	float m_DeltaX = 1, m_DeltaY = 0, m_Magnitude = 1;
public:
	GVector(const float& in_deltaX, const float& in_deltaY);
	GVector(GVertex* in_startingPoint, const GVertex& in_endpoint);
	float GetMagnitude() const;
	float GetDirection() const;
	float GetDeltaX() const;
	float GetDeltaY() const;
	void Rotate(const float& in_Alpha);
};

#endif //SIM_GVECTOR_HPP
