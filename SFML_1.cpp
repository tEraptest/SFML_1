#include<iostream>

#include<cmath>

#include <SFML/Window.hpp>

using namespace std;

double F1(double x)
{
    return 2 * pow(x, 2);
}

double F2(double x)
{
    return 2 * x * x + 3 * x - 5;
}

double F3(double x)
{
    return pow((x - 3), 2) - 2;
}

double segment1(double eps, double a, double b)
{
    double n, h, x;

    n = 8; // в зависимости от кооличества шагов точность возрастает



    h = (b - a) / n;

    while (abs(b - a) > eps)
    {
        x = a;

        while ((F1(x) * F1(x + h)) > 0)
        {
            x = x + h;
        }

        a = x;

        b = x + h;

        h = h / n;
    }


    return (a + b) / 2;
}

double segment2(double eps, double a, double b)
{
    double n, h, x;

    n = 8; //в зависимости от кооличества шагов точность возрастает

    h = (b - a) / n;

    while (abs(b - a) > eps)
    {
        x = a;

        while ((F2(x) * F2(x + h)) > 0)
        {
            x = x + h;
        }

        a = x;

        b = x + h;

        h = h / n;
    }
    return (a + b) / 2;
}

double segment3(double eps, double a, double b)
{
    double n, h, x;

    n = 8;//в зависимости от кооличества шагов точность возрастает

    h = (b - a) / n;

    while (abs(b - a) > eps)
    {
        x = a;

        while ((F3(x) * F3(x + h)) > 0)
        {
            x = x + h;
        }

        a = x;

        b = x + h;

        h = h / n;
    }
    return (a + b) / 2;
}
int main()
{
    int tmp;
    double eps, a, b;

    cout << "Введите значение eps: " << endl;
    cin >> eps;

    cout << "Введите значение начала отрезка a: " << endl;
    cin >> a;

    cout << "Введите значение конца отрезка b: " << endl;
    cin >> b;

    cout << "Введите значение от 1 - 3 какую функцию вы хотите использовать" << endl;
    cin >> tmp;

    sf::Window window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    switch (tmp)
    {
    case 1:
        cout << " X =  " << segment1(eps, a, b) << endl;
        break;
    case 2:
        cout << " X = " << segment2(eps, a, b) << endl;
        break;
    case 3:
        cout << " X = " << segment3(eps, a, b) << endl;
        break;
    }

    return 0;
}
