//
// Created by adam on 7/23/2021.
//
#pragma once
#ifndef SIM_GCOLOR_HPP
#define SIM_GCOLOR_HPP

#include <string>
#include <vector>
#include <SFML/Graphics/Color.hpp>

struct HSVMeta
{
	float fMin, fMax;
	float rgb[3];
	char charMin, charMax;
};

class GColor
{
private:
	uint8_t rgba[4] = {0, 0, 0, 255};
	HSVMeta getHSVSetup();
public:
	GColor();
	explicit GColor(const unsigned int& in_GrayScale);
	GColor(const unsigned int& in_GrayScale, const unsigned int& in_Opacity);
	GColor(const unsigned int& in_Red, const unsigned int& in_Green, const unsigned int& in_Blue);
	GColor(const unsigned int& in_Red, const unsigned int& in_Green, const unsigned int& in_Blue, const unsigned int& in_Opacity);
	static GColor Parse_HSV(const std::vector<float>& in_HSV);
	static GColor Parse_Wavelength(const unsigned int& in_Value);
	static GColor Parse_String(const std::string& in_Value);
	static GColor Get_Random();
	static std::vector<GColor> Random(const size_t& in_Count);
	void SetOpacity(unsigned int in_NewOpacity);
	void SetRed(unsigned int in_NewRed);
	void SetGreen(unsigned int in_NewGreen);
	void SetBlue(unsigned int in_NewBlue);
	void SetHue(float in_NewHue);
	void SetSaturation(float in_NewSaturation);
	void SetValue(float in_NewValue);
	unsigned int GetRed();
	unsigned int GetGreen();
	unsigned int GetBlue();
	float GetHue();
	float GetSaturation();
	float GetValue();
	std::string GetString();
	GColor GetComplimentaryColors(const unsigned int in_Count);
	sf::Color ToSFML();
};

#endif //SIM_GCOLOR_HPP
