#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getComputerChoice() {
    return rand() % 3 + 1;
}

string getChoiceName(int choice) {
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}

int main() {
    srand(time(0));
    int user, computer;
    int userScore = 0, compScore = 0;
    char playAgain;

    cout << "🎮 Rock Paper Scissors Game\n";

    do {
        cout << "\n1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> user;

        if (user < 1 || user > 3) {
            cout << "❌ Invalid choice! Try again.\n";
            continue;
        }

        computer = getComputerChoice();

        cout << "You chose: " << getChoiceName(user) << endl;
        cout << "Computer chose: " << getChoiceName(computer) << endl;

        if (user == computer) {
            cout << "🤝 Draw!\n";
        } else if ((user == 1 && computer == 3) ||
                   (user == 2 && computer == 1) ||
                   (user == 3 && computer == 2)) {
            cout << "🎉 You win this round!\n";
            userScore++;
        } else {
            cout << "💻 Computer wins this round!\n";
            compScore++;
        }

        cout << "Score -> You: " << userScore 
             << " | Computer: " << compScore << endl;

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n🏁 Final Score\n";
    cout << "You: " << userScore << " | Computer: " << compScore << endl;

    if (userScore > compScore)
        cout << "🏆 You won the game!\n";
    else if (userScore < compScore)
        cout << "💻 Computer won the game!\n";
    else
        cout << "🤝 Game Draw!\n";

    return 0;
}
