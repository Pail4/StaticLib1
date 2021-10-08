// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

//#include "pch.h"
//#include "framework.h"
#include "Header.h"
#include <SFML/Graphics.hpp>

namespace Shapes
{
    SimplePoint::SimplePoint(float x, float y, bool show)
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
    SimplePoint::SimplePoint() :SimplePoint(0, 0, false)
    {

    }
    SimplePoint::~SimplePoint()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }
    void SimplePoint::Draw(bool show)
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
    void SimplePoint:: Show()
    {
        Draw(true);
        visible = true;
    }
    void SimplePoint::Hide()
    {
        Draw(false);
        visible = false;
    }
    void SimplePoint::Move(float newX, float newY)
    {
        bool visibleState = visible;
        Hide();
        x = newX;
        y = newY;
        if (visibleState) Show();
        visible = visibleState;
    }

    void SimplePoint::MoveRel(float dx, float dy)
    {
        bool visibleState = visible;
        Hide();
        x += dx;
        y += dy;
        if (visibleState) Show();
        visible = visibleState;
    }
    bool SimplePoint::GetVisible()
    {
        return visible;
    }

    float SimplePoint::GetX()
    {
        return x;
    }

    float SimplePoint::GetY()
    {
        return y;
    }

    ///////

    ColorPoint::ColorPoint(float x, float y, sf::Color color, bool show) :SimplePoint(x, y, false), color(color)
    {
        visible = show;
        if (show) Show();
    }

    ColorPoint::~ColorPoint()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }

    sf::Color ColorPoint::GetColor() { return color; }

    void ColorPoint::SetColor(sf::Color newColor)
    {
        bool show = GetVisible();
        if (show) Hide();
        color = newColor;
        if (show) Show();
    }

    void ColorPoint::Draw(bool show)
    {
        if (object == NULL)
        {
            object = new sf::CircleShape(1);
        }
        //sf::CircleShape* circle = static_cast<sf::CircleShape*>(object);
        if (show)
        {
            object->setFillColor(color);
            object->setOutlineColor(sf::Color(color));
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
    //////////////////

    Circle::Circle(float x, float y, float radius, sf::Color color, bool show) : ColorPoint(x, y, color, false), radius(radius)
    {
        visible = show;
        //object = NULL;
        if (show) Show();
    }

    Circle::~Circle()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }

    float Circle::GetRadius() { return radius; }

    void Circle::SetRadius(float newRadius)
    {
        bool show = GetVisible();
        if (show) Hide();
        radius = newRadius;
        if (show) Show();
    }

    void Circle::Draw(bool show)
    {
        if (object == NULL)
        {
            object = new sf::CircleShape(radius);
        }
        //sf::CircleShape* circle = static_cast<sf::CircleShape*>(object);
        if (show)
        {
            object->setFillColor(color);
            object->setOutlineColor(sf::Color(color));
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
    //////////////
    Rectangle::Rectangle(float x, float y, float width, float height,
        sf::Color color, bool show) : ColorPoint(x, y, color, false)
    {
        this->width = width;
        this->height = height;
        visible = show;
        if (show) Show();
    }

    Rectangle:: ~Rectangle()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }

    float Rectangle::GetWidth() { return width; }
    float Rectangle::GetHeight() { return height; }

    void Rectangle::Draw(bool show)
    {
        if (object == NULL)
        {
            object = new sf::RectangleShape(sf::Vector2f(width, height));
        }
        //sf::RectangleShape* rectangle = static_cast<sf::RectangleShape*>(object);

        if (show)
        {
            object->setFillColor(color);
            object->setOutlineColor(sf::Color(color));
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
    ////////////
    Line::Line(float x1, float y1, float x2, float y2,
        sf::Color color,
        bool show) : ColorPoint(x1, y1, color, false), x2(x2), y2(y2)
    {
        float xStart = GetX();
        float yStart = GetY();
        lineLength = sqrt((xStart - x2) * (xStart - x2) + (yStart - y2) * (yStart - y2));
        angle = atan((yStart - y2) / (xStart - x2)) * 180 / 3.14159265358979323846264;
        visible = show;
        if (show) Show();
    }

    Line:: ~Line()
    {
        if (visible)
            Hide();
        if (object) delete object;
        object = NULL;
    }

    void Line::Draw(bool show)
    {
        if (object == NULL)
        {
            object = new sf::RectangleShape(sf::Vector2f(lineLength, 1));
            //object->setOrigin(GetX(), GetY());
            object->rotate(angle);
        }
        sf::RectangleShape* rectangle = static_cast<sf::RectangleShape*>(object);
        if (show)
        {
            rectangle->setFillColor(color);
            rectangle->setOutlineColor(sf::Color(color));
        }
        else
        {
            rectangle->setFillColor(sf::Color(0, 0, 0));
            rectangle->setOutlineColor(sf::Color(0, 0, 0));
        }
        rectangle->setOutlineThickness(1);
        rectangle->move(x, y);
        window.draw(*rectangle);
    }
}
