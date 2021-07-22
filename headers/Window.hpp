#ifndef SIM_WINDOW_HPP
#define SIM_WINDOW_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include "GRectangle.hpp"

#define D_WIDTH 1280
#define D_HEIGHT 720

struct DrawFunction
{
	const char* name;
};

///
/// @brief GWindow is a Graphics SFML window with all important properties of given application
///
class GWindow
{
protected:
	///
	/// @brief Singleton instance of GWindow
	///
	static GWindow* m_Instance;

private:
	///
	///@brief Window width
	///
	size_t WIDTH = D_WIDTH;
	
	///
	/// @brief Window height
	///
	size_t HEIGHT = D_HEIGHT;

private:
	///
	/// @brief Constructor
	///
	GWindow();

public:
	std::vector<std::function<void(sf::RenderWindow*)>> m_drawFunction;
	///
	/// @brief Root SFML window
	///
	sf::RenderWindow root = sf::RenderWindow(sf::VideoMode(D_WIDTH, D_HEIGHT), "");
	
	///
	/// @brief Copy constructor just deletes
	///
	GWindow(GWindow& other) = delete;
	
	///
	/// @brief Clone assignment deletes
	///
	void operator=(const GWindow&) = delete;
	
	///
	/// @brief If instance is present returns it. If not assigns it and then returns it
	///
	static GWindow& Get_Instance();
	
	///
	/// @brief Opening the window
	///
	void Run();
};

#endif //SIM_WINDOW_HPP
