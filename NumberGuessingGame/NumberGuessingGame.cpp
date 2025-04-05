

#include <iostream>
using namespace std;


int main()
{
    int min;
    int max;
    int correctNum;
    int guessedNum;

    cout << "Enter min number" << endl;
    cin >> min;
    cout << "Enter max number" << endl;
    cin >> max;

    correctNum = rand() % max + min;

    cout << "I'm thinking of a number between ";
    cout << min;
    cout << " and ";
    cout << max << endl;

    cin >> guessedNum;

    (guessedNum == correctNum) ? (cout << "You win!") : (cout << "You lose!");

    return 0;
}