#include "Paper.h"

Paper::Paper(const std::string& name, double price, int pages) : Stationery(name, price), pages(pages) {}

void Paper::setPages(int newPages) {
    pages = newPages;
}

void Paper::extraInfo() const {
    std::cout << "Количество страниц: " << pages << "\n";
}

void Paper::display() const {
    Stationery::display();
    std::cout << " (это бумага)\n";
}

