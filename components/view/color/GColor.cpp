//
// Created by adam on 7/23/2021.
//

#include <cmath>
#include <iostream>
#include "GColor.hpp"

#define PI_3 M_PI/3

HSVMeta GColor::getHSVSetup()
{
	
	std::cout << rgba[0]*1 << " , " << rgba[1]*1 << " , " << rgba[2]*1 << std::endl;
	
	int l_Min = rgba[0]*1;
	char l_MinChar = 'R';
	if (rgba[1]*1 < l_Min)
	{
		l_Min = rgba[1]*1;
		l_MinChar = 'G';
	}
	if (rgba[2]*1 < l_Min)
	{
		l_Min = rgba[2]*1;
		l_MinChar = 'B';
	}
	
	int l_Max = rgba[0]*1;
	char l_MaxChar = 'R';
	if (rgba[1]*1 > l_Max)
	{
		l_Max = rgba[1]*1;
		l_MaxChar = 'G';
	}
	if (rgba[2]*1 > l_Max)
	{
		l_Max = rgba[2]*1;
		l_MaxChar = 'B';
	}
	
	return {float(l_Min) / 255.f, float(l_Max) / 255.f,
			{float(rgba[0]) / 255.f, float(rgba[1]) / 255.f, float(rgba[2]) / 255.f},
			l_MinChar,l_MaxChar};
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

GColor GColor::Parse_HSV(const std::vector<float>& in_HSV)
{
	float H = in_HSV.at(0);
	float S = in_HSV.at(1);
	float V = in_HSV.at(2);
	
	double i = floor(double(H) * 6);
	double f = (H * 6) - i;
	
	float p = V * (1 - S);
	float q = V * (1 - (f * S));
	float t = V * (1 - ((1 - f) * S));
	
	float out_R_, out_G_, out_B_;
	
	if (H < PI_3)
	{
		out_R_ = V;
		out_G_ = t;
		out_B_ = p;
	} else if (H < 2 * PI_3)
	{
		out_R_ = q;
		out_G_ = V;
		out_B_ = p;
	} else if (H < M_PI)
	{
		out_R_ = p;
		out_G_ = V;
		out_B_ = t;
	} else if (H < 4 * PI_3)
	{
		out_R_ = p;
		out_G_ = q;
		out_B_ = V;
	} else if (H < 5 * PI_3)
	{
		out_R_ = t;
		out_G_ = p;
		out_B_ = q;
	} else
	{
		out_R_ = V;
		out_G_ = p;
		out_B_ = q;
	}
	
	uint8_t R = out_R_ * 255, G = out_G_ * 255, B = out_B_ * 255;

	std::cout << H*180/M_PI << "\t" << "(" << R*1 << ", " << G*1 << ", " << B*1 << ")" << std::endl;
	
	return GColor(R, G, B);
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

GColor GColor::Get_Random()
{
	srand(time(NULL));
	return *(new GColor(rand() % 255, rand() % 255, rand() % 255));
}

std::vector<GColor> GColor::Random(const size_t& in_Count = 1)
{
	std::vector<GColor> out_Vector;
	out_Vector.reserve(in_Count);
	srand(time(NULL));
	for (size_t i = 0; i < in_Count; i++)
	{
		out_Vector.emplace_back(*(new GColor(rand() % 255, rand() % 255, rand() % 255)));
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

void GColor::SetHue(float in_NewHue)
{
}

void GColor::SetSaturation(float in_NewSaturation)
{

}

void GColor::SetValue(float in_NewValue)
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
//	std::cout << l_HSVSetup.charMax << " - " << l_HSVSetup.fMax << "\t" << l_HSVSetup.charMin << " - " << l_HSVSetup.fMin << "\t"<< std::endl;
	float l_Delta = l_HSVSetup.fMax - l_HSVSetup.fMin;
	float out_Angle;
	switch (l_HSVSetup.charMax)
	{
		default: out_Angle = ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta);
			break;
		case 'G': out_Angle = ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta) + 2.0f;
			break;
		case 'B': out_Angle = ((l_HSVSetup.rgb[1] - l_HSVSetup.rgb[2]) / l_Delta) + 4.0f;
			break;
	}
	return out_Angle;
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

std::string GColor::GetString()
{
	char t_CharAR[3]{'0', '0', '\0'};
	itoa(this->rgba[0], t_CharAR, 16);
	
	char t_CharAG[3]{'0', '0', '\0'};
	itoa(this->rgba[1], t_CharAG, 16);
	
	char t_CharAB[3]{'0', '0', '\0'};
	itoa(this->rgba[2], t_CharAB, 16);
	
	std::string out_String = std::string(6, '0');
	
	if (std::string(t_CharAR).size() == 1)
	{
		out_String.at(1) = t_CharAR[0];
	} else
	{
		out_String.at(0) = t_CharAR[0];
		out_String.at(1) = t_CharAR[1];
	}
	
	if (std::string(t_CharAG).size() == 1)
	{
		out_String.at(3) = t_CharAG[0];
	} else
	{
		out_String.at(2) = t_CharAG[0];
		out_String.at(3) = t_CharAG[1];
	}
	if (std::string(t_CharAB).size() == 1)
	{
		out_String.at(5) = t_CharAB[0];
	} else
	{
		out_String.at(4) = t_CharAB[0];
		out_String.at(5) = t_CharAB[1];
	}
	
	return '#' + out_String;
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
