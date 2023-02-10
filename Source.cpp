#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char ABC[50] = { 'a','b','c','d','e','f','g','h','i','j','k','l',
                     'm','n','o','p','q','r','s','t','u','v','w','x','y','z',
                     '0','1','2','3','4','5','6','7','8','9', ' ' };
    // created an array with valid values for encryption
    char msg[1000]; // array for storing the message
    int shift; // stores the shift key
    int index;
    int j = 0;
    VVOD:
    cout << "enter the message you want to encode': " << endl;
    cout << "lowercase Latin letters and numbers from 0-9 are accepted for input" << endl;
    cout << endl;
    cin.get(msg, 1000); //we enter a message into the msg array
    for (int i = 0; i < 1000; i++) {    // checking for a register
        int aa;
        aa = isupper(msg[i]);
        cout << aa;
        if (aa == 1) {
            cout << "Nuzhno vvodit' v nizhnem registre!" << endl;
            goto VVOD;
        }
    }
    SDVIG:
    cout << "you need to enter in lowercase: ";   // the user enters the key for the cipher
    cin >> shift;
    int choise;
    SHIFRDESHIFR:
    cout << "if you want to encrypt enter 1 if you want to decrypt enter 2: " << endl; // Pol'zovatel' vybiraet zashifrovat' ili deshifrovat' soobshchenie
    cin >> choise;
    if (choise == 1) {

        for (int i = 0; i < strlen(msg); i++) {
            if (msg[i] != ' ') {

                while (msg[i] != ABC[j]) {
                    j++;
                }
                index = j + shift;
                if (index > 35) {
                    index = (index - 35) - 1;
                }
                msg[i] = ABC[index];
                j = 0;
            }
            else {
                msg[i] = ' ';
            }

        }
        cout << msg << endl;
    }
    else if (choise == 2) {
        for (int i = 0; i < strlen(msg); i++) {
            if (msg[i] != ' ') {
                while (msg[i] != ABC[j]) {
                    j++;
                }
                index = j - shift;
                msg[i] = ABC[index];
                j = 0;
            }
            else {
                msg[i] = ' ';
            }
        }
        cout << msg << endl;
    }
    else {
        cout << "need to enter in 1 or 2" << endl;
        goto SHIFRDESHIFR;
    }

}

