#include <iostream>

#include <fstream>

#include <string>

#include <vector>


using namespace std;

int main() {
    fstream plik;
    plik.open("dane_obrazki.txt", ios:: in );

    vector < int > ktory;
    vector < int > ktora_kolumna;
    vector < int > ktory_wiersz;

    int pomocniczy = 0;
    int pomocniczy1 = 0;
    int ile = 0;
    char dobry;
    int poprawny = 0;
    int nienaprawialny = 0;
    int naprawialny = 0;
    int zlywiersz = 0;
    int zlakolumna = 0;
    int kolumna = 0;
    int wiersz = 0;
    int ktory_obrazek = 0;

    while (!plik.eof()) {

        ktory_obrazek++;
        pomocniczy1 = 0;
        pomocniczy = 0;

        string obraz[21];
        zlakolumna = 0;
        zlywiersz = 0;

        for (int i = 0; i < 21; i++) {
            plik >> obraz[i];

        }

        for (int i = 0; i < 20; i++) {
            wiersz++;
            for (int j = 0; j < 20; j++) {
                if (obraz[i][j] == '1') {
                    ile++;
                }
                if (j == 19) {
                    if (ile % 2 == 1) {
                        dobry = '1';
                    } else {
                        dobry = '0';
                    }

                    if (dobry != obraz[i][20]) {
                        pomocniczy1 = wiersz;
                        zlywiersz++;
                    }
                    ile = 0;
                }
            }
        }

        wiersz = 0;
        for (int i = 0; i < 20; i++) {
            kolumna++;
            for (int j = 0; j < 20; j++) {
                if (obraz[j][i] == '1') {
                    ile++;
                }
                if (j == 19) {
                    if (ile % 2 == 1) {
                        dobry = '1';
                    } else {
                        dobry = '0';
                    }

                    if (obraz[20][i] != dobry) {
                        pomocniczy = kolumna;
                        zlakolumna++;
                    }
                    ile = 0;
                }
            }
        }
        kolumna = 0;

        if (zlakolumna > 1 || zlywiersz > 1) {
            nienaprawialny++;

        } else if (zlakolumna > 0 || zlywiersz > 0) {
            naprawialny++;
            ktory.push_back(ktory_obrazek);
            if (pomocniczy == 0) {
                pomocniczy = 21;
            }
            if (pomocniczy1 == 0) {
                pomocniczy1 = 21;
            }
            ktora_kolumna.push_back(pomocniczy);
            ktory_wiersz.push_back(pomocniczy1);

        } else if (zlakolumna == 0 || zlywiersz == 0) {
            poprawny++;

        }

    }
    //        cout<<"poprawnych "<<poprawny<<endl;
    //        cout<<"nie naprawialny "<<nienaprawialny<<endl;
    //        cout<<"naprawilanych "<<naprawialny<<endl;
    //        cout<<"maks bledow "<<max_errors;

    for (int i = 0; i < ktory.size(); i++) {

        cout << "(" << ktory[i] << "," << ktory_wiersz[i] << "," << ktora_kolumna[i] << ")" << endl << endl;
    }

    return 0;
}
