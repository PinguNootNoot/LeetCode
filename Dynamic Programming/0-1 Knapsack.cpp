#include <bits/stdc++.h>
using namespace std;

/**
* Knapsack problem is NP-Complete.
*/

/* Alter the values to meet the problem's needs */
#define ItemNum 5
#define LoadLimit 10

/***************************************/

struct Item{
    int value;
    int weight;
};

Item items[ItemNum];
int backpack[LoadLimit+1];

void showBackpack(){
    cout << endl << "Backpack:" << endl << backpack[0];
    for(int i = 1; i <= LoadLimit; ++i) cout << ' ' << backpack[i];
    cout << endl;
}

void Knapsack(){
    int v, w;

    memset(backpack, 0, sizeof(backpack));
    for(int i = 0; i < ItemNum; ++i){
        v = items[i].value;
        w = items[i].weight;
        for(int j = LoadLimit; j - w >= 0; --j) backpack[j] = max(backpack[j], backpack[j-w] + v);
        // showBackpack();
    }
}

int main(){
    for(int i = 0; i < ItemNum; ++i){
        cin >> items[i].value >> items[i].weight;
    }
    Knapsack();
    cout << backpack[LoadLimit] << endl;

    return 0;
}
