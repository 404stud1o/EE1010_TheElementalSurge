#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

string version = "2025v4_0108";

void Home();
void Instructions();

int BasicLevel();
void PvPMode();
void Again();

int main() {
    cout << "\nWelcome to The Elemental Surge -A Text-Based Tactical Role Playing Game by Henry Li-" << endl;
    Home();

    return 0;
}

void Home() {
    cout << "\n------ Home ------ \n";
    cout << " 1. Start New Game \n 2. Instructions \n 3. Quit Game \n";
    cout << "Select option: ";
    int startInput;
    cin >> startInput;

    if (startInput == 1) {
        cout << "\n--- Game Modes --- \n";
        cout << " a. Single Player \n b. 2 Players PvP \n";
        cout << "Select game mode: ";
        char modeInput;
        cin >> modeInput;

        if (modeInput == 'A') {
            BasicLevel();
        }
        else if (modeInput == 'a') {
            BasicLevel();
        }
        else if (modeInput == 'B') {
            PvPMode();
        }
        else if (modeInput == 'b') {
            PvPMode();
        }
        else {
                cout << "\nSyntax Error. Game Restarting... \n" << endl;
                Sleep(500);
                main();
        }
    }
    else if (startInput == 2) {
        Instructions();
    }
    else if (startInput == 3) {
        cout << "\nThank you for playing The Elemental Surge. \n \nVersion: " << version << " \n(c)2025 Royal Holloway, University of London.\n";
        Sleep(2500);
        exit(0);
    }
    else {
        cout << "\nSyntax Error. Game Restarting... \n" << endl;
        Sleep(500);
        main();
        }
}

void Instructions() {
    cout << "\nLoading Instructions... \n";
    Sleep(500);

    cout << "\n----- Instructions ----- \n";
    cout << "This game follows a regular turn-based role-playing game (RPG) structure. \n";

    Sleep(1500);

    cout << "\nThe Single Player mode consists of 3 stages.\n";
    cout << "The game will be initialised with a default health of 1000 HP, 3 attack skills, and a Power Shield. \nThe attack skills are as following: \n";
    cout << "   A.	Fire Punch       (Attack), Opponent –100 HP \n";
    cout << "   B.	Voltage Blast    (Attack), Opponent –200 HP \n";
    cout << "   C.	Power Shield     (Defend), Player   +500 HP [3 Uses] \n";
    cout << "   D.	Mysterious Sonar (Attack), Opponent –500 HP [1 Use] \n";

    Sleep(5000);

    cout << "\nThe 2 Players Player-vs-Player (PvP) mode will initialise both players with the same settings of a default health of 1000 HP, \n3 attack skills, and a Power Shield. \nThe attack skills are as following: \n";
    cout << "   A.	Aqua Burst         (Attack), Opponent –200 HP \n";
    cout << "   B.	Golden Blast       (Attack), Opponent –400 HP \n";
    cout << "   C.	Power Shield       (Defend), Player   +300 HP [3 Uses] \n";
    cout << "   D.	Quantum Demolisher (Attack), Opponent –800 HP [1 Use] \n";

    cout << "\n * Please note that the Power Shield will never recover you to maximum health (HP 1000) * \n";

    Sleep(5000);

    char returnInput;
    cout << "\nPlease press any character and 'Enter' to return to main menu.";
    cin >> returnInput;

    if (returnInput == 'R' || returnInput == 'r') {
        Home();
    }
    else {
        Home();
    }
}

