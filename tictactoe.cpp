#include <iostream>

int main()
{
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int r = -1;
    int c = -1;
    char winner = ' ';

    for (int i = 0; i < 9; i++)
    {
        std::cout << "   |   |   \n";
        std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
        std::cout << "___|___|___\n";
        std::cout << "   |   |\n";
        std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
        std::cout << "___|___|___\n";
        std::cout << "   |   |\n";
        std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
        std::cout << "   |   |\n";

        if (winner != ' ')
        {
            break;
        }

        std::cout << "Current player is: " << currentPlayer << std::endl;
        while (true)
        {
            std::cout << "Enter your row and column for your next move (0 -> 2): ";
            std::cin >> r >> c;
            if (r > 2 || r < 0 || c > 2 || c < 0)
            {
                std::cout << "Invalid row or column. Please try again.\n";
            }
            else if (board[r][c] != ' ')
            {
                std::cout << "That tile is filled. Please try again.\n";
            }
            else
            {
                break;
            }
            //reset value
            r = -1;
            c = -1;
            std::cin.clear(); //clear error flags that causing infinite loop
            std::cin.ignore(10000, '\n'); // discard values
        }
        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        //check for horizontal
        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2])
            {
                winner = board[r][0];
                break;
            }
        }

        //check for vertical
        for (int c = 0; c < 3; c++)
        {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board [1][c] == board[2][c])
            {
                winner = board[0][c];
                break;
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][0];
            break;
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][2];
            break;
        }
    }
    if (winner != ' ')
        {
            std::cout << "The winner is: " << winner << "!\n";
        }
    else
    {
        std::cout << "Tie.";
    }
}