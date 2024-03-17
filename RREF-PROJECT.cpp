#include <iostream>
#include <cstdlib>
#include <iomanip>
#include<conio.h>
using namespace std;
float tem;
const int ROW = 3;
const int COL = 4;
void drawMatrix(float Matrix[][COL]);
void RREF(float Matrix[][COL]);
void REF(float Matrix[][COL]);
int main()
{
    float Matrix[ROW][COL];
    /*
    { {5, -6, -7,   7},
      {3, -2,  5, -17},
      {2,  4, -3,  29},
    };
    */
    cout << "Please Enter 3*4 matrix :)" << endl;
    cout << "Like This:" << endl;
    cout << " 5 -6 -7   7\n"
        " 3 -2  5 -17\n"
        " 2  4 -3  29" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cin >> Matrix[i][j];
        }
    }
    cout << endl;
    drawMatrix(Matrix);
    cout << "Row Echelon form Start!! : \n\n";
    REF(Matrix);
    cout << endl << "Row Echelon form Done!!  \n\n";
    cout << endl << "=====================================================================" << endl << endl;
    cout << "Reduced Row Echelon form Start!! : \n\n";
    RREF(Matrix);
    cout << "Reduced Row Echelon form Done!!  \n\n";

    cout << endl << "=====================================================================" << endl << endl;

    cout << "Prepared By : 1-Abd_Alraheem_Shawer." << endl;
    cout << "            : 2-Yazan_Abu_Khaled." << endl;
    cout << "            : 3-Shadi_Ameer_Almohtaseb." << endl;
    cout << endl << endl << endl << endl;
}
void drawMatrix(float Matrix[][COL])
{
    int NumberOfRows = ROW;
    int NumberOfCols = COL;
    int i = 0;
    cout << endl << "**** Step" << endl << endl;
    for (i = 0; i < NumberOfRows; i++) {
        for (int j = 0; j < NumberOfCols; j++) {
            if (Matrix[i][j] == -0) {
                Matrix[i][j] = 0;
            }
            cout << "     " << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void REF(float Matrix[][COL]) {
    for (int k = 0; k < ROW; k++)
    {
        if ((Matrix[k][k]) != 1)
        {
            float temp = Matrix[k][k];
            if (temp == 0)
                continue;
            for (int j = 0; j < COL; j++)
            {
                Matrix[k][j] = ((Matrix[k][j]) / temp);
            }
        }

        for (int i = k + 1; i < ROW; i++)
        {
            tem = Matrix[i][k];
            for (int j = k; j < COL; j++)
            {

                Matrix[i][j] = Matrix[i][j] - (Matrix[k][j] * tem);
            }

        }

        cout << "\n****\n";
        if (k == ROW - 1)
            cout << "Row Echelon form is : \n\n";
        else
            cout << "Step \n\n", k + 1;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (Matrix[i][j] == -0)
                    Matrix[i][j] = 0;
                cout << "     " << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void RREF(float Matrix[][COL])
{
    const int NumberOfRows = 3; // # of rows
    const int NumberOfCols = COL; // # of columns
    int leading = 0;
    while (leading < NumberOfRows) {
        float Divisor, Multiplier;
        // r = 1; lead = 1;
        for (int row = 0; row < NumberOfRows; row++) {
            Divisor = Matrix[leading][leading];
            Multiplier = Matrix[row][leading] / Matrix[leading][leading]; // m = 1 ;
            for (int col = 0; col < NumberOfCols; col++) {
                if (row == leading) {
                    if (Matrix[row][col] == -0) {
                        Matrix[row][col] = 0;
                    }
                    Matrix[row][col] = Matrix[row][col] / Divisor;
                }
                else
                {
                    if (Matrix[row][col] == -0) {
                        Matrix[row][col] = 0;
                    }
                    Matrix[row][col] = Matrix[row][col] - Matrix[leading][col] * Multiplier;
                }
                /*
                    Example For :
                    |               |
                    |  5 -6 -7 7    |
                    |  3 -2 5 -17   |
                    |  2 4 -3 29    |

                    sol:
                         5      -6      -7      7
                         3      -2      5      -17
                         2      4      -3      29

                         1      -1.2      -1.4      1.4
                         0      1.6      9.2      -21.2
                         0      6.4      -0.2      26.2

                         1      0      5.5      -14.5
                         0      1      5.75      -13.25
                         0      0      -37      111

                         1      0      0      2
                         0      1      0      4
                         0      0      1      -3
                */
            }
        }
        leading++;
        drawMatrix(Matrix);
    }
}


/*
    5 -6 -7 7
    3 -2 5 -17
    2 4 -3 29
*/