int BasicLevel() {
    string playerName;

    cout << "\nYou are now entering the Single Player Mode... \n";
    Sleep(500);

    cout << "\n Enter player name: ";
    cin >> playerName;

    int playerHP = 1000;
    const int firePunch = 100;
    const int voltageBlast = 200;
    const int powerShield = 500;
    const int mysteriousSonar = 500;
    bool sonarUsed = false;
    int shieldCounter = 3;

    srand(static_cast<unsigned>(time(0)));

    for (int stage = 1; stage <= 3; ++stage) {
        string opponent;
        int opponentHP = 0;
        if (stage == 1) {
            opponent = "Goblin";
            opponentHP = 200;
        }
        else if (stage == 2) {
            opponent = "Giant";
            opponentHP = 500;
        }
        else if (stage == 3) {
            opponent = "Demon";
            opponentHP = 1000;
        }

        cout << "\nStage " << stage << ": Opponent - " << opponent << " \n";

        while (playerHP > 0 && opponentHP > 0) {
            cout << "\n" << playerName << "'s HP: " << playerHP << "  |  Opponent's HP: " << opponentHP << endl;

            cout << "\n" << playerName << ", choose your move: \n";
            cout << " A. Fire Punch (-100 HP) \n B. Voltage Blast (-200 HP) \n C. Power Shield (+500 HP) [" << shieldCounter << " Uses Remaining] \n D. Mysterious Sonar (-500 HP) [1 Use] \n";
            cout << "Your move: ";
            char move;
            cin >> move;;

            if (move == 'A' || move == 'a') {
                opponentHP -= firePunch;
                cout << "\n" << "You used Fire Punch! \n";
            }
            else if (move == 'B' || move == 'b') {
                opponentHP -= voltageBlast;
                cout << "\n" << "You used Voltage Blast! \n";
            }
            else if (move == 'C' || move == 'c') {
                if (shieldCounter != 0) {
                    shieldCounter--; // Decrement shieldCounter by 1
                    if (playerHP > 1000) {
                        playerHP = 1000;    // Caps player's HP at 1000
                    }
                    else if (playerHP < 1000) {
                        int oldPlayerHP = playerHP;
                        playerHP = oldPlayerHP + powerShield;

                        if (playerHP > 1000) {
                            playerHP = 1000;    // Caps player's HP at 1000
                        }
                        else {
                            playerHP = playerHP;
                        }
                    }
                    cout << "\n" << "You used Power Shield! \n";
                    cout << shieldCounter << " Power Shield remaining. \n";
                }
                else if (shieldCounter == 0) {
                    cout << "No remaining Power Shield. \n";
                }
            }
            else if (move == 'D' || move == 'd') {
                if (!sonarUsed) {
                    opponentHP -= mysteriousSonar;
                    sonarUsed = true;

                    cout << "\n" << "You used Mysterious Sonar! \n";
                }
                else {
                    cout << "Mysterious Sonar can only be used once. \n";
                }
            }
            else {
                cout << "\nSyntax Error. Returning to Home Menu... \n" << endl;
                Sleep(500);
                Home();
            }

            if (opponentHP <= 0) {
                cout << "\n" << opponent << " has been defeated! \n";
                break;
            }

            int opponentAttack = rand() % 2;
            if (opponent == "Goblin") {
                playerHP -= (opponentAttack == 0) ? 50 : 100;
                if (playerHP < 0) {
                    playerHP = 0;
                }

                cout << "Goblin attacked you! \n";
            }
            else if (opponent == "Giant") {
                playerHP -= (opponentAttack == 0) ? 100 : 150;
                if (playerHP < 0) {
                    playerHP = 0;
                }

                cout << "Giant attacked you! \n";
            }
            else if (opponent == "Demon") {
                playerHP -= (opponentAttack == 0) ? 200 : 400;
                if (playerHP < 0) {
                    playerHP = 0;
                }

                cout << "Demon attacked you! \n";
            }
        }

        if (playerHP <= 0) {
            cout << "\n" << playerName << "'s HP: " << playerHP << "  |  Opponent's HP: " << opponentHP << "\n" << endl;
            cout << "\nDEFEATED. Game Over. \n";
            Again();
        }
    }

    cout << "\nVICTORY! Congratulations, " << playerName << "! \n";

    if (playerHP >= 900) {
        cout << "You have cleared this level with an S ranking! \n";
    }
    else if (playerHP >= 750) {
        cout << "You have cleared this level with an A+ ranking! \n";
    }
    else if (playerHP >= 650) {
        cout << "You have cleared this level with an A ranking! \n";
    }
    else if (playerHP >= 500) {
        cout << "You have cleared this level with a B ranking! \n";
    }
    else if (playerHP >= 300) {
        cout << "You have cleared this level with a C ranking! \n";
    }
    else if (playerHP >= 100) {
        cout << "You have cleared this level with a D ranking! \n";
    }
    else if (playerHP > 0) {
        cout << "You have cleared this level with an E ranking! \n";
    }

    Again();

    return 0;
}


