//
// Created by adam on 7/29/2021.
//
#pragma once
#ifndef SIM_GMATRIX_HPP
#define SIM_GMATRIX_HPP

#include <vector>

class GMatrix
{
	GMatrix(float in_m, float in_n);
	GMatrix(float in_m, float in_n, const float& in_default);
	GMatrix(float in_m, float in_n, const std::vector<const float>& in_Values);
	std::vector<float> Multiply(const GMatrix& in_Other) const;
	float DotProduct(const GMatrix& in_Other) const;
	float GetDeterminant(const GMatrix& in_Other) const;
	std::vector<float> Add(const GMatrix& in_Other) const;
	std::vector<float> Subtract(const GMatrix& in_Other) const;
};

#endif //SIM_GMATRIX_HPP
