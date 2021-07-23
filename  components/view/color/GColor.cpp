//
// Created by adam on 7/23/2021.
//

#include "GColor.hpp"

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
	return GColor();
}

GColor GColor::Parse_Wavelength(const unsigned int& in_Value)
{
	return GColor();
}

GColor GColor::Parse_String(const std::string& in_Value)
{
	return GColor();
}

std::vector<GColor> GColor::Random(const size_t& in_Count)
{
	return std::vector<GColor>();
}

void GColor::SetOpacity(unsigned int in_NewOpacity)
{

}

void GColor::SetRed(unsigned int in_NewRed)
{

}

void GColor::SetGreen(unsigned int in_NewGreen)
{

}

void GColor::SetBlue(unsigned int in_NewBlue)
{

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
	return 0;
}

unsigned int GColor::GetGreen()
{
	return 0;
}

unsigned int GColor::GetBlue()
{
	return 0;
}

unsigned int GColor::GetHue()
{
	return 0;
}

unsigned int GColor::GetSaturation()
{
	return 0;
}

unsigned int GColor::GetValue()
{
	return 0;
}

GColor GColor::GetComplimentaryColors(const unsigned int in_Count)
{
	return GColor();
}

sf::Color GColor::ToSFML()
{
	return sf::Color();
}
