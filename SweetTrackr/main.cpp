// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Order.h"

// Displays the main menu options
void showMenu() {
    std::cout << "\nSweetTrackr Menu\n";
    std::cout << "1. Add Order\n";
    std::cout << "2. View Saved Orders\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

// Handles adding a new order and saving it to the file
void addOrder() {
    std::string name, date, item;
    int quantity;

    std::cin.ignore(); // clear input buffer
    std::cout << "Customer Name: ";
    std::getline(std::cin, name);

    std::cout << "Date (MM/DD/YYYY): ";
    std::getline(std::cin, date);

    std::cout << "Item: ";
    std::getline(std::cin, item);

    std::cout << "Quantity: ";
    std::cin >> quantity;

    Order newOrder(name, date, item, quantity);

    std::ofstream outFile("orders.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << name << "|" << date << "|" << item << "|" << quantity << "\n";
        outFile.close();
        std::cout << "Order added and saved successfully.\n";
    } else {
        std::cout << "Error: Could not save the order.\n";
    }
}

// Displays all saved orders from the file
void viewOrders() {
    std::ifstream inFile("orders.txt");
    if (!inFile) {
        std::cout << "No saved orders found.\n";
        return;
    }

    std::string line;
    int orderNum = 1;

    std::cout << "\nSaved Orders:\n";
    while (std::getline(inFile, line)) {
        std::string name, date, item;
        int quantity;
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);

        name = line.substr(0, pos1);
        date = line.substr(pos1 + 1, pos2 - pos1 - 1);
        item = line.substr(pos2 + 1, pos3 - pos2 - 1);
        quantity = std::stoi(line.substr(pos3 + 1));

        Order loadedOrder(name, date, item, quantity);
        std::cout << orderNum++ << ". " << loadedOrder.toString() << "\n";
    }

    inFile.close();
}

int main() {
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                viewOrders();
                break;
            case 3:
                std::cout << "Exiting SweetTrackr.\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
