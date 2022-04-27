#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

char name[20];

//Frenzy Fighters functions and data members:

struct player
{
    int health;
    int pbar;
    int damage;
};
struct player p1, p2;

void init(struct player &p)
{
    p.health = 100;
    p.pbar = 0;
    p.damage = 10;
}

void healthcheck()
{
    if (p1.health<=0 && p2.health<=0){
        cout << "\nBoth players lost all health simultaneously. So, no one loses.\a\n";

    }
    else if (p1.health<=0 && p2.health>0){
        cout << "\nYou lose all health points. You lose!\a\n";

    }
    else if (p1.health>0 && p2.health<=0){
        cout << "\nThe bot loses all health points. You win!\a\n";

    }
}

void supercheck()
{
    char choice;
    if (p1.pbar>=3){
        Sleep(800);
        cout << "\nYou have a SUPERATTACK available. Would you like to use it? (Enter 'Y' for Yes and 'ANY OTHER KEY' for No)\n";
        cin >> choice;
        if (choice=='Y' || choice=='y'){
            Sleep(800);
            printf ("\nSUPER ATTACK UNLEASHED!!!\n You deal %d damage to bot.\n", p1.damage*2);
            p1.pbar=0;
            p2.health-=p1.damage*2;

        }
    }
    if (p2.pbar>=3){
        Sleep(800);
        cout << "\nBot is about to use its SUPER ATTACK.\n";
        Sleep(800);
        printf("Bot's SUPER ATTACK UNLEASHED!!!\n Bot deals %d damage to you.\n", p2.damage*2);
        Sleep(800);
        p2.pbar=0;
        p1.health-=p2.damage*2;

    }
}

void action(char m1, char m2)
{
    if (m1=='A' && m2=='A'){
        printf("Both players attack each other successfully - You lose %d health points and the bot loses %d health points.\n", p2.damage, p1.damage);
        p1.health-=p2.damage;
        p2.damage+=(p2.damage*3)/10;
        p2.health-=p1.damage;
        p1.damage+=(p1.damage*3)/10;
    }
    else if (m1=='A' && m2=='B'){
        printf("The bot blocks incoming attack successfully -> +1 power bar for bot.\n");
        p2.pbar++;
        p1.damage-=(p1.damage*3)/20;
    }
    else if (m1=='A' && m2=='C'){
        printf("Bot's charge fails and you attack successfully. Bot loses %d health points.\n", p1.damage);
        p2.health-=p1.damage;
        p1.damage+=(p1.damage*3)/10;
    }
    else if (m1=='B' && m2=='A'){
        printf("You block bot's incoming attack successfully -> +1 power bar for you.\n");
        p1.pbar++;
        p2.damage-=(p2.damage*3)/20;
    }
    else if (m1=='B' && m2=='B'){
        printf("+1 power bar for both players.\n");
        p1.pbar++;
        p2.pbar++;
    }
    else if (m1=='B' && m2=='C'){
        printf("Bot uses a charge attack and your block fails. You lose %d health points and bot gains %d health points.\n", p2.damage/2, p2.damage/2);
        p1.health-=p2.damage/2;
        p2.health+=p2.damage/2;
        p2.damage+=p2.damage/5;
    }
    else if (m1=='C' && m2=='A'){
        printf("Your charge fails and bot attacks successfully. You lose %d health points.\n", p2.damage);
        p1.health-=p2.damage;
        p2.damage+=(p2.damage*3)/10;
    }
    else if (m1=='C' && m2=='B'){
        printf("You use a charge attack and bot's block fails. You gain %d health points and bot loses %d health points.\n", p1.damage/2, p1.damage/2);
        p2.health-=p1.damage/2;
        p1.health+=p1.damage/2;
        p1.damage+=p1.damage/5;
    }
    else if (m1=='C' && m2=='C'){
        printf("Both players charge at each other. You: %d health gained, Bot: %d health gained\n", p1.damage/2-p2.damage/2, p2.damage/2-p1.damage/2);
        p1.health-=p2.damage/2;
        p2.health+=p2.damage/2;
        p2.health-=p1.damage/2;
        p1.health+=p1.damage/2;
        p1.damage+=p1.damage/5;
        p2.damage+=p2.damage/5;
    }
    else {
        cout << "Invalid move entered!\n";
    }
}

