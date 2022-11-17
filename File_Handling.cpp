#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
using namespace std;

struct Student {
    int ID;
    string name;
    string gender;
    float score;
};

void readFile(fstream& f) {
    Student* students = new Student[100];
    f.open("text.txt", ios::in);
    if (f.is_open() == false) {
        cout << "error in opening file";
        return;
    }

    int i = 0;
    f.seekg(21);
    while (i < 3) {
        string temp_id, temp_score;
        getline(f, temp_id, ',');
        students[i].ID = stoi(temp_id);
        getline(f, students[i].name, ',');
        getline(f, students[i].gender, ',');
        getline(f, temp_score);
        students[i].score = stof(temp_score);
        ++i;
    }
    f.close();

    for (int j = 0; j < i; j++) {
        cout << students[j].ID << " " << students[j].name << " " << students[j].gender << " " << students[j].score << endl;
    }
}


int main() {
    fstream f;
    readFile(f);
}