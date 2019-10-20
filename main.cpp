#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void duomenuSkaitymas(int balsai[], int &balsavusiujuSkaicius, int &kandidatuSkaicius, ifstream &read);
void skaiciuotiBalsus(int balsai[], int kandidatai[], int balsavusiujuSkaicius, int kandidatuSkaicius);
void rezultatuRasymas(int kandidatai[], int kandidatuSkaicius, ofstream &write);

int const MAX_BALSAI = 1000,
          MAX_KANDIDATAI = 100;

int main()
{
    int balsavusiujuSkaicius = 0,
        kandidatuSkaicius = 0,
        balsai[MAX_BALSAI],
        kandidatai[MAX_KANDIDATAI];

    for (int i = 0; i < MAX_KANDIDATAI; i++) {
        kandidatai[i] = 0;
    }

    ifstream read("balsavimo_duomenys.txt");
    if (!read) {return 1;}
    ofstream write("balsavimo_lentele.txt");

    duomenuSkaitymas(balsai, balsavusiujuSkaicius, kandidatuSkaicius, read);
    skaiciuotiBalsus(balsai, kandidatai, balsavusiujuSkaicius, kandidatuSkaicius);
    rezultatuRasymas(kandidatai, kandidatuSkaicius, write);

    read.close();
    write.close();

    cout << "--------------------------------------\n";
    cout << "Skaitykite faila balsavimo_lentele.txt" << endl;
    cout << "--------------------------------------\n";

    return 0;
}

void duomenuSkaitymas(int balsai[], int &balsavusiujuSkaicius, int &kandidatuSkaicius, ifstream &read)
{
    read >> balsavusiujuSkaicius >> kandidatuSkaicius;
    for (int i = 0; i < balsavusiujuSkaicius; i++) {
        read >> balsai[i];
    }
}

void skaiciuotiBalsus(int balsai[], int kandidatai[], int balsavusiujuSkaicius, int kandidatuSkaicius)
{
    for (int i = 0; i < balsavusiujuSkaicius; i++) {
        for (int j = 0; j < kandidatuSkaicius; j++) {
            if (balsai[i] == (j + 1)) {
                kandidatai[j]++;
            }
        }
    }
}

void rezultatuRasymas(int kandidatai[], int kandidatuSkaicius, ofstream &write)
{
    write << "-------------------------------------\n";
    write << "|  Kandidato nr." << setw(10) << "  |   Balsu kiekis  |\n";
    write << "-------------------------------------\n";
    for (int i = 0; i < kandidatuSkaicius; i++) {
        write << "|  " << i + 1 << setw(18) << "  |   " << kandidatai[i] << setw(15) << "|\n";
    }
    write << "-------------------------------------\n";

}