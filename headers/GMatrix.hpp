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
    GMatrix(size_t in_m, size_t in_n);

    GMatrix(size_t in_m, size_t in_n, const float &in_default);

    GMatrix(size_t in_m, size_t in_n, const std::vector<const float> &in_Values);

    std::vector<float> Multiply(const GMatrix &in_Other) const;

    float DotProduct(const GMatrix &in_Other) const;

    float GetDeterminant(const GMatrix &in_Other) const;

    std::vector<float> Add(const GMatrix &in_Other) const;

    std::vector<float> Subtract(const GMatrix &in_Other) const;

    float Retrieve(size_t in_PosX, size_t in_PosY) const;
};

#endif //SIM_GMATRIX_HPP
