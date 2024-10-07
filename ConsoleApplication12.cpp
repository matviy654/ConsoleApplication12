#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;

    Complex add(const Complex& other) const {
        return { real + other.real, imag + other.imag };
    }

    Complex subtract(const Complex& other) const {
        return { real - other.real, imag - other.imag };
    }

    Complex multiply(const Complex& other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    Complex divide(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return {
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        };
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex a = { 3, 4 };
    Complex b = { 1, 2 };

    cout << "Додавання: ";
    Complex sum = a.add(b);
    sum.display();

    cout << "Віднімання: ";
    Complex diff = a.subtract(b);
    diff.display();

    cout << "Множення: ";
    Complex product = a.multiply(b);
    product.display();

    cout << "Ділення: ";
    Complex quotient = a.divide(b);
    quotient.display();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;

    void setValues(double len, double clear, double engVol, int engPower, double wheelDia, string col, string transType) {
        length = len;
        clearance = clear;
        engineVolume = engVol;
        enginePower = engPower;
        wheelDiameter = wheelDia;
        color = col;
        transmissionType = transType;
    }

    void display() const {
        cout << "Довжина: " << length << " м" << endl;
        cout << "Кліренс: " << clearance << " м" << endl;
        cout << "Об'єм двигуна: " << engineVolume << " л" << endl;
        cout << "Потужність двигуна: " << enginePower << " к.с." << endl;
        cout << "Діаметр коліс: " << wheelDiameter << " дюймів" << endl;
        cout << "Колір: " << color << endl;
        cout << "Тип коробки передач: " << transmissionType << endl;
    }

    bool searchByColor(const string& searchColor) const {
        return color == searchColor;
    }

    bool searchByTransmissionType(const string& searchTransmissionType) const {
        return transmissionType == searchTransmissionType;
    }
};

int main() {
    Car car;
    car.setValues(4.5, 0.2, 2.0, 150, 18, "Червоний", "Автомат");

    cout << "Інформація про автомобіль: " << endl;
    car.display();

    string colorToSearch = "Червоний";
    if (car.searchByColor(colorToSearch)) {
        cout << "Знайдено автомобіль з кольором: " << colorToSearch << endl;
    }
    else {
        cout << "Автомобіль з таким кольором не знайдено." << endl;
    }

    string transmissionToSearch = "Автомат";
    if (car.searchByTransmissionType(transmissionToSearch)) {
        cout << "Знайдено автомобіль з коробкою передач: " << transmissionToSearch << endl;
    }
    else {
        cout << "Автомобіль з такою коробкою передач не знайдено." << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;

    void editBook(const string& newTitle, const string& newAuthor, const string& newPublisher, const string& newGenre) {
        title = newTitle;
        author = newAuthor;
        publisher = newPublisher;
        genre = newGenre;
    }

    void printBook() const {
        cout << "Назва: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Видавництво: " << publisher << endl;
        cout << "Жанр: " << genre << endl;
        cout << "----------------------" << endl;
    }
};

void printAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].printBook();
    }
}

void searchByAuthor(Book books[], int size, const string& author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            books[i].printBook();
            found = true;
        }
    }
    if (!found) {
        cout << "Книгу автора " << author << " не знайдено." << endl;
    }
}

void searchByTitle(Book books[], int size, const string& title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            books[i].printBook();
            found = true;
        }
    }
    if (!found) {
        cout << "Книгу з назвою " << title << " не знайдено." << endl;
    }
}

bool compareByTitle(const Book& a, const Book& b) {
    return a.title < b.title;
}

bool compareByAuthor(const Book& a, const Book& b) {
    return a.author < b.author;
}

bool compareByPublisher(const Book& a, const Book& b) {
    return a.publisher < b.publisher;
}

int main() {
    
    Book books[10] = {
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Fiction"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Fiction"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
        {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Bloomsbury", "Fantasy"},
        {"The Lord of the Rings", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"}
    };

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Редагувати книгу\n";
        cout << "2. Друк усіх книг\n";
        cout << "3. Пошук книги за автором\n";
        cout << "4. Пошук книги за назвою\n";
        cout << "5. Сортування масиву за назвою\n";
        cout << "6. Сортування масиву за автором\n";
        cout << "7. Сортування масиву за видавництвом\n";
        cout << "0. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            int index;
            cout << "Введіть індекс книги (0-9) для редагування: ";
            cin >> index;
            cin.ignore(); 
            if (index >= 0 && index < 10) {
                string newTitle, newAuthor, newPublisher, newGenre;
                cout << "Введіть нову назву: ";
                getline(cin, newTitle);
                cout << "Введіть нового автора: ";
                getline(cin, newAuthor);
                cout << "Введіть нове видавництво: ";
                getline(cin, newPublisher);
                cout << "Введіть новий жанр: ";
                getline(cin, newGenre);
                books[index].editBook(newTitle, newAuthor, newPublisher, newGenre);
                cout << "Книгу відредаговано.\n";
            }
            else {
                cout << "Неправильний індекс!\n";
            }
            break;
        }
        case 2:
            printAllBooks(books, 10);
            break;
        case 3: {
            string author;
            cout << "Введіть автора для пошуку: ";
            getline(cin, author);
            searchByAuthor(books, 10, author);
            break;
        }
        case 4: {
            string title;
            cout << "Введіть назву книги для пошуку: ";
            getline(cin, title);
            searchByTitle(books, 10
