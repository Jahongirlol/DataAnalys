#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll_num;

        Student(string n){
            name = n;
            roll_num = 0;
            cout << "Constructor called for " << name << endl;
        }
        ~Student(){
            cout << "Destructor called for " << name << endl;
        }
};

class DynoArray{
    public:
        int *arr = new int[3];
        
        DynoArray(){
            for (int i = 0; i < 3; i++){
                arr[i] = i+1;
            }
            cout << "Constructor called for DynoArray" << endl;
        }
        ~DynoArray(){
            delete[] arr;
            cout << "Destructor called for DynoArray" << endl;
        }
};

void destroyTest(){ // this is the destroyFun task.6
    DynoArray *dynamicArray = new DynoArray[5];
    delete[] dynamicArray;

    cout << "Destroyed dynamicArray" << endl;
}

struct Book{
    public:
        string title;
        string author;
        int year;
};

void printBook(Book b){
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Year: " << b.year << endl;
}

void addBook(Book *&shelfy, Book b, int &storedCount){
    if (storedCount < 2){
        shelfy[storedCount] = b;
        storedCount++;
    } 
    else {
        cout << "Shelf is full!" << endl;

        int newsize = storedCount * 2;
        Book *new_shelf = new Book[newsize];

        for (int i = 0; i < storedCount; i++){
            new_shelf[i] = shelfy[i];
        }

        new_shelf[storedCount] = b;

        delete[] shelfy;
        shelfy = new_shelf;

        storedCount++;

        cout << "Shelf size increased to " << newsize << endl;
    }
}


struct Book_Task9{
    private:
        string name_book;
        string name_author;
        string name_publisher;
        int assignedID;
        int ISSN, Edition;
        bool isAvailable;
    public:
        Book_Task9(): name_book(""),name_author(""),name_publisher(""),assignedID(0),ISSN(0),Edition(0),isAvailable(false){}

        Book_Task9(string name_book, string name_author, string name_publisher, int assignedID, int ISSN, int Edition, bool isAvailable){
            this->name_book = name_book;
            this->name_author = name_author;
            this->name_publisher = name_publisher;
            this->assignedID = assignedID;
            this->ISSN = ISSN;
            this->Edition = Edition;
            this->isAvailable = isAvailable;
        }

        void inputDetails(string name_book, string name_author, string name_publisher, int assignedID, int ISSN, int Edition, bool isAvailable){
            this->name_book = name_book;
            this->name_author = name_author;
            this->name_publisher = name_publisher;
            this->assignedID = assignedID;
            this->ISSN = ISSN;
            this->Edition = Edition;
            this->isAvailable = isAvailable;
        }

        void displayDetails(string name_bookFun){
            if (name_bookFun != name_book){
                cout << "Book not found!" << endl;
                return;
            }
            cout << "Book Name: " << name_book << endl;
            cout << "Author: " << name_author << endl;
            cout << "Publisher: " << name_publisher << endl;
            cout << "Assigned ID: " << assignedID << endl;
            cout << "ISSN: " << ISSN << endl;
            cout << "Edition: " << Edition << endl;
            cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        }

        void displayDetails(){
            cout << "Book Name: " << name_book << endl;
            cout << "Author: " << name_author << endl;
            cout << "Publisher: " << name_publisher << endl;
            cout << "Assigned ID: " << assignedID << endl;
            cout << "ISSN: " << ISSN << endl;
            cout << "Edition: " << Edition << endl;
            cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        }

        void displayDetails(int ISSNFun){
            if (ISSNFun != ISSN){
                cout << "Book not found!" << endl;
                return;
            }
            cout << "Book Name: " << name_book << endl;
            cout << "Author: " << name_author << endl;
            cout << "Publisher: " << name_publisher << endl;
            cout << "Assigned ID: " << assignedID << endl;
            cout << "ISSN: " << ISSN << endl;
            cout << "Edition: " << Edition << endl;
            cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        }

