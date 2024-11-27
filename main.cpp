#include <iostream>
#include <vector>
#include <string>

// Базовый класс "Канцелярские товары"
class Stationery {
protected:
    std::string name;
    double price;

public:
    Stationery(const std::string& name, double price)
        : name(name), price(price) {}

    virtual ~Stationery() {}

    virtual void display() const {
        std::cout << "Название: " << name << ", Цена: " << price << " руб.";
    }

    virtual void extraInfo() const = 0; // Чисто виртуальная функция

    virtual void updatePrice(double newPrice) {
        price = newPrice;
    }

    double getPrice() const {
        return price;
    }
};

// Производный класс "Бумага"
class Paper : public Stationery {
private:
    int pages;

public:
    Paper(const std::string& name, double price, int pages)
        : Stationery(name, price), pages(pages) {}

    void extraInfo() const override {
        std::cout << " (это бумага)\n";
        std::cout << "   Количество страниц: " << pages << "\n";
    }

    void setPages(int newPages) {
        pages = newPages;
    }
};

// Производный класс "Ручка"
class Pen : public Stationery {
private:
    std::string inkColor;

public:
    Pen(const std::string& name, double price, const std::string& inkColor)
        : Stationery(name, price), inkColor(inkColor) {}

    void extraInfo() const override {
        std::cout << " (это ручка)\n";
        std::cout << "   Цвет чернил: " << inkColor << "\n";
    }

    void setInkColor(const std::string& newInkColor) {
        inkColor = newInkColor;
    }
};

// Функция для создания новых объектов
void createNewObject(std::vector<Stationery*>& items) {
    int count;
    std::cout << "Сколько объектов вы хотите создать? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        int choice;
        std::cout << "\nСоздание объекта #" << i + 1 << "\n";
        std::cout << "1. Бумага (Paper)\n";
        std::cout << "2. Ручка (Pen)\n";
        std::cout << "Выберите тип: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            double price;
            int pages;

            std::cout << "Введите название бумаги: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите количество страниц: ";
            std::cin >> pages;

            items.push_back(new Paper(name, price, pages));
            std::cout << "Объект 'Бумага' успешно создан!\n";

        } else if (choice == 2) {
            std::string name;
            double price;
            std::string inkColor;

            std::cout << "Введите название ручки: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите цвет чернил: ";
            std::cin.ignore();
            std::getline(std::cin, inkColor);

            items.push_back(new Pen(name, price, inkColor));
            std::cout << "Объект 'Ручка' успешно создан!\n";

        } else {
            std::cout << "Неверный выбор!\n";
        }
    }
}

// Главная функция программы
int main() {
    std::vector<Stationery*> items;

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Показать все товары\n";
        std::cout << "2. Изменить свойства товара\n";
        std::cout << "3. Вычислить среднюю цену\n";
        std::cout << "4. Создать новые объекты\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "\nСписок товаров:\n";
                for (size_t i = 0; i < items.size(); ++i) {
                    std::cout << i + 1 << ". ";
                    items[i]->display();
                    items[i]->extraInfo();
                }
                break;
            }
            case 2: {
                int index;
                double newPrice;
                std::cout << "Введите номер товара для изменения: ";
                std::cin >> index;
                if (index <= 0 || index > items.size()) {
                    std::cout << "Неверный номер товара!\n";
                    break;
                }
                std::cout << "Введите новую цену: ";
                std::cin >> newPrice;
                items[index - 1]->updatePrice(newPrice);

                // Изменение специфических свойств
                if (auto paper = dynamic_cast<Paper*>(items[index - 1])) {
                    int newPages;
                    std::cout << "Введите новое количество страниц: ";
                    std::cin >> newPages;
                    paper->setPages(newPages);
                } else if (auto pen = dynamic_cast<Pen*>(items[index - 1])) {
                    std::string newColor;
                    std::cout << "Введите новый цвет чернил: ";
                    std::cin.ignore();
                    std::getline(std::cin, newColor);
                    pen->setInkColor(newColor);
                }

                std::cout << "Свойства товара изменены!\n";
                break;
            }
            case 3: {
                if (items.empty()) {
                    std::cout << "Нет товаров для расчёта средней цены!\n";
                    break;
                }
                double total = 0;
                for (const auto& item : items) {
                    total += item->getPrice();
                }
                std::cout << "Средняя цена товаров: " << (total / items.size()) << " руб.\n";
                break;
            }
            case 4: {
                createNewObject(items);
                break;
            }
            case 5: {
                std::cout << "Выход из программы.\n";
                break;
            }
            default:
                std::cout << "Неверный выбор!\n";
        }
    } while (option != 5);

    // Освобождение памяти
    for (auto& item : items) {
        delete item;
    }

    return 0;
}

