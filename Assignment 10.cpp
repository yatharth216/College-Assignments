#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string isbn;
    std::string title;

    Book(std::string i, std::string t) : isbn(i), title(t) {}

    void display() {
        std::cout << "ISBN: " << isbn << ", Title: " << title << std::endl;
    }
};

int main() {
    // List of books in the library
    std::vector<Book> library = {
        Book("1234567890", "The Great Gatsby"),
        Book("0987654321", "To Kill a Mockingbird"),
        Book("1111111111", "The Catcher in the Rye")
    };

    // Input ISBN from the user
    std::string inputIsbn;
    std::cout << "Enter the ISBN of the book: ";
    std::cin >> inputIsbn;

    // Search for the book in the library
    bool found = false;
    for (Book& book : library) {
        if (book.isbn == inputIsbn) {
            // Book found
            found = true;
            book.display();
            break;
        }
    }

    if (!found) {
        // Book not found in the library
        std::cout << "The book is not available in the library." << std::endl;
    }

    return 0;
}