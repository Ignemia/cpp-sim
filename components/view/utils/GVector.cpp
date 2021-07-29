//
// Created by adam on 7/26/2021.
//

#include "GVector.hpp"
#include <math.h>

GVector::GVector(const float& in_DeltaX, const float& in_DeltaY)
{
	this->m_Magnitude = sqrt(pow(this->m_DeltaX, 2) + pow(this->m_DeltaY, 2));
	this->m_DeltaX = in_DeltaX / this->m_Magnitude;
	this->m_DeltaY = in_DeltaY / this->m_Magnitude;
};

GVector::GVector(GVertex* in_StartingPoint, const GVertex& in_Endpoint)
		: GVertex(*in_StartingPoint)
{
	float t_DeltaX = in_Endpoint.GetX() - this->m_X;
	float t_DeltaY = in_Endpoint.GetY() - this->m_Y;
	this->m_Magnitude = sqrt(pow(t_DeltaX, 2) + pow(t_DeltaY, 2));
	this->m_DeltaX = t_DeltaX / this->m_Magnitude;
	this->m_DeltaY = t_DeltaY / this->m_Magnitude;
};

void GVector::Rotate(const float& in_Alpha)
{

}

float GVector::GetMagnitude() const
{
	return this->m_Magnitude;
}

float GVector::GetDirection() const
{
	return std::asin(this->m_Magnitude / this->m_DeltaY);
}

float GVector::GetDeltaX() const
{
	return this->m_Magnitude * this->m_DeltaX;
}

float GVector::GetDeltaY() const
{
	return this->m_Magnitude * this->m_DeltaY;
}
