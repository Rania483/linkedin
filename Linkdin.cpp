

#include <iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<algorithm>
#include"person.h"
using namespace std;


std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return result;
}

int main()
{
    string line;
    int i = 0;
    vector<person*> people;
    int id;
    string name;
    int yearOfBirth;
    string major;
    string university;
    string jopPlace;
    vector<int>connections;

    while (getline(cin, line)) {

        if (line.empty()) {
            i++;
        }
        else {
            i = 0;
        }
        if (i == 2) {
            //cout << "finish";
            break;
        }
        size_t colonPos = line.find(':');
        if (colonPos == string::npos) {
            continue; // Skip lines without a colon
        }
        string value = line.substr(colonPos + 1);
        value.erase(0, value.find_first_not_of(" \t")); // Trim leading spaces
         //cout << value;

        if (line.find("ID:") == 0) {
            id = stoi(value);
        }
        else if (line.find("Name:") == 0) {
            name = toLowerCase(value);
        }
        else if (line.find("Year of Birth:") == 0) {
            yearOfBirth = stoi(value);
        }
        else if (line.find("University:") == 0) {
            university = toLowerCase(value);
        }
        else if (line.find("Major:") == 0) {
            major = toLowerCase(value);
        }
        else if (line.find("Job Place:") == 0) {
            jopPlace = toLowerCase(value);
        }
        else if (line.find("Connections:") == 0) {

            stringstream ssConn(value);
            int conn;
            while (ssConn >> conn) {
                connections.push_back(conn);
                if (ssConn.peek() == ',') {
                    ssConn.ignore();
                }
            }
            person* p = new person(id, name, yearOfBirth, university, major, jopPlace, connections);
            people.push_back(p);
            connections.clear();





        }
    }

    for (int u = 0; u < people.size(); u++) {
        people[u]->set_neigh(people);
        people[u]->set_gr(people);

    }
    people[0]->connection_graph(people);
    for (int u = 0; u < people.size(); u++) {
        people[u]->suggestion(people);
    }

}