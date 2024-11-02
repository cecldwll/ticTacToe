#include<iostream>
#include <ctime>

// function to display the game board with current player and computer moves
void drawBoard(char* spaces);

// function to handle player's move by asking for input and updating the board
void playerMove(char* spaces, char player);

// function to randomly place the computer's move on an empty spot on the board
void computerMove(char* spaces, char computer);

// function to check if there is a winner by evaluating board state
bool checkWinner(char* spaces, char player, char computer);

// function to check if there is a tie (all spots are filled with no winner)
bool checkTie(char* spaces);

int main()
{
    // initialize board spaces, player and computer symbols, and game status
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    char computer = 'O';
    bool running = true;

    // draw the initial empty board
    drawBoard(spaces);

    // main game loop
    while (running) {
        // player's turn
        playerMove(spaces, player);
        drawBoard(spaces);

        // check if player won or if it's a tie
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }

        // computer's turn
        computerMove(spaces, computer);
        drawBoard(spaces);

        // check if computer won or if it's a tie
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }

    // game end message
    std::cout << "Thanks for playing!\n";

    return 0;
}

// function to display the tic-tac-toe board in console
void drawBoard(char* spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

// function to handle player's move by taking input and updating the board
void playerMove(char* spaces, char player) {
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--; // adjust for zero-based array
        // check if the chosen spot is empty
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (number >= 0 && number < 9); // validate input range
}

// function to handle computer's move by selecting a random empty spot
void computerMove(char* spaces, char computer) {
    int number;
    srand(time(0)); // seed random number generator

    // loop until an empty spot is found
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

// function to check if there is a winner by checking all possible winning lines
bool checkWinner(char* spaces, char player, char computer) {

    // check each row, column, and diagonal for matching non-empty symbols
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else {
        return false; // no winner found
    }

    return true; // winner found
}

// function to check for a tie by verifying all spots are filled with no winner
bool checkTie(char* spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') { // if any spot is empty, no tie
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true; // tie found if board is full with no winner
}
