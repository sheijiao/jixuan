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
        std::cout << "书籍添加成功！\n";
    }

    void displayBooks() {
        std::cout << "图书馆藏书：\n";
        for (const auto& book : books) {
            std::cout << "书名: " << book.title << ", 作者: " << book.author
                << ", 出版年份: " << book.year << ", ISBN: " << book.isbn << "\n";
        }
    }

    // 新增查询功能
    void findBookByTitle(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), &title{
            return book.title == title;
            });
        if (it != books.end()) {
            std::cout << "找到书籍：\n";
            std::cout << "书名: " << it->title << ", 作者: " << it->author
                << ", 出版年份: " << it->year << ", ISBN: " << it->isbn << "\n";
        }
        else {
            std::cout << "未找到书名为 '" << title << "' 的书籍。\n";
        }
    }

    void findBookByISBN(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), &isbn{
            return book.isbn == isbn;
            });
        if (it != books.end()) {
            std::cout << "找到书籍：\n";
            std::cout << "书名: " << it->title << ", 作者: " << it->author
                << ", 出版年份: " << it->year << ", ISBN: " << it->isbn << "\n";
        }
        else {
            std::cout << "未找到ISBN为 '" << isbn << "' 的书籍。\n";
        }
    }
};

int main() {
    Library library;
    std::string title, author, isbn;
    int year, choice;

    do {
        std::cout << "1. 添加书籍\n";
        std::cout << "2. 显示所有书籍\n";
        std::cout << "3. 查询书籍\n";
        std::cout << "4. 退出\n";
        std::cout << "请输入您的选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin.ignore(); // 清除缓冲区
            std::cout << "输入书名: ";
            std::getline(std::cin, title);
            std::cout << "输入作者: ";
            std::getline(std::cin, author);
            std::cout << "输入出版年份: ";
            std::cin >> year;
            std::cout << "输入ISBN: ";
            std::cin >> isbn;
            library.addBook(Book(title, author, year, isbn));
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            std::cin.ignore(); // 清除缓冲区
            std::cout << "输入书名或ISBN来查询书籍: ";
            std::getline(std::cin, title); // 这里使用title变量来接收输入，可以是书名或ISBN
            library.findBookByTitle(title);
            library.findBookByISBN(title);
            break;
        case 4:
            std::cout << "感谢使用图书馆管理系统。\n";
            break;
        default:
            std::cout << "无效选择，请重新输入。\n";
        }
    } while (choice != 4);

    return 0;
}