void frenzyFighters()
{
    system("CLS");
    cout << "************************\n";
    cout << "*   FRENZY FIGHTERS!   *" << endl;
    cout << "************************\n";
    cout << "\nRules:\n\n";
    cout << "This is a 1v1 game where you will have to first fill in 3 moves, and so will the computer do (randomly).\n";
    cout << "Initially, both players (YOU & BOT) have 100 HP, 10 damage points and 0 power bars.\n";
    cout << "You have 3 options per move: Attack(A), Block(B), Charge(C)\n\n";
    cout << "All possible combinations:\n";
    cout << "ATK-ATK: Both LOSE HP as much as OTHER'S CURRENT DAMAGE POINTS, and both GAIN +30% damage points.\n";
    cout << "BLK-BLK: Both players do nothing and only GAIN 1 POWER BAR each.\n";
    cout << "CHG-CHG: Both players GAIN HP equal to HALF of their current DAMAGE POINTS and INFLICT that much damage on their opponent.\n";
    cout << "ATK-CHG: The attacker REDUCES OPPONENT'S HEALTH by the amount of his current DAMAGE POINTS and also GAIN +30% damage points.\n";
    cout << "ATK-BLK: The attack FAILS and the attacker LOSES -15% damage points and the blocker GAINS +1 POWER BAR.\n";
    cout << "BLK-CHG: The charger INFLICTS damage equal to half its current DAMAGE POINTS and also GAINS that many HP.\n\n";
    cout << "SUPERATTACK: Once the 3 moves are done and if you have 3 or more power bars, you will be given the option to do a super attack, ";
    cout << "\nwhich will inflict damage that is TWICE(2x) of your current damage rating.\n";
    cout << "NOTE: If both players have 3 or more power bars, then you will be given the option to use your super attack first. Use it wisely!\n";
    cout << "\nGOAL: Reduce opponent's health to or below 0 to win the game.\n";



    srand(time(0));
    int i;
    char pmove[3],cmove[3];
    char s[] = "ABC";
    init(p1);
    init(p2);
    while (true)
    {

        cout << "\nEnter any key\n";
        getch();
        system("CLS");
        cout << "\n\nYou:\nHealth Points: " << p1.health << "\nPower Bars: " << p1.pbar << "\nDamage Points: " << p1.damage << endl;
        cout << "\nBot:\nHealth Points: " << p2.health << "\nPower Bars: " << p2.pbar << "\nDamage Points: " << p2.damage << endl ;
        cout << "\n\n(Enter 'Q' to exit the game at any time.)\n";


        cout << "\n(Enter 'A' for ATTACK, 'B' for BLOCK or 'C' for CHARGE)\n\n";
        for (i=0;i<3;i++){
            cout <<  "Enter move " << i+1 << " : ";
            cin >> pmove[i];
            if (pmove[i] == 'Q') break;
            cmove[i] = s[rand()%3];
        }
        if (pmove[i] == 'Q') break;
        Sleep(1000);
        cout << "Computer's moves: " << cmove[0] << ", " << cmove[1] << ", " << cmove[2] << endl << endl;
        Sleep(1000);
        for (i=0;i<3;i++){
            cout << "Action on Move " << i+1 << ": ";

            action(pmove[i], cmove[i]);
            Sleep(800);

            if (p1.health<=0 || p2.health<=0)
                break;
        }

        if (p1.pbar>=3 || p2.pbar>=3)
            supercheck();
        Sleep(700);
        if (p1.health<=0 || p2.health<=0)
            break;

    }
    healthcheck();

    i=0;
    char g[]="GAME";
    cout << endl;
    while (g[i]!='\0'){
        cout << g[i];
        Sleep(600);
        i++;
    }
    Sleep(700);
    cout << " OVER!";
    Sleep (700);
    cout << "\n\nPress any key return to the main menu";
    getch();

}

//Slot Machine functions and data members:

void decideReward(char x1, char x2, char x3, int &stake)
{
    if ((x1==x2) && (x2==x3)){
        switch(x1)
        {
        case '\001':
            cout << "\n\aCONGRATS! You win " << stake*200 << "$ !!!";
            stake *= 200;
            break;
        case '\002':
            cout << "\n\aCONGRATS! You win " << stake*250 << "$ !!!";
            stake *= 250;
            break;
        case '\003':
            cout << "\n\aCONGRATS! You win " << stake*400 << "$ !!!";
            stake *= 400;
            break;
        case '\004':
            cout << "\n\aCONGRATS! You win " << stake*400 << "$ !!!";
            stake *= 400;
            break;
        case '\005':
            cout << "\n\aCONGRATS! You win " << stake*400 << "$ !!!";
            stake *= 400;
            break;
        case '\006':
            cout << "\n\aCONGRATS! You win " << stake*400 << "$ !!!";
            stake *= 400;
            break;
        case '7':
            cout << "\n\aJACKPOT! YOU WIN " << stake*10000 << "$ !!!";
            stake *= 10000;
            break;
        }
    }
    else if ((x1==x2) || (x2==x3) || (x3==x1)){
        cout << "You get your bet amount back!";
    }
    else {
        cout << "Better luck next time!";
        stake = 0;
    }
}

