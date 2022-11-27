#include "menupart3.h"
#include "country.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(Country c1, Country c2) {
    return c1.getPop() < c2.getPop();
}

void MenuPart3::menu() {
    vector<Country> t2;
    t2.resize(100);

    char op;
    int i = 0;
    do {
        cout << "1. Add country\n2. List countries\n3. Find largest country\n4. Remove country\n5. Sort countries\nQ. Quit\nEnter Option: ";
        cin >> op;
        if (op == '1') {
            if (i == t2.size()) t2.resize(2 * i);

            cout << "Enter details:" << endl;
            Country c;
            cin >> c;
            t2[i] = c;
            i++; // 1 larger than last actual idx stored

            //cout << "i: " << i << " size:" << t2.size() << endl;
        }
        else if (op == '2') {
            if (i == 0) {}
            else for (int j = 0; j < i; j++) cout << "[" << j + 1 << "] " << t2[j] << endl;
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
                for (int j = idx - 1; j < i - 1; j++) t2[j] = t2[j + 1];
                i--;
            }
        }
        else if (op == '5') {
            stable_sort(t2.begin(), t2.begin() + i, compare);
        }
    } while (op != 'q' && op != 'Q');
}
