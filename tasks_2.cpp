#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll_num;

        Student(string n){
            name = n;
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

void destroyTest(){
    DynoArray dynamicArray[5];
    
    delete[] dynamicArray;
    cout << "Destroyed dynamicArray" << endl;
}

int main(){
    Student *pointy_student = new Student("John");
    delete pointy_student;

    Student **students = new Student*[5];
    for (int i = 0; i < 5; i++){
        students[i] = new Student("Student " + to_string(i));
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