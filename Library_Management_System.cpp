#include <iostream>
#include <fstream>
using namespace std;

class Book
{
public:
    int id;
    string name;
    bool issued;

    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Book Name: ";
        cin >> name;
        issued = false;
    }

    void display()
    {
        cout << id << "\t" << name << "\t" << (issued ? "Issued" : "Available") << endl;
    }
};

int main()
{
    Book b;
    fstream file;
    int choice;

    do
    {
        cout << "\n1. Add Book\n2. View Books\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            file.open("library.txt", ios::out | ios::app);
            b.input();
            file.write((char *)&b, sizeof(b));
            file.close();
        }

        else if (choice == 2)
        {
            file.open("library.txt", ios::in);
            cout << "ID\tName\tStatus\n";
            while (file.read((char *)&b, sizeof(b)))
            {
                b.display();
            }
            file.close();
        }

    } while (choice != 3);

    return 0;
}
