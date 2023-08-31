#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// Задача о рюкзаке, сложность О(N*W), N - количество чиселя, W - максимальная вместимость рюкзака.
// Идея - расмотерть комбинации без повторений и запомнить все числа, которые мы можем получить из этих комбинаций
// и взять последнее (как задача с играми, где всевозмодные варианты - клетчатое поле)

int main(){
    ios::sync_with_stdio(false);
    int n, w;
    cin>>w>>n;
    int sum=0;
    vector <int> variety(w+1);
    variety[0]=1;
    for(int i=1; i<=w;++i){
        variety[i]=0;
    }
    vector <int> mass(n);
    for (int i=0; i<n; ++i){
        cin>>mass[i];
    }
    sort(mass.begin(), mass.end());
    int sumer;
    for(int j=0; j<n;++j){
        sumer=mass[j];
        int i=w; // Идем с конца, чтобы избежать повторений!!
        while (i>=0 ){
            if(variety[i]!=0){
                if(i+sumer<=w){
                    variety[i+sumer]=1;
                }
            }
            i--;
        }
    }
    int counter=w;
    while(variety[counter]==0){
        counter--;
    }
    cout<<counter;
}