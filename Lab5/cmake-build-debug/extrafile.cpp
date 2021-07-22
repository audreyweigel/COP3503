#include "extrafile.h"
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

Starship::Starship(string name, string newClass, short length, int capacity, float speed, vector<Starship::Weapon>weapon) {
    // contains
    vesselName = name;
    shipClass = newClass;
    shipLength = length;
    shieldCapacity = capacity;
    maxShipSpeed = speed;
    weaponElements = weapon;
}

void ReadFile(int option1, vector<Starship>&refVector) {
    ifstream checkFile("friendlyships.shp", ios_base::binary);
    ifstream readFile("enemyships.shp", ios_base::binary);

    int newOption = option1;
    string tempName, tempClass;
    short tempShipLength;
    int tempCount, tempCapacity, tempWeapon, tempLength;
    float tempSpeed;
    char* tempChar;

    if (newOption == 1) {
        if (!checkFile.is_open()) {
            cout << "Error" << endl;
        }
        checkFile.read((char*)&tempCount, sizeof(tempCount));
        for (int i = 0; i < tempCount; i++) {
            checkFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            checkFile.read(tempChar, tempLength);
            tempName = tempChar;
            delete[] tempChar;
            checkFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            checkFile.read(tempChar, tempLength);
            tempClass = tempChar;
            delete[] tempChar;
            checkFile.read((char*)&tempShipLength, sizeof(tempShipLength));
            checkFile.read((char*)&tempCapacity, sizeof(tempLength));
            checkFile.read((char*)&tempSpeed, sizeof(tempLength));
            checkFile.read((char *)&tempWeapon, sizeof(tempLength));

            vector<Starship::Weapon>weaponVector;
            for (int j = 0; j < tempWeapon; j++) {
                string weaponName;
                int newWeaponInt;
                float floatWeapon;
                checkFile.read((char *) &tempLength, sizeof(tempLength));
                tempChar = new char[tempLength];
                checkFile.read(tempChar, tempLength);
                weaponName = tempChar;
                delete[] tempChar;
                checkFile.read((char *) &newWeaponInt, 4);
                checkFile.read((char *) &floatWeapon, 4);

                Starship::Weapon newWeapon;
                newWeapon.weaponString = weaponName;
                newWeapon.weaponInt = newWeaponInt;
                newWeapon.weaponFloat = floatWeapon;
                weaponVector.push_back(newWeapon);
            }
            refVector.emplace_back(tempName, tempClass, tempShipLength, tempCapacity, tempSpeed, weaponVector);
        }
    }
    else if (newOption == 2) {
        readFile.read((char*)&tempCount, sizeof(tempCount));
        if (!readFile.is_open()) {
            cout << "Error" << endl;
        }
        for (int i = 0; i < tempCount; i++) {
            readFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            readFile.read(tempChar, tempLength);
            tempName = tempChar;
            delete[] tempChar;
            readFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            readFile.read(tempChar, tempLength);
            tempClass = tempChar;
            delete[] tempChar;
            readFile.read((char*)&tempShipLength, sizeof(tempShipLength));
            readFile.read((char*)&tempCapacity, sizeof(tempCapacity));
            readFile.read((char*)&tempSpeed, sizeof(tempSpeed));
            readFile.read((char *)&tempWeapon, sizeof(tempWeapon));

            vector<Starship::Weapon>weaponVector;
            for (int j = 0; j < tempWeapon; j++) {
                string weaponName;
                int newWeaponInt;
                float floatWeapon;
                readFile.read((char *) &tempLength, sizeof(tempLength));
                tempChar = new char[tempLength];
                readFile.read(tempChar, tempLength);
                weaponName = tempChar;
                delete[] tempChar;
                readFile.read((char *) &newWeaponInt, 4);
                readFile.read((char *) &floatWeapon, 4);

                Starship::Weapon newWeapon;
                newWeapon.weaponString = weaponName;
                newWeapon.weaponInt = newWeaponInt;
                newWeapon.weaponFloat = floatWeapon;
                weaponVector.push_back(newWeapon);
            }
            refVector.emplace_back(tempName, tempClass, tempShipLength, tempCapacity, tempSpeed, weaponVector);
        }
    }
    else if (newOption == 3) {
        checkFile.read((char*)&tempCount, sizeof(tempCount));
        if (!checkFile.is_open()) {
            cout << "Error" << endl;
        }
        for (int i = 0; i < tempCount; i++) {
            checkFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            checkFile.read(tempChar, tempLength);
            tempName = tempChar;
            delete[] tempChar;
            checkFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            checkFile.read(tempChar, tempLength);
            tempClass = tempChar;
            delete[] tempChar;
            checkFile.read((char*)&tempShipLength, sizeof(tempShipLength));
            checkFile.read((char*)&tempCapacity, sizeof(tempCapacity));
            checkFile.read((char*)&tempSpeed, sizeof(tempSpeed));
            checkFile.read((char *)&tempWeapon, sizeof(tempWeapon));

            vector<Starship::Weapon>weaponVector;
            for (int j = 0; j < tempWeapon; j++) {
                string weaponName;
                int newWeaponInt;
                float floatWeapon;
                checkFile.read((char *) &tempLength, sizeof(tempLength));
                tempChar = new char[tempLength];
                checkFile.read(tempChar, tempLength);
                weaponName = tempChar;
                delete[] tempChar;
                checkFile.read((char *) &newWeaponInt, 4);
                checkFile.read((char *) &floatWeapon, 4);

                Starship::Weapon newWeapon;
                newWeapon.weaponString = weaponName;
                newWeapon.weaponInt = newWeaponInt;
                newWeapon.weaponFloat = floatWeapon;
                weaponVector.push_back(newWeapon);
            }
            refVector.emplace_back(tempName, tempClass, tempShipLength, tempCapacity, tempSpeed, weaponVector);
        }
        readFile.read((char*)&tempCount, sizeof(tempCount));
        if (!readFile.is_open()) {
            cout << "Error" << endl;
        }
        for (int i = 0; i < tempCount; i++) {
            readFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            readFile.read(tempChar, tempLength);
            tempName = tempChar;
            delete[] tempChar;
            readFile.read((char*)&tempLength, sizeof(tempLength));
            tempChar = new char[tempLength];
            readFile.read(tempChar, tempLength);
            tempClass = tempChar;
            delete[] tempChar;
            readFile.read((char*)&tempShipLength, sizeof(tempShipLength));
            readFile.read((char*)&tempCapacity, sizeof(tempCapacity));
            readFile.read((char*)&tempSpeed, sizeof(tempSpeed));
            readFile.read((char *)&tempWeapon, sizeof(tempWeapon));

            vector<Starship::Weapon>weaponVector;
            for (int j = 0; j < tempWeapon; j++) {
                string weaponName;
                int newWeaponInt;
                float floatWeapon;
                readFile.read((char *) &tempLength, sizeof(tempLength));
                tempChar = new char[tempLength];
                readFile.read(tempChar, tempLength);
                weaponName = tempChar;
                delete[] tempChar;
                readFile.read((char *) &newWeaponInt, 4);
                readFile.read((char *) &floatWeapon, 4);

                Starship::Weapon newWeapon;
                newWeapon.weaponString = weaponName;
                newWeapon.weaponInt = newWeaponInt;
                newWeapon.weaponFloat = floatWeapon;
                weaponVector.push_back(newWeapon);
            }
            refVector.emplace_back(tempName, tempClass, tempShipLength, tempCapacity, tempSpeed, weaponVector);
        }
    }
    else {
        cout << "Invalid input" << endl;
    }
}

