//
// Created by adam on 7/29/2021.
//

#include "GMatrix.hpp"

GMatrix::GMatrix(std::size_t in_m, std::size_t in_n) {
    this->m_Data.reserve(in_m * in_n);
    this->m_Data = {0};
}

GMatrix::GMatrix(std::size_t in_m, std::size_t in_n, const float &in_default) {
    this->m_Data.reserve(in_m * in_n);
    this->m_Data = {0};
}

GMatrix::GMatrix(std::size_t in_m, std::size_t in_n, const std::vector<const float> &in_Values) {
    this->m_Data.reserve(in_m * in_n);
    this->m_Data = {0};
}

std::vector<float> GMatrix::Multiply(const GMatrix& in_Other)
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

std::vector<float> GMatrix::Add(const GMatrix &in_Other) const {
    return {};
}

std::vector<float> GMatrix::Subtract(const GMatrix &in_Other) const {
    return {};
}

float GMatrix::Retrieve(std::size_t in_PosX, std::size_t in_PosY) const {
    return 0;
}
