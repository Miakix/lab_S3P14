#include "Pen.h"

Pen::Pen(const std::string& name, double price, const std::string& inkColor)
    : Stationery(name, price), inkColor(inkColor) {}

void Pen::setInkColor(const std::string& newColor) {
    inkColor = newColor;
}

void Pen::extraInfo() const {
    std::cout << "Цвет чернил: " << inkColor << "\n";
}

void Pen::display() const {
    Stationery::display();
    std::cout << " (это авторучка)\n";
}

