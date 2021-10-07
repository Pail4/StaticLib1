// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

//#include "pch.h"
//#include "framework.h"
#include "Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>


namespace Shapes
{
    SimplePoint::SimplePoint()
    {
        auto size = window.getSize();
        windowWidth = size.x;
        windowHeight = size.y;
        this->x = x;
        this->y = y;
        object = NULL;
        if (show) Show();
        visible = show;
    }
    SimplePoint::~SimplePoint()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }
    SimplePoint::virtual void Draw()
    {
        if (object == NULL)
        {
            object = new sf::CircleShape(1);
        }
        sf::CircleShape* circle = static_cast<sf::CircleShape*>(object);
        //sf::CircleShape* circle = (sf::CircleShape*)object;
        if (show)
        {
            object->setFillColor(sf::Color(255, 255, 255));
            object->setOutlineColor(sf::Color(255, 255, 255));
        }
        else
        {
            object->setFillColor(sf::Color(0, 0, 0));
            object->setOutlineColor(sf::Color(0, 0, 0));
        }
        object->setOutlineThickness(1);
        object->move(x, y);
        window.draw(*object);
    }
}
