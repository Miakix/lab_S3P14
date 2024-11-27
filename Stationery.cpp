#include "Stationery.h"

Stationery::Stationery(const std::string& name, double price) : name(name), price(price) {}

void Stationery::display() const {
    std::cout << "Название: " << name << ", Цена: " << price << " руб.\n";
}

void Stationery::updatePrice(double newPrice) {
    price = newPrice;
}

