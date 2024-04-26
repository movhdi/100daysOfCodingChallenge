#include <iostream>
#include <filesystem>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include <vector>
#include <string_view>


struct book
{
    std::string author;
    std::string title;
    std::string genre;
    double price;
    std::string publish_date;
    std::string description;
};

std::vector<book> deserialize(std::string_view path)
{
    std::vector<book> books;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.data());
    for (auto entry : doc.child("catalog"))
    {
        book item;
        item.author = entry.child_value("author");
        item.title = entry.child_value("title");
        item.genre = entry.child_value("genre");
        item.price = entry.child("price").text().as_double();
        item.publish_date = entry.child_value("publish_date");
        item.description = entry.child_value("description");

        books.emplace_back(item);
    }
    return books;
} 

void printBooks(std::vector<book> books)
{
    for (const auto &item : books)
    {
        std::cout << "Author: " << item.author << std::endl;
        std::cout << "Title: " << item.title << std::endl;
        std::cout << "Genre: " << item.genre << std::endl;
        std::cout << "price: " << item.price << std::endl;
        std::cout << "Publish Date: " << item.publish_date << std::endl;
        std::cout << "Description: " << item.description << std::endl;
    }
}

int main()
{
    printBooks(deserialize("../xmlBookData.xml"));
    return 0;
}