        bool availabilityStatus(){
            return isAvailable;
        }

        string getBookName(){
            return name_book;
        }


        void issueBook(){
            if (isAvailable){
                isAvailable = false;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Book is not available for issue!" << endl;
            }
        }
};

class Library{
    private:
        string librarian;
        int maxBookNums, currentBookNums;
        Book_Task9 *books;
    public:
        Library(string librarian){
            this->librarian = librarian;
            maxBookNums = 100;
            currentBookNums = 0;
            books = new Book_Task9[maxBookNums];
        }
        Library(string librarian, int maxBookNums){
            this->librarian = librarian;
            this->maxBookNums = maxBookNums;
            currentBookNums = 0;
            books = new Book_Task9[maxBookNums];
        }
        void DispBookDetails(){
            for (int i = 0; i < currentBookNums; i++){
                books[i].displayDetails();
            }
        }
        void addBook(Book_Task9 book){
            if (currentBookNums < maxBookNums){
                books[currentBookNums] = book;
                currentBookNums++;
            } else {
                cout << "Library is full!" << endl;
            }
        }
        void searchBook(string name_book){
            for (int i = 0; i < currentBookNums; i++){
                if (books[i].getBookName() == name_book){
                    books[i].displayDetails();
                    return;
                }
            }
            cout << "Book not found!" << endl;
        }
        void assignBook(string name_book){
            for (int i = 0; i < currentBookNums; i++){
                if (books[i].availabilityStatus() && books[i].getBookName() == name_book){
                    books[i].issueBook();
                    return;
                }
            }
            cout << "Book not found or not available!" << endl;
        }
        ~Library(){
            delete[] books;
        }
};


int main(){
    Book b1,b2,b3;
    b1.title = "b1";
    b1.author = "agartha";
    b1.year = 1999;

    b2.title = "b2";
    b2.author = "agartha";
    b2.year = 1999;

    b3.title = "b3";
    b3.author = "agartha";
    b3.year = 1999;

    printBook(b1);
    printBook(b2);
    printBook(b3);

    int storedCount = 0;
    Book *shelfy = new Book[2];
    addBook(shelfy, b1, storedCount);
    addBook(shelfy, b2, storedCount);
    addBook(shelfy, b3, storedCount);
    Book b4 = {"b4", "agartha", 1999};
    addBook(shelfy, b4, storedCount);
    cout << "Total number of book copies: " << storedCount << endl;
    delete[] shelfy;

    

    Student *pointy_student = new Student("John");
    delete pointy_student;

    Student **students = new Student*[5];
    for (int i = 0; i < 5; i++){
        students[i] = new Student("Student " + to_string(i));
    }
    for (int i = 0; i < 5; i++){
        delete students[i];
    }
    delete[] students;


    destroyTest();

    int *pointy_var = new int;
    *pointy_var = 67;
    cout << *pointy_var << endl;
    delete pointy_var;

    char *pointy_char = new char;
    *pointy_char = 'A';
    cout << *pointy_char << endl;
    delete pointy_char;


    int size = 3;
    int *pointy_array = new int[size];
    int loop = 0;
    
    while (true){
        int num;
        cout << "Enter a number (0 to exit): ";
        cin >> num;
        if (num == 0){
            cout << "You entered: ";
            for (int i = 0; i < loop; i++){
               cout << pointy_array[i] << " ";
            }
            cout << endl;
            delete[] pointy_array;
            break;
        } else{
            if (loop < size){
                pointy_array[loop] = num;
            } else {
                cout << "Array is full!" << endl;
                int newsize = size * 2;
                int *new_array = new int[newsize];
                for (int i = 0; i < size; i++){
                    new_array[i] = pointy_array[i];
                }
                new_array[loop] = num;
                delete[] pointy_array;
                pointy_array = new_array;
                size = newsize;
                cout << "Array size increased to " << size << " from " << size/2 << endl;
            }
        }
        loop++;
    }


    return 0;
}