void PvPMode() {
    string player1Name, player2Name;

    cout << "\nYou are now entering the 2 Players PvP Mode... \n";
    Sleep(500);

    cout << "\n Enter Player 1 Name: ";
    cin >> player1Name;
    cout << " Enter Player 2 Name: ";
    cin >> player2Name;

    int player1HP = 1500, player2HP = 1500;

    const int aquaBurst = 200;
    const int goldenBlast = 400;
    const int quantumDemolisher = 800;
    const int powerShield = 300;

    int player1ShieldCounter = 3, player2ShieldCounter = 3;
    bool player1QuantumUsed = false, player2QuantumUsed = false;

    while (player1HP > 0 && player2HP > 0) {
        // Player 1's Turn
        cout << "\n" << player1Name << "'s HP: " << player1HP << "  |  " << player2Name << "'s HP: " << player2HP << endl;

        cout << "\n--- " << player1Name << "'s turn ---\n";
        cout << " A. Aqua Burst (-200 HP) \n B. Golden Blast (-400 HP) \n C. Power Shield (+300 HP) [" << player2ShieldCounter << " Uses Remaining] \n D. Quantum Demolisher (-800 HP) [1 Use] \n";
        cout << "Your Move: ";
        char player1Move;
        cin >> player1Move;

        if (player1Move == 'A' || player1Move == 'a') {
            player2HP -= aquaBurst;
            cout << "\n" << player1Name << " used Aqua Burst! \n";
        }
        else if (player1Move == 'B' || player1Move == 'b') {
            player2HP -= goldenBlast;
            cout << "\n" << player1Name << " used Golden Blast! \n";
        }
        else if (player1Move == 'C' || player1Move == 'c') {
            if (player1ShieldCounter != 0) {
                player1ShieldCounter--; // Decrement shieldCounter by 1
                if (player1HP > 1500) {
                    player1HP = 1500;    // Caps player's HP at 1000
                }
                else if (player1HP < 1500) {
                    int player1OldHP = player1HP;
                    player1HP = player1OldHP + powerShield;

                    if (player1HP > 1500) {
                        player1HP = 1500;    // Caps player's HP at 1000
                    }
                    else {
                        player1HP = player1HP;
                    }
                }
                cout << "\n" << player1Name << " used Power Shield! \n";
                cout << player1ShieldCounter << " Power Shield remaining for " << player1Name << ". \n";
            }
            else if (player1ShieldCounter == 0) {
                cout << "No remaining Power Shield for " << player1Name << ". \n";
            }
        }
        else if (player1Move == 'D' || player1Move == 'd') {
            if (!player1QuantumUsed) {
                player2HP -= quantumDemolisher;
                player1QuantumUsed = true;
                cout << "\n" << player1Name << " used Quantum Demolisher! \n";
            }
            else {
                cout << "\nNo remaining Quantum Demolisher for " << player1Name << ". \n";
            }
        }
        else {
            cout << "\nSyntax Error. Returning to Home Menu... \n" << endl;
            Sleep(500);
            Home();
        }

        // Player 1 wins
        if (player2HP <= 0) {
            cout << "\n" << player2Name << " has been defeated. \nVICTORY! Congratulations, " << player1Name << "! \n";

            if (player1HP >= 1200) {
                cout << "You have won the round with an S ranking! \n";
            }
            else if (player1HP >= 1000) {
                cout << "You have won the round with an A ranking! \n";
            }
            else if (player1HP >= 850) {
                cout << "You have won the round with a B ranking! \n";
            }
            else if (player1HP >= 500) {
                cout << "You have won the round with a C ranking! \n";
            }
            else if (player1HP >= 200) {
                cout << "You have won the round with a D ranking! \n";
            }
            else if (player1HP > 0) {
                cout << "You have won the round with a E ranking! \n";
            }

            Again();
        }

        // Player 2's Turn
        cout << "\n" << player1Name << "'s HP: " << player1HP << "  |  " << player2Name << "'s HP: " << player2HP << endl;

        cout << "\n--- " << player2Name << "'s turn ---\n";
        cout << " A. Aqua Burst (-200 HP) \n B. Golden Blast (-400 HP) \n C. Power Shield (+300 HP) [" << player2ShieldCounter << " Uses Remaining] \n D. Quantum Demolisher (-800 HP, one-time use) \n";
        cout << "Your Move: ";
        char player2Move;
        cin >> player2Move;

        if (player2Move == 'A' || player2Move == 'a') {
            player1HP -= aquaBurst;
            cout << "\n" << player2Name << " used Aqua Burst! \n";
        }
        else if (player2Move == 'B' || player2Move == 'b') {
            player1HP -= goldenBlast;
            cout << "\n" << player1Name << " used Golden Blast! \n";
        }
        else if (player2Move == 'C' || player2Move == 'c') {
            if (player2ShieldCounter != 0) {
                player2ShieldCounter--; // Decrement shieldCounter by 1
                if (player2HP > 1500) {
                    player2HP = 1500;    // Caps player's HP at 1000
                }
                else if (player2HP < 1500) {
                    int player2OldHP = player2HP;
                    player2HP = player2OldHP + powerShield;

                    if (player2HP > 1500) {
                        player2HP = 1500;    // Caps player's HP at 1000
                    }
                    else {
                        player2HP = player2HP;
                    }
                }
                cout << "\n" << player2Name << " used Power Shield! \n";
                cout << player2ShieldCounter << " Power Shield remaining for " << player2Name << ". \n";
            }
            else if (player2ShieldCounter == 0) {
                cout << "No remaining Power Shield for " << player2Name << ". \n";
            }
        }
        else if (player2Move == 'D' || player2Move == 'd') {
            if (!player2QuantumUsed) {
                player1HP -= quantumDemolisher;
                player2QuantumUsed = true;
                cout << "\n" << player2Name << " used Quantum Demolisher! \n";
            }
            else {
                cout << "No remaining Quantum Demolisher for " << player2Name << ". \n";
            }
        }
        else {
            cout << "\nSyntax Error. Returning to Home Menu... \n" << endl;
            Sleep(500);
            Home();
        }

        // Player 2 wins
        if (player1HP <= 0) {
            cout << "\n" << player1Name << " has been defeated. \nVICTORY! Congratulations, " << player2Name << "! \n";

            if (player2HP >= 1200) {
                cout << "You have won the round with an S ranking! \n";
            }
            else if (player2HP >= 1000) {
                cout << "You have won the round with an A ranking! \n";
            }
            else if (player2HP >= 850) {
                cout << "You have won the round with a B ranking! \n";
            }
            else if (player2HP >= 500) {
                cout << "You have won the round with a C ranking! \n";
            }
            else if (player2HP >= 200) {
                cout << "You have won the round with a D ranking! \n";
            }
            else if (player2HP > 0) {
                cout << "You have won the round with a E ranking! \n";
            }

            Again();
        }
    }
}

void Again() {
    char againInput;
    cout << "\nWould you like to continue?  [Y / N]" << endl;
    cin >> againInput;
    if (againInput == 'Y' || againInput == 'y') {
        cout << "\n--- Game Modes --- \n";
        cout << " a. Single Player \n b. 2 Players PvP \n c. Instructions \n d. Home \n";
        cout << "Select game mode: ";
        char modeInput;
        cin >> modeInput;

        if (modeInput == 'A' || modeInput == 'a') {
            BasicLevel();
        }
        else if (modeInput == 'B' || modeInput == 'b') {
            PvPMode();
        }
        else if (modeInput == 'C' || modeInput == 'c') {
            Instructions();
        }
        else if (modeInput == 'D' || modeInput == 'd') {
            main();
        }
        else {
            cout << "\nSyntax Error. Returning to Home Menu... \n" << endl;
            Sleep(500);
            Home();
        }
    }
    else if (againInput == 'N' || againInput == 'n') {
        cout << "\nThank you for playing The Elemental Surge. \n \nVersion: " << version << " \n(c)2025 Royal Holloway, University of London.\n";
        Sleep(2500);
        exit(0);
    }
}
