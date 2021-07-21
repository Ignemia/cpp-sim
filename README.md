# Sim

A simple simulation framework that will provide you with Shapes, Window and Drawing capabilities, animation and other
important things you might need to create a simulation.

- Author: **Adam Opalecký**
- Language: **C++**
- IDE: **Clion**

## Libraries used:

- SFML
- Standard library

## Goal:

    To practice usage of C++ language, STD and SFML while making it fun for myself and possibly others.
    I need to get some habits that senior programmers have yet I as a junior do not

## Code Style
#### Variable Names

    Every variable name is in camelCase unless it has a prefix then it is in PascalCase. 
    Global constants are in SCREAMING_SNAKE_CASE

#### prefixes:

    _    = is private (_name)
    l_   = local variable (l_Save)
    m_   = member (instance) variable (m_Reader)
    c_   = local constant (c_MaxNumber)
    t_   = temporary variable (t_CurrentNude)
    s_   = static variable (s_ClassType)
    out_ = output variable
    in_  = input parameter
    v[t]_= vector of type t (vint_HeatMap)

### Function Names

    All functions are in snake_case.
    All class methods are in PascalCase.
    Static function are in Upper_Snake_Case.

### Class/Type Names

    All classes/types are named in PascalCase

### Namespace names

    Namespaces are named in 3-8 lowercase characters representing full name of the namespace
    eg: Opalecký Linked List -> oll::
        - or -    
        Opalecký Physics Simulations -> ops::

##Todo list of projects before finish:
- Bubble sort of colors based on their frequency - **×**
- Make bubbles fear the cursor and flee it also reverse when right-clicked - **×**
- Make a 3D cube made of 2D triangles (shaded) - **×**
- Maze Generator - **×**
- Fill a maze with bubbles - **×**
- Cursor echolocation - **×**
- Simulation of a bat navigating through maze using echolocation (AI) - **×**
