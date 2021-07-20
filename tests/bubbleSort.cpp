#ifndef BS_TEST
#define BS_TEST

#include <vector>
#include <iostream>
#include "Window.h"
#include "../ components/view/shapes/GRectangle.h"

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
			std::vector< int > s_inp = {
					665, 599, 134, 208, 3, 133, 215, 705, 691, 691, 87, 179, 344, 86, 824, 749, 695, 173, 222, 524, 598, 741, 359, 638, 330, 586, 961,
					376, 716, 113, 330, 602, 280, 394, 544, 991, 642, 465, 42, 879, 802, 918, 278, 904, 922, 489
			};
			
			template < typename T >
			void swap_pointer_values( T* in_Pt1, T* in_Pt2 )
				{
					
					T l_Save = *in_Pt2;
					*in_Pt2 = *in_Pt1;
					*in_Pt1 = l_Save;
				}
			
			bool sort_pass( std::vector< int >& in_Query )
				{
					
					bool out_ChangesMade = false;
					for ( size_t i = 0; i < in_Query.size() - 1; i ++ )
						{
							auto l_Current = in_Query.at( i );
							auto l_Next = in_Query.at( i + 1 );
							if ( l_Current > l_Next )
								{
									auto l_CurrentPtr = &in_Query.at( i );
									auto l_NextPtr = &in_Query.at( i + 1 );
									swap_pointer_values( l_CurrentPtr, l_NextPtr );
									out_ChangesMade = true;
								}
						}
					return out_ChangesMade;
				}
			
			void draw( int in_Count )
				{
					
					std::printf( "Pass #%i\n", in_Count );
				}
			
			void run( )
				{
					
					GWindow& window = GWindow::Get_Instance();
					GRectangle rect;
					rect.Draw(window);
					window.Run();
					int counter = 0;
					do
						{
							draw( counter );
							counter ++;
						}
					while ( sort_pass( s_inp ) );
				}
	}
#endif