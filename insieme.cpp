#include <iostream>
using namespace std;

template <typename T>
class Insieme{
private:
    T* A;
    int dim;
public:
    Insieme(){
        dim = 0;
        T* A = new T[dim];
    }

    Insieme(const Insieme<T>& other) : Insieme(){
        for(int i = 0; i < dim; i++)
            add(other.A[i]);
    }

    /*~Insieme(){
        delete[] A;
    }*/

    void add(T x){
        if(contains(x))
            throw "Elemento gia' presente";

        T* temp = new T[dim+1];
        for(int i = 0; i < dim; i++)
            temp[i] = this->A[i];
        temp[dim] = x;
        dim++;
        A = temp;
    }

    bool contains(T x){
        for (int i = 0; i < dim; i++)
            if(x == A[i])
                return true;

        return false;
    }

    Insieme<T> operator+(Insieme<T>& other){
        Insieme<T> sum;
        int count = 0;
        T* temp = new T[this->dim + other.dim];
        for (int i = 0; i < this->dim; i++)
            temp[count] = this->A[i];
        for (int i = 0; i < other.dim; i++)
            temp[count] = other.A[i];

        sum.A = this->A;
        sum.dim = count;

        return sum;
    }

    int getDim() const{
        return this->dim;
    }

    T getValue(int i) const{
        return this->A[i];
    }
};

template <typename T>
ostream& operator<< (ostream& fout, const Insieme<T>& ins){
    for (int i = 0; i < ins.getDim(); i++)
        fout << ins.getValue(i) << " ";
    cout << endl;
    return fout;
}

int main() {
    Insieme<int> ins;
    try {
        ins.add(1);
        ins.add(2);
        ins.add(3);
    }
    catch(const char* txt){
        cout << txt << endl;
    }
    cout << ins;
    int x;
    cin >> x;
    if(ins.contains(x))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

    cout << "Cardinalita' dell'insieme: " << ins.getDim() << endl;
    Insieme<int> ins2;
    ins2.add(4);
    ins2.add(5);
    Insieme<int> ins3;
    //ins3 = ins + ins2;
    cout << ins2;
    cout << ins + ins2;
    return 0;
}