void slotMachine()
{
    system("CLS");
    cout << "*********************\n";
    cout << "*   SLOT MACHINE!   *" << endl;
    cout << "*********************\n\n\n";
    cout << "Try your luck !!!\n\n";
    cout << "Instructions:\n";
    cout << "You get an initial amount of 1000$.\n";
    cout << "You have to enter a stake amount (any integer from 0 to 'balance amount').\n";
    cout << "\nPRIZE POOL:\n";
    cout << "ALL \001 - receive 200x of stake amount!\n";
    cout << "ALL \002 - receive 250x of stake amount!\n";
    cout << "ALL \003/\004/\005/\006 - receive 400x of stake amount!\n";
    cout << "ALL 7s - $JACKPOT$ ! Receive 10000x the stake amount!\n";
    cout << "ANY TWO slots same - receive the stake amount back!\n";
    cout << "In all other cases, you will lose the stake amount from your balance.\n";
    cout << "If your balance amount drops to 0, the game will be over!\n\n";
    system("pause");
    int balance = 1000, stake, score, i;
    srand(time(0));

    char x1,x2,x3, choiceSM;
    char c[] = {'\001', '\002', '\003', '\004', '\005', '\006', '7'};
    char s[] = {'\001', '\001', '\001', '\001', '\002', '\002', '\002', '\003', '\003', '\003',
                '\004', '\004', '\004', '\005', '\005', '\005', '\006', '\006', '\006', '7'};
    while (true) {
    system("CLS");
    cout << "BALANCE: " << balance << "$\n\n";
    cout << "Enter STAKE amount: ";
    cin >> stake;

    if (stake > balance){
        cout << "Stake CANNOT be HIGHER than balance amount!\n\n";
        system("PAUSE");
        continue;
    }
    else if (stake < 0){
        cout << "Stake can't be negative!\n";
        system("pause");
        continue;
    }

    balance -= stake;

    cout << " _____ _____ _____\n";
    cout << "|     |     |     |\n";
    cout << "|     |     |     |\n";
    cout << "|  ";

    for (i = 0; i < 10; i++) {
        cout << c[rand()%7] << "\b";
        Sleep(150);
    }
    x1 = s[rand()%20];
    cout << x1;
    cout << "  |  ";
    for (i = 0; i < 10; i++) {
        cout << c[rand()%7] << "\b";
        Sleep(180);
    }
    x2 = s[rand()%20];
    cout << x2;
    cout << "  |  ";
    for (i = 0; i < 10; i++) {
        cout << c[rand()%7] << "\b";
        Sleep(230);
    }
    x3 = s[rand()%20];
    cout << x3;
    cout << "  |\n";
    cout << "|     |     |     |\n";
    cout << "|_____|_____|_____|\n\n";

    decideReward(x1,x2,x3,stake);

    balance += stake;
    if (balance == 0){
        cout << "\n\nGame Over! You lose all you money.";
        break;
    }
    cout << "\n\nNew Balance = " << balance << "$";
    cout << "\n\nEnter 'Q'/'q' to cash out/exit, or enter any other key to play again.\n";
    cin >> choiceSM;
    if (choiceSM == 'Q' || choiceSM == 'q')
        break;
    }
    cout << "\n\nYour score is: " << 100*balance << " !\n\n";
    system("pause");
}


//Tic-Tac-Toe functions and data members:

struct TTTplayer
{
    char name[20];
    char marker;
};
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

/*
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
*/

int winCheck()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


void board() //FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
{
    system("CLS");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

void ticTacToe()
{
    int player = 1,i,choice;

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;
        cout << "Player " << player << ", enter the number where you want to fill your symbol: ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            cout<<"\nInvalid move!\n";
            player--;
            cin.ignore();
            system("pause");
        }

        i=winCheck();

        player++;

    }while(i==-1);

    board();
    if(i==1)
        cout<<"==>\aPlayer "<<--player<<" wins!\n";

    else
        cout<<"==>\aGame draw\n";

    system("PAUSE");
}


void mainMenu()
{
    cout << "\n\n        Enter player name: ";
    cin.get(name, 20);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line

    system("cls");
    cout << "\n\n        Welcome " << name;
    getch();
    while (true){
    system("CLS");
    cout << " __________________________ " << endl;
    cout << "|  ______________________  |" << endl;
    cout << "| |                      | |" << endl;
    cout << "| |    \001 MINI-GAMES \001    | |" << endl;
    cout << "| |______________________| |" << endl;
    cout << "|__________________________|" << endl;
    cout << "\n\nPress:\n1 for 'Slot Machine'\n";
    cout << "2 for 'Frenzy Fighters'" << endl;
    cout << "3 for 'Tic-Tac-Toe'" << endl;
    cout << "4 to exit" << endl;
    int choice;
    cout << "\nEnter your choice: ";

    cin >> choice;
    if (choice==1)
        slotMachine();
    else if (choice==2)
        frenzyFighters();
    else if (choice==3)
        ticTacToe();
    else if (choice==4)
        break;
    else {
        cout << "\n\nInvalid choice!\nPress any key to return to main menu!";
        getch();
    }
    }
    cout << "\n\nSee you again, " << name << " !\003\n";
}

int main()
{
    mainMenu();
    return 0;
}
