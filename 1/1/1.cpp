#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <cmath>
using namespace std;

//1
int power(int num, int indicator) 
{
    int result = 1;
    for (int i = 0; i < indicator; ++i) 
    {
        result *= num;
    }
    return (indicator < 0) ? 1 / result : result;
}

//2
int sumInRange(int num1, int num2) {
    int sum = 0;

    int start = (num1 < num2) ? num1 : num2;
    int end = (num1 > num2) ? num1 : num2;

    for (int i = start; i <= end; ++i) {
        sum += i;
    }

    return sum;
}

//3
bool isPerfect(int num) 
{
    int sum = 0;
    for (int i = 1; i < num; ++i) 
    {
        if (num % i == 0) 
        {
            sum += i;
        }
    }
    return sum == num;
}

void findPerfectNumbers(int start, int end) 
{
    cout << "Perfect numbers: ";
    bool found = false;
    for (int num = start; num <= end; ++num) 
    {
        if (isPerfect(num)) 
        {
            cout << num << " ";
            found = true;
        }
    }
    cout << (found ? "" : "None") << endl;
}

//4
#define SPADE L"\u2660"
#define CLUB L"\u2663"
#define HEART L"\u2665"
#define DIAMOND L"\u2666"

enum SUIT { spade = 1, club, heart, diamond };

using namespace std;

void printSuit(int suitToSelect) {
    _setmode(_fileno(stdout), _O_U16TEXT);
    switch (suitToSelect) {
    case spade:
        wcout << SPADE;
        break;
    case club:
        wcout << CLUB;
        break;
    case heart:
        wcout << HEART;
        break;
    case diamond:
        wcout << DIAMOND;
        break;
    }
    _setmode(_fileno(stdout), _O_TEXT);
}

//5
bool isLuckyNumber(int number) {

    if (number < 100000 || number > 999999)
        return false;

    int digit1 = number / 100000;
    int digit2 = (number / 10000) % 10;
    int digit3 = (number / 1000) % 10;
    int digit4 = (number / 100) % 10;
    int digit5 = (number / 10) % 10;
    int digit6 = number % 10;

    return (digit1 + digit2 + digit3 == digit4 + digit5 + digit6);
}

//6
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1;  
}

//8
int binaryToDecimal(const char binary[])
{
    int decimal = 0;
    int power = 0;

    int length = 0;
    while (binary[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (1 << power); 
        }
        power++;
    }

    return decimal;
}

int main()
{
    //1
    int base;
    int indicator;

    cout << "Enter the number: ";
    cin >> base;

    cout << "Enter the indicator: ";
    cin >> indicator;

    double result = power(base, indicator);
    cout << result << endl;

    //2
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    int result1 = sumInRange(num1, num2);
    cout << result1 << endl;

    //3
    int start, end;

    cout << "Enter the start of the interval: ";
    cin >> start;

    cout << "Enter the end of the interval: ";
    cin >> end;

    findPerfectNumbers(start, end);

    //4
    printSuit(spade);
    printSuit(heart);
    printSuit(club);
    printSuit(diamond);
    cout << "\n";

    //5
    int number;
    cout << "Enter a six-digit number: ";
    cin >> number;

    if (isLuckyNumber(number)) {
        cout << number << " is a lucky number." << endl;
    }
    else {
        cout << number << " is not a lucky number." << endl;
    }

    //6
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int result2 = linearSearch(arr, size, key);

    if (result2 != -1) {
        cout << "Key found at index: " << result2 << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    delete[] arr;

    //8
    char binaryNumber[10000]; 
    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Decimal equivalent: " << decimalNumber << endl;

    return 0;
}

