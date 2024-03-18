#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//1.1
void FillMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = rand() % 9 + 1;
        }
    }
}

//1.2
void PrintMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//1.4
void SortRows(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        sort(matrix[i], matrix[i] + size);
    }
}

//1.3
void FindMinMaxOnDiagonal(int** matrix, int size)
{
    int maxElement = matrix[0][0];
    int minElement = matrix[0][0];

    for (int i = 1; i < size; ++i)
    {
        if (matrix[i][i] > maxElement)
        {
            maxElement = matrix[i][i];
        }
        if (matrix[i][i] < minElement)
        {
            minElement = matrix[i][i];
        }
    }

    cout << "Min element on diagonal before sorting: " << minElement << endl;
    cout << "Max element on diagonal before sorting: " << maxElement << endl; 
}

//2
int nsd(int a, int b) {
    if (b == 0) 
    {
        return a;
    }
    else 
    {
        return nsd(b, a % b);
    }
}

int main()
{
    //1
    const int size = 3;

    srand(time(nullptr));

    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        intMatrix[i] = new int[size];
    }

    FillMatrix(intMatrix, size);

    cout << "Matrix before sorting:" << endl;
    PrintMatrix(intMatrix, size);

    FindMinMaxOnDiagonal(intMatrix, size);

    SortRows(intMatrix, size);

    cout << "Matrix after sorting:" << endl;
    PrintMatrix(intMatrix, size);

    //2
    int num1, num2;
    cout << "Enter first and second number: ";
    cin >> num1 >> num2;
    cout << nsd(num1, num2) << endl;
}