//
// Created by adam on 7/29/2021.
//
#pragma once
#ifndef SIM_GMATRIX_HPP
#define SIM_GMATRIX_HPP

struct V2D {
    unsigned long long int m, n;
};

#include <vector>

class GMatrix {
private:
    std::vector<float> m_Data;
    V2D m_Size = {0, 0};
public:
    GMatrix(std::size_t in_m, std::size_t in_n);

    GMatrix(std::size_t in_m, std::size_t in_n, const float &in_default);

    GMatrix(std::size_t in_m, std::size_t in_n, const std::vector<const float> &in_Values);
	
	float Retrieve(std::size_t in_PosX, std::size_t in_PosY) const;

    float DotProduct(const GMatrix &in_Other) const;

    float GetDeterminant(const GMatrix &in_Other) const;
	
	std::vector<float> Multiply(const GMatrix &in_Other) ;

    std::vector<float> Add(const GMatrix &in_Other) const;

    std::vector<float> Subtract(const GMatrix &in_Other) const;
};

#endif //SIM_GMATRIX_HPP
