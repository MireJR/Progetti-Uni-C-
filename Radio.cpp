#include <iostream>
using namespace std;

class Radio{
private:
    float frequenza;
    int volume;
    bool stato;
public:
    Radio() {
        stato = false;
        volume = 5;
        frequenza = 105;
    }

    void accendi(){
        if(!stato){
            stato = true;
            volume = 5;
            frequenza = 105;
            cout << "Radio accesa" << endl;
        }
        else
            cout << "Radio già accesa" << endl;
    }
    void spegni(){
        if(stato){
            stato = false;
            volume = 0;
            frequenza = 0;
            cout << "Radio spenta" << endl;
        }
        else
            cout << "Radio già spenta" << endl;
    }
    void alzaVolume(){
        if(stato){
            if(volume == 10)
                throw "Volume gia' al massimo";
            else {
                volume++;
                cout << "Volume: " << volume << endl;
            }
        }
        else
            cout << "La radio e' spenta" << endl;
    }
    void abbassaVolume(){
        if(stato){
            if(volume == 0)
                cout << "Volume già al minimo" << endl;
            else {
                volume--;
                cout << "Volume: " << volume << endl;
            }
        }
        else
            cout << "La radio e' spenta" << endl;
    }
    void aumentaFrequenza(){
        if(stato){
            frequenza+=0.1;
            cout << "Frequenza: " << volume << endl;
        }
        else
            cout << "La radio e' spenta" << endl;
    }
    void diminuisciFrequenza(){
        if(stato){
                frequenza-=0.1;
                cout << "Frequenza: " << volume << endl;
        }
        else
            cout << "La radio e' spenta" << endl;
    }
    void stampa(ostream& dest) const{
        if(stato){
            dest << "____________________" << endl;
            dest << "Volume: " << volume << endl;
            dest << "Frequenza: " << frequenza << endl;
            dest << "____________________" << endl;
        }
        else
            dest << "Radio spenta" << endl;
    }
    void leggi(istream& source) {
        this->accendi();
        cout << "Inserisci la frequenza" << endl;
        source >> frequenza;
        cout << "Inserisci il volume" << endl;
        source >> volume;
    }
};

istream& operator>> (istream& source, Radio& r){
    r.leggi(source);
    return source;
}

ostream& operator<< (ostream& dest, Radio& r){
    r.stampa(dest);
    return dest;
}

int main() {
    Radio r1;
    cin >> r1;
    cout << r1;
    r1.accendi();
    r1.alzaVolume();
    cout << r1;
    try{
        r1.alzaVolume();
        r1.alzaVolume();
        r1.alzaVolume();
        r1.alzaVolume();
        r1.alzaVolume();
        r1.alzaVolume();
        r1.alzaVolume();
    }
    catch(const char * exc){
        cout << exc;
    }
    return 0;
}
