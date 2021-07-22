#include <GVertex.hpp>
#include <iostream>
#include "Window.hpp"

GWindow *GWindow::m_Instance = nullptr;

GWindow::GWindow()
{
	auto t_WindowSize = root.getSize();
	GVertex::Set_Origin((float) (t_WindowSize.x / 2.0), (float) (t_WindowSize.y / 2.0));
}

void GWindow::Run(std::vector<GRectangle>& in_Rects)
{
	for (auto r : in_Rects)
	{
		r.Draw(this->root);
	}
	
	while (this->root.isOpen())
	{
		sf::Event event{};
		while (this->root.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->root.close();
			}
		}
		this->root.clear();
		
		for (auto r : in_Rects)
		{
			r.Draw(this->root);
		}
		
		this->root.display();
	}
}

GWindow &GWindow::Get_Instance()
{
	
	if (GWindow::m_Instance == nullptr)
	{
		GWindow::m_Instance = new GWindow();
	}
	
	return *GWindow::m_Instance;
}
