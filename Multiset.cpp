#include <iostream>
using namespace std;

template <typename T>
class multiset{
private:
    T* A;
    int dim;
    int top;

    void raddoppia(){
        T* temp = new T[dim*2];
        for (int i = 0; i < dim; i++)
            temp[i] = A[i];
        dim *= 2;
        A = temp;
    }
public:
    multiset(){
        dim = 5;
        T* A = new T[dim];
        top = 0;
    }

    void add(T x){
        if(isEmpty())
            raddoppia();
        T* temp = new T[dim];
        for (int i = 0; i < top; i++)
            temp[i] = A[i];
        temp[top] = x;
        top++;
        A = temp;
    }

    bool contains(T x){
        for (int i = 0; i < top; i++)
            if (x == A[i])
                return true;
        return false;
    }

    int multiplicity(T x){
        int count = 0;
        for (int i = 0; i < top; i++)
            if (A[i] == x)
                count++;
        return count;
    }

    void remove(T x){
        T* temp = new T[dim];
        int new_top = 0;
        bool contains = false;
        for (int i = 0; i < top; i++) {
            if (A[i] == x) {
                contains = true;
                continue;
            }
            temp[new_top] = A[i];
            new_top++;
        }
        if(!contains)
            throw "elemento non contenuto";
        top = new_top;
        A = temp;
    }

    multiset<T> operator+ (multiset<T> other){
        multiset<T> ins;
        T* somma = new T[this->dim + other.dim];
        int count = 0;
        for (int i = 0; i < this->top; i++) {
            somma[count] = this->A[i];
            count++;
        }
        for (int i = 0; i < other.top; i++) {
            somma[count] = other.A[i];
            count++;
        }
        ins.A = somma;
        ins.top = count;
        ins.dim = this->dim + other.dim;
        return ins;
    }

    bool isEmpty(){
        return top == dim;
    }

    int getTop() const{
        return top;
    }

    T getValue(int i) const{
        return A[i];
    }
};

template <typename T>
ostream& operator<< (ostream& fout, const multiset<T>& x){
    for (int i = 0; i < x.getTop(); i++)
        fout << x.getValue(i) << " ";
    fout << endl;
    return fout;
}

int main() {
    multiset<int> ins;
    multiset<int> ins2;
    multiset<int> ins3;
    ins.add(5);
    ins.add(2);
    ins.add(2);
    ins.add(2);
    ins.add(3);
    ins.add(4);
    cout << ins;
    if(ins.contains(4))
        cout << "L'elemento e' contenuto" << endl;
    else
        cout << "L'elemento non e' contenuto" << endl;

    int x = 2;
    cout << "L'elemento " << x << " e' contenuto nell'insieme " << ins.multiplicity(x) << " volte" << endl;
    try {
        ins.remove(1);
    }
    catch(const char* txt){
        cout << txt << endl;
    }
    cout << ins;
    ins2.add(6);
    ins2.add(7);
    ins2.add(8);
    ins3 = ins + ins2;
    cout << ins3;
    return 0;
}