void PrintStarships(vector<Starship>&weaponVector) {
    for (unsigned int i = 0; i < weaponVector.size(); i++) {
        cout << "Name: " << weaponVector.at(i).vesselName << endl;
        cout << "Class: " << weaponVector.at(i).shipClass << endl;
        cout << "Length: " << weaponVector.at(i).shipLength << endl;
        cout << "Shield capacity: " << weaponVector.at(i).shieldCapacity << endl;
        cout << "Maximum Warp: " << weaponVector.at(i).maxShipSpeed << endl;
        cout << "Armaments:" << endl;
        int index = 0;
        if (weaponVector.at(i).weaponElements.size() > 0) {
            for (unsigned int j = 0; j < weaponVector.at(i).weaponElements.size(); j++) {
                index += weaponVector.at(i).weaponElements.at(j).weaponInt;
                cout << weaponVector.at(i).weaponElements.at(j).weaponString << ", " << weaponVector.at(i).weaponElements.at(j).weaponInt << ", " << weaponVector.at(i).weaponElements.at(j).weaponFloat << endl;
            }
            cout << "Total firepower: " << index << endl;
        }
        else {
            cout << "Unarmed" << endl;
        }
    }
}

void StarshipWeapon(vector<Starship>&weaponVector) {
    int powerfulWeapon = 0;
    unsigned int index = 0;
    unsigned int index1;
    for (unsigned int i = 0; i < weaponVector.size(); i++) {
        for (unsigned int j = 0; j < weaponVector.at(i).weaponElements.size(); j++) {
            if (weaponVector.at(i).weaponElements.at(j).weaponInt >= powerfulWeapon) {
                index += weaponVector.at(i).weaponElements.at(j).weaponInt;
                powerfulWeapon = weaponVector.at(i).weaponElements.at(j).weaponInt;
                index1 = i;
            }
        }
    }
    cout << "Name: " << weaponVector.at(index1).vesselName << endl;
    cout << "Class: " << weaponVector.at(index1).shipClass << endl;
    cout << "Length: " << weaponVector.at(index1).shipLength << endl;
    cout << "Shield capacity: " << weaponVector.at(index1).shieldCapacity << endl;
    cout << "Maximum Warp: " << weaponVector.at(index1).maxShipSpeed << endl;
    cout << "Armaments:" << endl;
    for (unsigned int h = 0; h < weaponVector.at(index1).weaponElements.size(); h++) {
        cout << weaponVector.at(index1).weaponElements.at(h).weaponString << ", "
             << weaponVector.at(index1).weaponElements.at(h).weaponInt << ", "
             << weaponVector.at(index1).weaponElements.at(h).weaponFloat << endl;
    }
    cout << "Total firepower: " << index << endl;
}

