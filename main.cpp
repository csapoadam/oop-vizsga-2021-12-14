// OOP-vizsga-2021-12-14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>

#include "shapes.h"

// Keszitse el a Point2D, Shape, Rectangle es Circle osztalyokat ugy, hogy
// az alabbi kod forduljon!
// Fontos, hogy:
// Shape legyen absztrakt osztaly


// Az elvart kimenet az alabbi (a tavolsagok, teruletek nyilvan nem kell, hogy az utolso ezrelekig azonosak legyenek):
// 2 - es jegyert :
// myPoint1 es myPoint2 kozotti tavolsag : 2.23607
// s1 terulete : 8
// s2 terulete : 12.56
// 3 - as jegyert : egyszeruen le kell hogy forduljon amikor SZINT_3 makro 1 - re van allitva
// 4 - es jegyert :
// Teglalap kisebb teruletu, mint Kor
// 5 - os jegyert :
// A Teglalap alakzatnak 4 sarka van.
// A Kor alakzatnak viszont 0 sarka van.

// Tovabbi megjegyzesek:
// A kor terulete: r negyzet pi. pi erteke lehet siman 3.14, beegetve.
// 2 pont, a es b tavolsaga: sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))
// sqrt es pow a math.h konyvtarban megtalalhatoak, azaz: #include <math.h>

#define SZINT_2 1
#define SZINT_3 0
#define SZINT_4 0
#define SZINT_5 0

int main()
{
#if SZINT_2
    static_assert(std::is_abstract<Shape>(), "Shape-nek absztrakt osztalynak kell lennie!");

    Point2D myPoint1(3, 4);
    Point2D myPoint2(4, 6);
    
    Shape* s1 = new Rectangle(Point2D(10,1), Point2D(10,-3), Point2D(12,-3), Point2D(12,1));
    Shape* s2 = new Circle(Point2D(6, 9), 2);

    std::cout << "2-es jegyert:" << std::endl;
    std::cout << std::string(" ", 2) << "myPoint1 es myPoint2 kozotti tavolsag: " << myPoint1.distance(myPoint2) << std::endl;
    std::cout << std::string(" ", 2) << "s1 terulete: " << s1->area() << std::endl;
    std::cout << std::string(" ", 2) << "s2 terulete: " << s2->area() << std::endl;

#if SZINT_3

    std::cout << "3-as jegyert: egyszeruen le kell hogy forduljon amikor SZINT_3 makro 1-re van allitva" << std::endl;
    static_assert(!std::is_copy_constructible<Rectangle>(), "Rectangle osztaly masolasat le kell tiltani!");
    static_assert(!std::is_copy_constructible<Circle>(), "Circle osztaly masolasat le kell tiltani!");
    static_assert(!std::is_copy_assignable<Rectangle>(), "Rectangle osztaly copy assign operatorat le kell tiltani!");
    static_assert(!std::is_copy_assignable<Circle>(), "Circle osztaly copy assign operatorat le kell tiltani!");

#if SZINT_4
    std::cout << "4-es jegyert:" << std::endl;
    if (s1->isLargerThan(s2)) {
        std::cout << std::string(" ", 2) << s1->printType() << " nagyobb teruletu, mint " << s2->printType() << std::endl;
    }
    else {
        std::cout << std::string(" ", 2) << s1->printType() << " kisebb teruletu, mint " << s2->printType() << std::endl;
    }

#if SZINT_5
    std::cout << "5-os jegyert:" << std::endl;
    std::cout << std::string(" ", 2) << "A " << s1->printType() << " alakzatnak " << getSarkokSzama(s1) << " sarka van." << std::endl;
    std::cout << std::string(" ", 2) << "A " << s2->printType() << " alakzatnak viszont " << getSarkokSzama(s2) << " sarka van." << std::endl;

#endif

#endif

#endif
    delete s1;
    delete s2;
#endif
}
