#include <iostream>
#include <string>

using namespace std;

void intro() {
    cout << "Welcome to 'Escape the Dungeon'!" << endl;
    cout << "You find yourself trapped in a dark dungeon." << endl;
    cout << "Your mission is to find a way out." << endl;
}

bool handlePathChoice() {
    int choice;
    cout << "You see two paths ahead. Do you want to take (1) Left or (2) Right? ";
    cin >> choice;

    if (choice == 1) {
        cout << "You have chosen the left path." << endl;
        return true;
    }
    else if (choice == 2) {
        cout << "You have chosen the right path." << endl;
        return false;
    } else {
        cout << "Invalid input. Please choose (1) or (2)." << endl;
        return handlePathChoice();  // Retry if invalid input
    }
}

void encounterMonster(bool pathLeft) {
    int choice;
    if (pathLeft) {
        cout << "A fierce monster blocks your way!" << endl;
        cout << "Do you want to (1) Fight or (2) Flee? ";
    } else {
        cout << "You encounter a deep pit!" << endl;
        cout << "Do you want to (1) Jump or (2) Look for another way? ";
    }

    cin >> choice;

    switch (choice) {
        case 1:
            if (pathLeft) {
                cout << "You bravely fight the monster and win!" << endl;
            } else {
                cout << "You jump across the pit and survive!" << endl;
            }
            break;
        case 2:
            if (pathLeft) {
                cout << "You flee from the monster, but it catches up and you perish!" << endl;
            } else {
                cout << "You find another way around the pit, but it's a dead end. You perish!" << endl;
            }
            break;
        default:
            cout << "Invalid input. Please choose (1) or (2)." << endl;
            encounterMonster(pathLeft);  // Retry if invalid input
    }
}

void playGame() {
    intro();

    bool pathLeft = handlePathChoice();
    encounterMonster(pathLeft);
}

int main() {
    cout << "Are you ready to escape the dungeon? (y/n): ";
    char ready;
    cin >> ready;

    if (ready == 'y' || ready == 'Y') {
        playGame();
    } else {
        cout << "Maybe next time!" << endl;
    }

    return 0;
}
                    