#include "Window.h"

GWindow* GWindow::m_Instance = nullptr;

GWindow::GWindow( )
	{
	
	}

void GWindow::Run( )
	{
		
		while ( this->root.isOpen() )
			{
				sf::Event event{};
				while ( this->root.pollEvent( event ) )
					{
						if ( event.type == sf::Event::Closed )
							{
								this->root.close();
							}
					}
			}
	}


GWindow& GWindow::Get_Instance( )
	{
		
		if ( GWindow::m_Instance == nullptr )
			{
				GWindow::m_Instance = new GWindow();
			}
		
		return *GWindow::m_Instance;
	}
