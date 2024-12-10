#include <iostream>
using namespace std;

class Data{
private:
    int g;
    int m;
    int a;
public:
    Data(){
        g = 15;
        m = 4;
        a = 2003;
    }
    Data(int g, int m, int a){
        this->g = g;
        this->m = m;
        this->a = a;
    }

    bool valida(int giorno, int mese, int anno){
        if(anno >= 0 && anno <= 2023) {
            if (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12) {
                if (giorno >= 0 && giorno <= 31)
                    return true;
                else {
                    cout << "Giorno inserito non compatibile, riprovare" << endl;
                    return false;
                }
            }
            else if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
                if (giorno >= 0 && giorno <= 30)
                    return true;
                else {
                    cout << "Giorno inserito non compatibile, riprovare" << endl;
                    return false;
                }
            }
            else if(mese == 2){
                if(giorno >= 0 && giorno <= 29)
                    return true;
                else {
                    cout << "Giorno inserito non compatibile, riprovare" << endl;
                    return false;
                }
            }
            else{
                cout << "Mese inserito non compatibile, riprovare" << endl;
                return false;
            }
        }
        else{
            cout << "Anno inserito non compatibile, riprovare" << endl;
            return false;
        }
    }

    int getGiorno() const{
        return g;
    }
    int getMese() const{
        return m;
    }
    int getAnno() const{
        return a;
    }

    void setGiorno(int giorno){
        this->g = giorno;
    }
    void setMese(int mese){
        this->m = mese;
    }
    void setAnno(int anno){
        this->a = anno;
    }
};

ostream& operator<<(ostream& dest, Data d){
    dest << d.getGiorno() << "/" << d.getMese() << "/" << d.getAnno() << endl;
    return dest;
}

istream& operator>>(istream& source, Data d){
    int g, m, a;
    char sep;
    cout << "Inserisci una data" << endl;
    source >> g >> sep >> m >> sep >> a;

    while(!d.valida(g, m, a)){
        source >> g >> sep >> m >> sep >> a;
    }
    d.setGiorno(g);
    d.setMese(m);
    d.setAnno(a);
}

int main() {
    Data d1;
    cin >> d1;
    cout << d1;
    return 0;
}
