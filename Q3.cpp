#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray D(3);
    cout << "---------------------\n";

    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    DynamicArray D1(arr, 10);
    cout << "---------------------\n";

    DynamicArray D2(D);
    cout << "---------------------\n";

    cout<<D1[3]<<endl;
    D1[4] = 4;
    cout << "---------------------\n";
    DynamicArray D3(D1(1, 7));
    //D3 = D1(1, 7);
    cout << "---------------------\n";
    DynamicArray D4(D3(1));
   // D4 = D3(2);
    cout<<"---------------------\n";
    DynamicArray D5(D1(4, 8));
    cout << "---------------------\n";
    DynamicArray D6(D(1));
    cout << "---------------------\n";
    D6 += 4;
    cout << "---------------------\n";

    //string s;
    //s = string(D4);
    //cout<<"---------------------\nD4: "<<int(D4)<<endl;
//    if(D3==D2){
//        cout<<"D3 and D4 are equal!\n";
//    }else{cout<<"Hello!\n";}
//    if(D!=D1){
//        cout<<"D and D1 are not equal!\n";
//    }
    cout << int(D) << endl;
    cout << int(D1) << endl;
    cout << int(D2) << endl;
    cout << int(D3) << endl;
    cout << int(D4) << endl;
    cout << int(D5) << endl;
    cout << int(D6) << endl;
    //cout<<"Heeeeeeeeee\n";
    cout << "---------------------m\n";
    
    return 0;

}