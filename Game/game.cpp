#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessTheNumber {
private:
    int randomNumber;

public:
    GuessTheNumber() {
        // Initialize random seed
        srand(time(nullptr));
        // Generate random number between 1 and 100
        randomNumber = rand() % 100 + 1;
    }

    void playGame() {
        cout << "Welcome to Guess The Number!" << endl;
        cout << "I have selected a random number between 1 and 100. Try to guess it." << endl;

        int guess;
        int attempts = 0;
        do {
            cout << "Enter your guess (between 1 and 100): ";
            cin >> guess;
            attempts++;

            if (guess < randomNumber) {
                cout << "Too low! Try again." << endl;
            } else if (guess > randomNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts." << endl;
                return;
            }
        } while (true);
    }
};

int main() {
    GuessTheNumber game;
    game.playGame();
    return 0;
}
