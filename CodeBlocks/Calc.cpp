/*
Project Name: Basic Calculator
Date Started: February 3rd, 2026

Updates: (What does not not, what needs to be fixed)

*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    char op = ' ';

    cout << "*** Calculator ***" << endl;
    cout << "Please enter the first number: ";
    cin  >> num1;
    cout << "\nPlease enter the operation: ";
    cin  >> op;
    cout << "\nPlease enter the second number: ";
    cin  >> num2;
    cout << "\nAnswer: ";

    switch(op) {
    case '*':
    case 'x':
        cout << num1*num2 << endl;
        break;
    case '/':
        cout << num1/num2 << endl;
        break;
    case '^':
        cout << pow(num1, num2) << endl;
        break;
    case '-':
        cout << num1-num2 << endl;
        break;
    case '+':
        cout << num1+num2 << endl;
        break;
    case '%':
        cout << num1%num2 << endl;
        break;
    default:
        cout << "Invalid operation attempted" << endl;
    }

    return 0;
}
