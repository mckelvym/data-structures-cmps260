#include<iostream>

using namespace std;

int main(){
    int a;
	for(int x = 0; x < 10; x++)
		cout << rand() % 10 << endl;
	cin >> a;
	return 0;
}

