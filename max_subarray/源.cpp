#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;
    int year;
    std::string isbn;

    Book(const std::string& title, const std::string& author, int year, const std::string& isbn)
        : title(title), author(author), year(year), isbn(isbn) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "�鼮��ӳɹ���\n";
    }

    void displayBooks() {
        std::cout << "ͼ��ݲ��飺\n";
        for (const auto& book : books) {
            std::cout << "����: " << book.title << ", ����: " << book.author
                << ", �������: " << book.year << ", ISBN: " << book.isbn << "\n";
        }
    }

    // ������ѯ����
    void findBookByTitle(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), &title{
            return book.title == title;
            });
        if (it != books.end()) {
            std::cout << "�ҵ��鼮��\n";
            std::cout << "����: " << it->title << ", ����: " << it->author
                << ", �������: " << it->year << ", ISBN: " << it->isbn << "\n";
        }
        else {
            std::cout << "δ�ҵ�����Ϊ '" << title << "' ���鼮��\n";
        }
    }

    void findBookByISBN(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), &isbn{
            return book.isbn == isbn;
            });
        if (it != books.end()) {
            std::cout << "�ҵ��鼮��\n";
            std::cout << "����: " << it->title << ", ����: " << it->author
                << ", �������: " << it->year << ", ISBN: " << it->isbn << "\n";
        }
        else {
            std::cout << "δ�ҵ�ISBNΪ '" << isbn << "' ���鼮��\n";
        }
    }
};

int main() {
    Library library;
    std::string title, author, isbn;
    int year, choice;

    do {
        std::cout << "1. ����鼮\n";
        std::cout << "2. ��ʾ�����鼮\n";
        std::cout << "3. ��ѯ�鼮\n";
        std::cout << "4. �˳�\n";
        std::cout << "����������ѡ��: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin.ignore(); // ���������
            std::cout << "��������: ";
            std::getline(std::cin, title);
            std::cout << "��������: ";
            std::getline(std::cin, author);
            std::cout << "����������: ";
            std::cin >> year;
            std::cout << "����ISBN: ";
            std::cin >> isbn;
            library.addBook(Book(title, author, year, isbn));
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            std::cin.ignore(); // ���������
            std::cout << "����������ISBN����ѯ�鼮: ";
            std::getline(std::cin, title); // ����ʹ��title�������������룬������������ISBN
            library.findBookByTitle(title);
            library.findBookByISBN(title);
            break;
        case 4:
            std::cout << "��лʹ��ͼ��ݹ���ϵͳ��\n";
            break;
        default:
            std::cout << "��Чѡ�����������롣\n";
        }
    } while (choice != 4);

    return 0;
}
