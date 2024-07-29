#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class person
{
private:
	int id;
	string name;
	int year_of_birth;
	string university;
	string major;
	string job_place;
	vector<int>connections;
	vector<pair<int, int>>gr;
	vector<person*>neighber;
	int time = 0;
	bool infin = false;
public:
	
	person(int i, string n, int y, string u, string m, string j, vector<int>c);
	void display(person&);
	void display2();
	void connection_graph(vector<person*>);
	void set_gr(vector<person*>);
	void set_neigh(vector<person*>);
	void suggestion(vector<person*>);


};

