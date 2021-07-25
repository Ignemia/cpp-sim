#ifndef BS_TEST
#define BS_TEST

#include <vector>
#include <iostream>
#include <functional>
#include <GColor.hpp>
#include <cmath>
#include "Window.hpp"
#include "GRectangle.hpp"

/*
 *
 * Top-Down analysis:
 * Task: Create a visualisation of bubble sort sorting colors by the numeric value of it's hex code.
 * Major milestones:
 *  1.  Get a Bubble Sort going (done)
 *  2.  Open a window with a bunch of white rectangles of different heights based on their values and visualise each step of sorting - ×
 *  3.  Make rectangles into squares and give them colors mapped from #000000 to #FFFFFF based on it's value from vector and display each step below
 *  previous - ×
 *  4. Refactor everything and move on (be done) - ×
 *
 *  Milestone breakdown:
 *  1)  done
 *  2)  - Open a window
 *          × | import my GWindow class
 *      - Create rectangles with height based on their value
 *          | Create GRectangle class in view / shapes - constructor with random height and width
 *          | Implement draw function in the GRectangle class
 *          | Make a constructor that takes in width and height
 *          | Create a rectangle in the middle of the window
 *          | Allow positioning (add position to GRectangle class)
 *          | Make a bunch of them randomly placed
 *          | Make a bunch of them next to each other
 *          | Map 0-1000 to min-max height
 *      - visualise each step of sorting
 *          | Clear canvas
 *          | Draw background
 *          | Draw each rectangle
 *  3)  - Make rectangles into squares of color
 *          | Draw rectangles with height = width
 *          | Create basis for GColor class
 *          | Add m_HEX, m_RGB and m_Num (numeric value) to GColor class
 *          | Draw rectangles in their respective color with mapping from #000000 to #FFFFFF
 */



namespace BS_TEST {
	int g_WindowWidth = 1280;
	float g_Density = 3.f;
	int g_Count = g_WindowWidth * g_Density;
	
	std::vector<int> s_Inp;
	
	void swap_pointer_values(GRectangle* in_Pt1, GRectangle* in_Pt2)
	{
		GRectangle t_Save = *in_Pt2;
		*in_Pt2 = *in_Pt1;
		*in_Pt1 = t_Save;
	}
	
	bool sort_pass(std::vector<GRectangle>& in_Query)
	{
		
		bool out_ChangesMade = false;
		for (size_t i = 0; i < in_Query.size() - 1; i++)
		{
			GRectangle& l_Current = in_Query.at(i);
			GRectangle& l_Next = in_Query.at(i + 1);
			if (l_Current.GetColor().GetHue() > l_Next.GetColor().GetHue())
			{
				
				swap_pointer_values(&l_Current, &l_Next);
				
				float t_Save = l_Current.GetX();
				l_Current.SetX(l_Next.GetX());
				l_Next.SetX(t_Save);
				
				out_ChangesMade = true;
			}
		}
		return out_ChangesMade;
	}
	
	void GenerateValues()
	{
		s_Inp.reserve(g_Count);
		std::srand(std::time(NULL));
		
		for (int i = 0; i < g_Count + 1; i++)
		{
			s_Inp.emplace_back(rand() % 1000);
		}
	}
	
	void GenerateRectangles(std::vector<GRectangle>& rectangles)
	{
		float t_Width = 1280.0f / float(g_Count);
		int counter = 0;
		for (auto i : s_Inp)
		{
			float t_XPos = counter * t_Width + t_Width / 2;
			auto t_Hue = [&]()
			{
				float l_Max = 2 * M_PI;
				float l_Min = 0;
				float bottom = 0.0f;
				float top = 1000.0f;
				
				return l_Min + ((top - (float) i) / (top - bottom)) * (l_Max - l_Min);
			};
			auto c = GColor::Parse_HSV({t_Hue(), 1.f, 1.f});
			auto* n = new GRectangle(t_XPos, 0, t_Width, 150, c);
			rectangles.push_back(*n);
			counter++;
		}
	}
	
	void run()
	{
		GenerateValues();
		GWindow& window = GWindow::Get_Instance();
		std::vector<GRectangle> v_Rects;
		GenerateRectangles(v_Rects);
		std::function<void(sf::RenderWindow*)> a = [&](sf::RenderWindow*)
		{
			for (auto rect : v_Rects) rect.Draw(window.root);
			if (!sort_pass(v_Rects))
			{
				s_Inp.clear();
				v_Rects.clear();
				GenerateValues();
				GenerateRectangles(v_Rects);
			}
		};
		window.m_drawFunction.push_back(a);
		window.Run();
	}
}
#endif