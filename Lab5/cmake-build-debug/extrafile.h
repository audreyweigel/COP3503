#ifndef _EXTRAFILE_H
#define _EXTRAFILE_H

#include <iostream>
#include <vector>
using namespace std;

class Starship {
public:
    struct Weapon {
        string weaponString;
        int weaponInt;
        float weaponFloat;
    };
    string vesselName, shipClass;
    short shipLength;
    int shipCount, shieldCapacity;
    float maxShipSpeed;
    vector<Starship::Weapon> weaponElements;
    Starship(string name, string newClass, short length, int capacity, float speed, vector<Starship::Weapon>weapon);
private:
};

void ReadFile(int option1, vector<Starship>&refVector);
void StarshipWeapon(vector<Starship>&weaponVector);
void StrongestStarship(vector<Starship>&weaponVector);
void WeakestStarship(vector<Starship>&weaponVector);
void PrintStarships(vector<Starship>&weaponVector);
void UnarmedVessels(vector<Starship>&weaponVector);

#endif
