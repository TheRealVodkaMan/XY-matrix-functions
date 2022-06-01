#include <iostream>
#include <bits\stdc++.h>
#include "Eigen\Eigenvalues"

using namespace std;
using namespace Eigen;

void Porblemo()
{
    cout << "The operation you chose is invalid for the given matrices.\n";
}

int main()
{
    int x_A, x_B, y_A, y_B, oprNum;
    bool progExit = false;

    cout << "Please enter dimensions of Matrix A:\n";
    cin >> y_A >> x_A;

    cout << "Please enter dimensions of Matrix B:\n";
    cin >> y_B >> x_B;

    MatrixXd MatrixA(x_A,y_A), MatrixB(x_B,y_B);

    cout << "Please enter values of Matrix A:\n";
    
    for (int i = 0; i < y_A; i++)
    {
        for (int o = 0; o < x_A; o++)
        {
            cin >> MatrixA(i,o);
        }
    }

    cout << "Please enter values of Matrix B:\n";
    
    for (int i = 0; i < y_B; i++)
    {
        for (int o = 0; o < x_B; o++)
        {
            cin >> MatrixB(i,o);
        }
    }

    while (!progExit)
    {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
        cin >> oprNum;

        if(oprNum == 7)
        {
            cout << "Thank you!\n";
            progExit = true;
        }
        else if(oprNum == 1)
        {
            if ( (MatrixA.cols() == MatrixB.cols()) && (MatrixA.cols() == MatrixB.cols()) )
            {
                cout << MatrixA + MatrixB << endl;
            }
            else
            {
                Porblemo();
            }
        }
        else if(oprNum == 2)
        {
            if ( (MatrixA.cols() == MatrixB.cols()) && (MatrixA.cols() == MatrixB.cols()) )
            {
                cout << MatrixA - MatrixB << endl;
            }
            else
            {
                Porblemo();
            }
        }
        else if(oprNum == 3)
        {   
            if ( MatrixA.cols() == MatrixB.rows() )
            {
                cout << MatrixA * MatrixB << endl;
            }
            else
            {
                Porblemo();
            }
        }
        else if(oprNum == 4)
        {
            if ( (MatrixA.cols() == MatrixB.cols()) && (MatrixA.rows() == MatrixB.rows()) )
            {
                cout << MatrixA * MatrixB.inverse() << endl;
            }
            else
            {
                Porblemo();
            }
        }
        else if(oprNum == 5)
        {
            if (MatrixA.cols() == MatrixA.rows())
            {
                cout << MatrixA.determinant() << endl;
            }
            else
            {
                Porblemo();
            }
        }
        else if(oprNum == 6)
        {
            if (MatrixB.cols() == MatrixB.rows())
            {
                cout << MatrixB.determinant() << endl;
            }
            else
            {
                Porblemo();
            }
        }
    }

    cout << MatrixA << "\t" << MatrixB << endl;
}