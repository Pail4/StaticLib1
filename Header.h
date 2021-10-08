
#include <SFML/Graphics.hpp>
//using namespace std;



#pragma region SimplePoint

using namespace sf;

namespace Shapes
{
    class SimplePoint
    {

    protected:

        Shape* object;
        float x, y;
        bool visible;
        int windowWidth;
        int windowHeight;

    public:
        static RenderWindow window;

        SimplePoint(float x, float y, bool show); //: x(x), y(y), visible(show)
        SimplePoint();
        virtual ~SimplePoint();
        virtual void Draw(bool show);
        void Show();
        void Hide();
        void Move(float newX, float newY);
        void MoveRel(float dx, float dy);
        bool GetVisible();
        float GetX();
        float GetY();

    };

#pragma endregion

    class ColorPoint : public SimplePoint
    {
    protected:
        Color color;
    public:
        ColorPoint(float x, float y, Color color = Color(255, 255, 255), bool show = true);
        virtual ~ColorPoint();
        Color GetColor();
        void SetColor(Color newColor);
        virtual void Draw(bool show);
    };

    class Circle : public ColorPoint
    {
    protected:
        float radius;
    public:
        Circle(float x, float y, float radius = 1, sf::Color color = sf::Color(255, 255, 255), bool show = true);
        virtual ~Circle();
        float GetRadius();
        void SetRadius(float newRadius);
        virtual void Draw(bool show);
    };

    class Rectangle : public ColorPoint
    {
        float width;
        float height;

    public:
        Rectangle(float x, float y, float width, float height,
            Color color = sf::Color(255, 255, 255), bool show = true);
        virtual ~Rectangle();
        float GetWidth();
        float GetHeight();
        virtual void Draw(bool show);
    };

    class Line : public ColorPoint
    {
        float x2, y2;
        float lineLength;
        float angle;
    public:
        Line(float x1, float y1, float x2, float y2,
            Color color = Color(255, 255, 255),
            bool show = true);
        virtual ~Line();
        virtual void Draw(bool show);
    };
}

