// Mark McKelvy
// CLID: jmm0468
// 2005 - 01 - 31

#include<iostream>

using namespace std;

const int numMonths = 12;

enum row{high, low, rows};

void getData(int temp[rows][numMonths]);
float highAvg(int temp[rows][numMonths]);
float lowAvg(int temp[rows][numMonths]);
int highTemp(int temp[rows][numMonths]);
int lowTemp(int temp[rows][numMonths]);

int main(){
	int temps[rows][numMonths] = {0};
	getData(temps);
	cout << "Average high: " << highAvg(temps) << " degrees. " << endl;
	cout << "Average low:  " << lowAvg(temps) << " degrees. " << endl;
	cout << "Highest Temp: " << highTemp(temps) << " degrees. " << endl;
	cout << "Lowest Temp:  " << lowTemp(temps) << " degrees. " << endl;
	return 0;
}

void getData(int temp[rows][numMonths]){
	cout << "Enter the high temperature for each month: " << endl;
	for(int i = 0; i < numMonths; i++){
		cin >> temp[high][i];
	}
	cout << "Enter the low temperature for each month: " << endl;
	for(int i = 0; i < numMonths; i++){
		cin >> temp[low][i];
	}
}

float highAvg(int temp[rows][numMonths]){
	int total = 0;
	for(int i = 0; i < numMonths; i++){
		total += temp[high][i];
	}
	return ((float)total / (float)numMonths);
}

float lowAvg(int temp[rows][numMonths]){
	int total = 0;
	for(int i = 0; i < numMonths; i++){
		total += temp[low][i];
	}
	return ((float)total / (float)numMonths);
}

int highTemp(int temp[rows][numMonths]){
	int highest = 0;
	int index = -1;
	for(int i = 0; i < numMonths; i++){
		if(temp[high][i] > highest){
			highest = temp[high][i];
			index = i;
		}
	}
	return index;
}

int lowTemp(int temp[rows][numMonths]){
	int lowest = 1000;
	int index = -1;
	for(int i = 0; i < numMonths; i++){
		if(temp[low][i] < lowest){
			lowest = temp[low][i];
			index = i;
		}
	}
	return index;
}
