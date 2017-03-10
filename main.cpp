#include <iostream>
#include "Box.h"

void checkBox()
{
    int n;
    std::cin >> n;
    Box temp;
    for (auto i = 0; i < n; ++i)
    {
        int type;
        std::cin >> type;

        if (type == 1)
            std::cout << temp << std::endl;
        if (type == 2)
        {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            std::cout << temp << std::endl;
        }
        if (type == 3)
        {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
                std::cout << "Lesser\n";
            else
                std::cout << "Greater\n";
        }
        if (type == 4)
            std::cout << temp.CalculateVolume() << std::endl;
        if (type == 5)
        {
            auto NewBox(temp);
            std::cout << NewBox << std::endl;
        }
    }
}

int main()
{
    //Box box{ 3, 4, 5 };
    int answer;
    //std::cout << box << std::endl;
    //box << std::cout;

    checkBox();
    std::cin >> answer;
}