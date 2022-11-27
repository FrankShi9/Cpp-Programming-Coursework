#include "menupart2.h"
#include "country.h"
#include <iostream>

using namespace std;

void MenuPart2::menu() {
    Country t2[9];
    

    char op;
    int i = 0;
    do {
        cout << "1. Add country\n2. List countries\n3. Find largest country\n4. Remove country\nQ. Quit\nEnter Option: ";
        cin >> op;
        if (op == '1') {
            if(i == 9) cout << "Can not add country: There are already 9 countries" << endl;
            else {
                cout << "Enter details:" << endl;
                Country c;
                cin >> c;
                t2[i] = c;
                i++; // 1 larger than last actual idx stored
            }
        }
        else if (op == '2') {
            if (i == 0) {}
            else for (int j = 0; j < i; j++) cout << "[" << j+1 << "] " << t2[j] << endl;
        } 
        else if (op == '3') {
            if (i == 0) cout << "There are no countries in the index currently";
            else {
                long best = 0;
                int idx = 0;
                for (int j = 0; j < i; j++) {
                    if (t2[j].getPop() > best) {
                        best = t2[j].getPop();
                        idx = j;
                    }
                }
                cout << "Largest: " << t2[idx] << endl;
            }
        }
        else if (op == '4') {
            cout << "Enter Index: " << endl;
            int idx = -1;
            cin >> idx;
            if (idx <= 0 || idx > i) cout << "No country has that index" << endl;
            else {
                for (int j = idx-1; j < i - 1; j++) t2[j] = t2[j + 1];
                i--;
            }
        }
    } while (op != 'q' && op != 'Q');
}
