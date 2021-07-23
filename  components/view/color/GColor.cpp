//
// Created by adam on 7/23/2021.
//

#include <cmath>
#include "GColor.hpp"

HSVMeta GColor::getHSVSetup()
{
	float t_Red_ = float(this->rgba[0]) / 255.0f;
	float t_Green_ = float(this->rgba[1]) / 255.0f;
	float t_Blue_ = float(this->rgba[2]) / 255.0f;
	
	float& l_Min = t_Red_;
	char l_MinChar = 'R';
	if (t_Green_ < l_Min)
	{
		l_Min = t_Green_;
		l_MinChar = 'G';
	}
	if (t_Blue_ < l_Min)
	{
		l_Min = t_Blue_;
		l_MinChar = 'B';
	}
	
	float& l_Max = t_Red_;
	char l_MaxChar = 'R';
	if (t_Green_ > l_Min)
	{
		l_Max = t_Green_;
		l_MaxChar = 'G';
	}
	if (t_Blue_ > l_Min)
	{
		l_Max = t_Blue_;
		l_MaxChar = 'B';
	}
	
	return {l_Min, l_Max, {t_Red_, t_Green_, t_Blue_}, l_MinChar, l_MaxChar};
}

GColor::GColor() = default;

GColor::GColor(const unsigned int& in_GrayScale)
{
	rgba[0] = in_GrayScale;
	rgba[1] = in_GrayScale;
	rgba[2] = in_GrayScale;
}

GColor::GColor(const unsigned int& in_GrayScale, const unsigned int& in_Opacity)
{
	rgba[0] = in_GrayScale;
	rgba[1] = in_GrayScale;
	rgba[2] = in_GrayScale;
	rgba[3] = in_Opacity;
}

GColor::GColor(const unsigned int& in_Red, const unsigned int& in_Green, const unsigned int& in_Blue)
{
	rgba[0] = in_Red;
	rgba[1] = in_Green;
	rgba[2] = in_Blue;
}

GColor::GColor(const unsigned int& in_Red, const unsigned int& in_Green, const unsigned int& in_Blue, const unsigned int& in_Opacity)
{
	rgba[0] = in_Red;
	rgba[1] = in_Green;
	rgba[2] = in_Blue;
	rgba[3] = in_Opacity;
}

GColor GColor::Parse_HSV(const std::vector<unsigned int> in_HSV)
{
	// todo: finish parsing
	return GColor();
}

GColor GColor::Parse_Wavelength(const unsigned int& in_Value)
{
	// todo: finish parsing
	return GColor();
}

GColor GColor::Parse_String(const std::string& in_Value)
{
	// todo: finish parsing
	return GColor();
}

std::vector<GColor> GColor::Random(const size_t& in_Count)
{
	std::vector<GColor> out_Vector;
	out_Vector.reserve(in_Count);
	for (size_t i = 0; i < in_Count; i++)
	{
		// todo: finish randomness
		out_Vector.emplace_back(*(new GColor()));
	}
	return out_Vector;
}

void GColor::SetOpacity(unsigned int in_NewOpacity)
{
	this->rgba[3] = in_NewOpacity;
}

void GColor::SetRed(unsigned int in_NewRed)
{
	this->rgba[0] = in_NewRed;
}

void GColor::SetGreen(unsigned int in_NewGreen)
{
	this->rgba[1] = in_NewGreen;
}

void GColor::SetBlue(unsigned int in_NewBlue)
{
	this->rgba[2] = in_NewBlue;
}

void GColor::SetHue(unsigned int in_NewHue)
{

}

void GColor::SetSaturation(unsigned int in_NewSaturation)
{

}

void GColor::SetValue(unsigned int in_NewValue)
{

}

unsigned int GColor::GetRed()
{
	return this->rgba[0];
}

unsigned int GColor::GetGreen()
{
	return this->rgba[1];
}

unsigned int GColor::GetBlue()
{
	return this->rgba[2];
}

float GColor::GetHue()
{
	HSVMeta l_HSVSetup = this->getHSVSetup();
	float l_Delta = l_HSVSetup.fMax - l_HSVSetup.fMin;
	float out_Angle = 60;
	switch (l_HSVSetup.charMax)
	{
		default: out_Angle *= ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta);
			break;
		case 'G': out_Angle *= ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta) + 2.0f;
			break;
		case 'B': out_Angle *= ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta) + 4.0f;
			break;
	}
	return M_PI * out_Angle / 180;
}

float GColor::GetSaturation()
{
	HSVMeta l_HSVSetup = this->getHSVSetup();
	if (l_HSVSetup.fMax == 0) return 0;
	return (l_HSVSetup.fMax - l_HSVSetup.fMin) / l_HSVSetup.fMax;
}

float GColor::GetValue()
{
	return this->getHSVSetup().fMax;
}

GColor GColor::GetComplimentaryColors(const unsigned int in_Count)
{
	// todo: finish
	return GColor();
}

sf::Color GColor::ToSFML()
{
	return sf::Color(rgba[0], rgba[1], rgba[2], rgba[3]);
}
