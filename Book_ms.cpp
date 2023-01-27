
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class BookShop
{
public:
    void control_panel();
    void add_book();
    void display_book();
    void check_book();
    void update_book();
    void delete_book();
};

void BookShop::control_panel()
{
    system("cls");
    cout << "Welcome to Book Shop" << endl;
    cout << endl;
    cout << "\t 1. Add Book" << endl;
    cout << "\t 2. Display Book" << endl;
    cout << "\t 3. Cheeck Individual Book" << endl;
    cout << "\t 4. Update Book" << endl;
    cout << "\t 5. Delete Book" << endl;
    cout << "\t 6. Exit" << endl;
}

void BookShop::add_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string book_name, author_name, book_id;
    cout << "\t Add Book" << endl;
    cout << "Enter Book ID: ";
    cin >> book_id;
    cout << "Enter Book Name: ";
    cin >> book_name;
    cout << "Enter Auther Name: ";
    cin >> author_name;
    cout << "Enter No. of Copy: ";
    cin >> no_copy;

    file.open("Book.txt", ios::out | ios::app);                                          // ios::out for write and ios::app for append
    file << book_id << " " << book_name << " " << author_name << " " << no_copy << endl; // write data in file
    file.close();                                                                        // close file
}

void BookShop::display_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string book_id, book_name, author_name;
    cout << "\t All Books" << endl;

    // open file in read mode
    file.open("Book.txt", ios::in); // ios::in for read
    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }
    else
    {
        cout << "\t Book ID \t Book Name \t Author Name \t No. of Copy" << endl;
        file >> book_id >> book_name >> author_name >> no_copy;

        while (!file.eof())
        {
            cout << "\t" << book_id << "\t" << book_name << "\t" << author_name << "\t" << no_copy << endl;
            file >> book_id >> book_name >> author_name >> no_copy;
        }
        system("pause");
        file.close();
    }
}

void BookShop::check_book()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    ;
    string book_id, book_name, author_name;

    cout << "\t Check Book" << endl;

    file.open("Book.txt", ios::in); // ios::in for read
    if (!file)
    {
        cout << "File not Found" << endl;
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        file >> book_id >> book_name >> author_name >> no_copy; // read data from file
        while (!file.eof())
        {
            if (book_id == book_id)
            {
                cout << "Book ID: " << book_id << endl;
                cout << "Book Name: " << book_name << endl;
                cout << "Author Name: " << author_name << endl;
                cout << "No. of Copy: " << no_copy << endl;
                count++;
                break;
            }
            file >> book_id >> book_name >> author_name >> no_copy; // read data from file
        }
        if (count == 0)
        {
            cout << "Book not found" << endl;
        }
    }
}

void BookShop::update_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string book_id, book_name, author_name;
    string book_id1, book_name1, author_name1;

    cout << "\t Update Book" << endl;
    file1.open("Book1.txt", ios::app | ios::out); // ios::out for write
    file.open("Book.txt", ios::in);               // ios::in for read

    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        file >> book_id >> book_name >> author_name >> no_copy; // read data from file

        while (!file.eof())
        {
            if (book_id == book_id)
            {
                system("cls");
                cout << "Update Book" << endl;
                cout << "Enter New Book Name: ";
                cin >> book_name;
                cout << "Enter New Author Name: ";
                cin >> author_name;
                cout << "Enter New No. of Copy: ";
                cin >> no_copy;

                file1 << book_id << " " << book_name << " " << author_name << " " << no_copy << endl;
                count++; // count for check book is found or not
            }
            else
            {
                file1 << book_id << " " << book_name << " " << author_name << " " << no_copy << endl;
                file >> book_id >> book_name >> author_name >> no_copy; 
            }
        }
        if (count == 0)
        {
            cout << "Book not found...." << endl;
        }
    }
    cout << endl;
    system("pause");
    file.close();  // close file
    file1.close(); // close file

    remove("Book.txt");              // remove file
    rename("Book1.txt", "Book.txt"); // rename file
}

void BookShop::delete_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string book_id, book_name, author_name;
    

    cout << "\t Delete Book" << endl;
    file1.open("Book1.txt", ios::app | ios::out); // ios::out for write
    file.open("Book.txt", ios::in);               // ios::in for read

    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        file >> book_id >> book_name >> author_name >> no_copy; // read data from file

        while (!file.eof())
        {
            if (book_id == book_id)
            {
                system("cls");
                cout << "Deleted Book Successfully" << endl;

                count++; // count for check book is found or not
            }
            else
            {
                file1 << book_id << " " << book_name << " " << author_name << " " << no_copy << endl; // write data to file
            }
        }
        if (count == 0)
        {
            cout << "Book not found...." << endl;
        }
    }
    system("pause");
    file.close();                    // close file
    file1.close();                   // close file
    remove("Book.txt");              // remove file
    rename("Book1.txt", "Book.txt"); // rename file
}

void BookShopRecord()
{
    int choice;
    char x;
    BookShop book;

    while (1)
    {
        book.control_panel();
        cout << "\t Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                book.add_book();
                cout << "Do you want to add more book? (y/n): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            book.display_book();
            break;
        case 3:
            book.check_book();
            break;
        case 4:
            book.update_book();
            break;
        case 5:
            book.delete_book();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

int main()
{
    BookShopRecord();
    return 0;
}