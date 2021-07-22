#include "extrafile.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    vector<Starship>mainVector;

    if (option > 0 && option < 4) {
        ReadFile(option, mainVector);
    }
    /* Load files here */

    /* cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl; */

    cin >> option;


    switch(option) {
        case 1:
            // print all ships
            PrintStarships(mainVector);
            break;
        case 2:
            // starship w/ strongest weapon
            StarshipWeapon(mainVector);
            break;
        case 3:
            // strongest starship overall
            StrongestStarship(mainVector);
            break;
        case 4:
            WeakestStarship(mainVector);
            break;
        case 5:
            UnarmedVessels(mainVector);
            break;
        default:
            return 0;
    }
    /* Work your magic here */

    return 0;
}