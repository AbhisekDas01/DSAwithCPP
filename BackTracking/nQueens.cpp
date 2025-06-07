#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isPossible(vector<string> &board, int row, int col, int n)
{

    int x = row;
    int y = col;

    // check upper diagonal
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }

    // check bottom diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x++;
        y--;
    }

    // check left side
    x = row;
    y = col;

    while (y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        y--;
    }

    return true;
}

void nQueens(int col, vector<string> &board, int n, vector<vector<string>> &result)
{

    if (col == n)
    {
        result.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isPossible(board, row, col, n))
        {
            board[row][col] = 'Q';
            nQueens(col + 1, board, n, result);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "\n=== N-Queens Problem Solver ===\n\n";
    cout << "Enter the size of chess board (n x n): ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;

    nQueens(0, board, n, result);

    cout << "\n================================\n";
    cout << "Total number of solutions: " << result.size() << "\n";
    cout << "================================\n\n";

    for (int i = 0; i < result.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n\n";

        // Print top border
        cout << "   ";
        for (int k = 0; k < n; k++)
            cout << "+---";
        cout << "+\n";

        // Print board with queens
        for (int j = 0; j < n; j++)
        {
            cout << " " << j + 1 << " ";
            for (char c : result[i][j])
            {
                cout << "| " << (c == 'Q' ? "Q" : " ") << " ";
            }
            cout << "|\n";

            // Print horizontal line after each row
            cout << "   ";
            for (int k = 0; k < n; k++)
                cout << "+---";
            cout << "+\n";
        }

        // Print column numbers
        cout << "    ";
        for (int k = 0; k < n; k++)
        {
            cout << k + 1 << "   ";
        }
        cout << "\n\n--------------------------------\n\n";
    }

    return 0;
}