#include <iostream>
#include <vector>
#define max 9
using namespace std;

class SudokuSolver
{   
    private:
    bool isPossible(vector<vector<int>> &sudoku , int row , int col , int target)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            //check for row
            if(sudoku[row][i] == target)
            {
                return false;
            }

            //check for col
            if(sudoku[i][col] == target)
            {
                return false;
            }

            //check for inner box
            int newRow = 3*(row/3) + i/3;
            int newCol = 3*(col/3) + i%3;
            if(sudoku[newRow][newCol] == target)
            {
                return false;
            }
        }
        return true;
    }

    public:

    //solver function
    bool solver(vector<vector<int>> &sudoku)
    {
        //step-1 -> traverse the matrix and find the empty place
        for(int row = 0 ; row < max ; row++)
        {
            for(int col = 0 ; col < max ; col++)
            {
                //if any of the element is zero means that is the empty place
                if(sudoku[row][col] == 0)
                {
                    //now try placing numbers from 1-9 and check possibility
                    for(int i = 1 ; i <= 9 ; i++)
                    {
                        if(isPossible(sudoku , row , col , i))
                        {
                            sudoku[row][col] = i; // if possible then place the value in the matrix
                            
                            bool isNextPartPossible = solver(sudoku); //call for remaining empty spaces

                            if(isNextPartPossible) //if for i next part is possible then i is the correct value 
                            {
                                return true;
                            }
                            else
                            {
                                //if its not possible the i is not the possible solution for sudoku[row][col]
                                sudoku[row][col] = 0; //remove i and try some new value
                            }
                        }
                    }
                    //if it is out of the loop then no possible values found 
                    return false;
                }
            }
        }
        //if it completes all the loops then solution is done 
        return true;
    }
    
};

//print function
void printMatrix(const vector<vector<int>> &sudoku)
    {
        for(int row = 0 ; row < sudoku.size() ; row++)
        {
              // Print horizontal lines after every 3 rows (except the first)
            if (row % 3 == 0 && row != 0)
            {
                cout << " ------+-------+------" << endl;
            }
            for(int col = 0 ; col < sudoku[row].size() ; col++)
            {
                //print vertical lines
                if (col % 3 == 0 && col != 0)
                {
                    cout << " |";
                }
                cout << " " << sudoku[row][col];
            }
            cout << endl;
        }
    }
int main()
{
    SudokuSolver solve;
    vector<vector<int>> sudoku(max , vector<int>(max));
    //take input
    cout << "Enter the sudoku question (0 for empty space) : " << endl;
    for(int row = 0 ; row < sudoku.size() ; row++)
    {
        for(int col = 0 ; col < sudoku[row].size() ; col++)
        {
            cin >> sudoku[row][col];
        }
    }

    cout << "\n\nBefore solving : " << endl;
    printMatrix(sudoku);

    if(solve.solver(sudoku))
    {
        cout << "\n\nAfter solving : " << endl;
        printMatrix(sudoku);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }
    return 0;
}