void StrongestStarship(vector<Starship>&weaponVector) {
    int totalStarship = 0;
    unsigned int index = 0;
    int maxValue = 0;
    for (unsigned int i = 0; i < weaponVector.size(); i++) {
        for (unsigned int j = 0; j < weaponVector.at(i).weaponElements.size(); j++) {
            totalStarship += weaponVector.at(i).weaponElements.at(j).weaponInt;
        }
        if (totalStarship >= maxValue) {
            maxValue = totalStarship;
            index = i;
        }
        totalStarship = 0;
    }
    cout << "Name: " << weaponVector.at(index).vesselName << endl;
    cout << "Class: " << weaponVector.at(index).shipClass << endl;
    cout << "Length: " << weaponVector.at(index).shipLength << endl;
    cout << "Shield capacity: " << weaponVector.at(index).shieldCapacity << endl;
    cout << "Maximum Warp: " << weaponVector.at(index).maxShipSpeed << endl;
    cout << "Armaments:" << endl;
    for (unsigned int h = 0; h < weaponVector.at(index).weaponElements.size(); h++) {
        cout << weaponVector.at(index).weaponElements.at(h).weaponString << ", "
             << weaponVector.at(index).weaponElements.at(h).weaponInt << ", "
             << weaponVector.at(index).weaponElements.at(h).weaponFloat << endl;
    }
    cout << "Total firepower: " << maxValue << endl;
}

void WeakestStarship(vector<Starship>&weaponVector) {
    int totalStarship = 0;
    unsigned int index = 0;
    int minValue = INT_MAX;
    for (unsigned int i = 0; i < weaponVector.size(); i++) {
        for (unsigned int j = 0; j < weaponVector.at(i).weaponElements.size(); j++) {
            totalStarship += weaponVector.at(i).weaponElements.at(j).weaponInt;
        }
        if (weaponVector.at(i).weaponElements.size() != 0 && totalStarship <= minValue) {
            minValue = totalStarship;
            index = i;
        }
        totalStarship = 0;
    }
    cout << "Name: " << weaponVector.at(index).vesselName << endl;
    cout << "Class: " << weaponVector.at(index).shipClass << endl;
    cout << "Length: " << weaponVector.at(index).shipLength << endl;
    cout << "Shield capacity: " << weaponVector.at(index).shieldCapacity << endl;
    cout << "Maximum Warp: " << weaponVector.at(index).maxShipSpeed << endl;
    cout << "Armaments:" << endl;
    for (unsigned int h = 0; h < weaponVector.at(index).weaponElements.size(); h++) {
        cout << weaponVector.at(index).weaponElements.at(h).weaponString << ", "
             << weaponVector.at(index).weaponElements.at(h).weaponInt << ", "
             << weaponVector.at(index).weaponElements.at(h).weaponFloat << endl;
    }
    cout << "Total firepower: " << minValue << endl;
}

void UnarmedVessels(vector<Starship>&weaponVector) {
    for (unsigned int i = 0; i < weaponVector.size(); i++) {
        if (weaponVector.at(i).weaponElements.size() == 0) {
            cout << "Name: " << weaponVector.at(i).vesselName << endl;
            cout << "Class: " << weaponVector.at(i).shipClass << endl;
            cout << "Length: " << weaponVector.at(i).shipLength << endl;
            cout << "Shield capacity: " << weaponVector.at(i).shieldCapacity << endl;
            cout << "Maximum Warp: " << weaponVector.at(i).maxShipSpeed << endl;
            cout << "Armaments:" << endl;
            int index = 0;
            if (weaponVector.at(i).weaponElements.size() > 0) {
                for (unsigned int j = 0; j < weaponVector.at(i).weaponElements.size(); j++) {
                    index += weaponVector.at(i).weaponElements.at(j).weaponInt;
                    cout << weaponVector.at(i).weaponElements.at(j).weaponString << ", "
                         << weaponVector.at(i).weaponElements.at(j).weaponInt << ", "
                         << weaponVector.at(i).weaponElements.at(j).weaponFloat << endl;
                }
                cout << "Total firepower: " << index << endl;
            } else {
                cout << "Unarmed" << endl;
            }
        }
    }
}