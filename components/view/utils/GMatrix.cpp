//
// Created by adam on 7/29/2021.
//

#include "GMatrix.hpp"

GMatrix::GMatrix(float in_m, float in_n)
{

}

GMatrix::GMatrix(float in_m, float in_n, const float& in_default)
{

}

GMatrix::GMatrix(float in_m, float in_n, const std::vector<float>& in_Values)
{

}

std::vector<float> GMatrix::Multiply(const GMatrix& in_Other) const
{
	return {};
}

float GMatrix::DotProduct(const GMatrix& in_Other) const
{
	return 0;
}

float GMatrix::GetDeterminant(const GMatrix& in_Other) const
{
	return 0;
}

std::vector<float> GMatrix::Add(const GMatrix& in_Other) const
{
	return {};
}

std::vector<float> GMatrix::Subtract(const GMatrix& in_Other) const
{
	return {};
}
