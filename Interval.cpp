#include <iostream>
using namespace std;

class Interval{
private:
    int start;
    int end;
public:
    Interval(){
        start = 0;
        end = 0;
    }

    Interval(int start, int end){
        this->start = start;
        this->end = end;
    }

    bool Contains(int e) const{
        for (int i = start; i <= end; i++)
            if (e == i)
                return true;
        return false;
    }

    Interval& join(Interval& other){
        this->end = other.end;
        return *this;
    }
};

int main() {
    Interval i(2,8);
    if(i.Contains(10))
        cout << "l'elemento e' contenuto";

    return 0;
}
