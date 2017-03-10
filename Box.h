#pragma once
#include <ostream>
#include <iostream>

/*
* Class Box represents a simple 3-dimentional figure which has
* length (l), breadth (b), height (h).
* Implements a main functionality appropriate to such figure.
* [Solution for https://www.hackerrank.com/challenges/box-it]
*/
class Box
{
    int m_length;
    int m_breadth;
    int m_height;
public:
    Box() : m_length(0), m_breadth(0), m_height(0) {}
    explicit Box(int l, int b, int h) : m_length(l), m_breadth(b), m_height(h) {}
    Box(const Box& box) : m_length(box.getLength()), m_breadth(box.getBreadth()), m_height(box.getHeight()) {} // copy constructor

                                                                                                               // TODO: consider replace with if..else ?
    bool operator<(Box box) const { return m_length == box.getLength() ? (m_breadth == box.getBreadth() ? m_length < box.getLength() : m_breadth < box.getBreadth()) : m_length < box.getLength(); }
    Box& operator=(const Box& box)  // copy assignment
    {
        if (this != &box)
        {
            m_length = box.getLength();
            m_breadth = box.getBreadth();
            m_height = box.getHeight();
        }
        return *this;
    }

    // use as: Box << std::cout (unconvenient signature, below implemented analog)
    std::ostream& operator<<(std::ostream& out) const { return out << m_length << " " << m_breadth << " " << m_height; }

    int getLength() const { return m_length; }
    int getBreadth() const { return m_breadth; }
    int getHeight() const { return m_height; }

    /*
    * the problem with this method was as follows:
    * if 'm_length', 'm_breadth' and 'm_height' hold a big values and
    * as multiplication operator has associativity from left to right, so if we will do: long long result = m_length * m_breadth * m_height;
    * we can get out of range exception if the first part [m_length * m_breadth] will be type of 'int' and has a quite big value
    * but by multiple on m_height will has a value greater than max value allowed for the 'int'
    */
    long long CalculateVolume() const
    {
        long long result = m_length * m_breadth;
        std::cout << "The type is: " << typeid(result).name() << " Value is: " << result << std::endl;
        result *= m_height;
        std::cout << "The type is: " << typeid(result).name() << " Value is: " << result << std::endl;
        return static_cast<long long>(m_length * m_breadth * m_height);
    }
};

// to allow use as: std::cout << Box;
inline std::ostream& operator<<(std::ostream& out, const Box& box) { return out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight(); }