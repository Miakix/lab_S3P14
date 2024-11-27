#ifndef PEN_H
#define PEN_H

#include "Stationery.h"

class Pen : public Stationery {
    std::string inkColor; // Цвет чернил

public:
    Pen(const std::string& name, double price, const std::string& inkColor);
    void setInkColor(const std::string& newColor); // Изменение цвета чернил
    void extraInfo() const override; // Реализация виртуальной функции

    void display() const override; // Переопределение метода
};

#endif // PEN_H

