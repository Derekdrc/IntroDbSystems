//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

//Simple C++ program to intake a text file, and process the ints in the text file

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

float average(int, vector<float>&);

int main() {
	int N;
	cout << "Please enter the number N of ints you would like to read between 1 and 13" << endl;
	cin >> N;
	while (N<=0 || N>=14){
		cout << "Invalid. Please enter N";
		cin >> N;
	}

	int numFileInts;
	int nextLine;

	ifstream Input;
	Input.open("./Scores.txt");

	if (Input.fail()) {
		cout << "Input failed to open \n";
		system("pause");
		exit(1);
	}

    std::vector<float> fileVector;

    while (Input >> nextLine) {
        fileVector.push_back(nextLine);
    }

    if (fileVector.size() == 0) {
        cout << "The file is empty";
        system("pause");
        exit(1);
    }

    std::vector<float> scoreVector;
    int count = 0; 
    while (count < N) {
        scoreVector.push_back(fileVector.at(count));
        count++;
    }
    for (int i = 0; i < scoreVector.size(); i++) {
        cout << scoreVector.at(i) << endl;
    }

    cout << "The average is " << setprecision(3) << average(N, scoreVector) << endl;

    //sort vector
    sort(scoreVector.begin(), scoreVector.end());
    cout << "The largest number is " << scoreVector.at(N-1) << " and the smallest number is " << scoreVector.at(0) << endl;

    system("pause");
    return 0;
}

float average(int N, vector<float>& scoreVector) {
    float total = 0;
    float numFloats = scoreVector.size();

    for (int i = 0; i < N; i++) {
        total += scoreVector.at(i);
    }

    return (total / N);

}