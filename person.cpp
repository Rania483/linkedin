#include "person.h"
person::person(int i, string n, int y, string u, string m, string j, vector<int>c){
	id = i;
	name = n;
	year_of_birth = y;
	university = u;
	major = m;
	job_place = j;
	for (int k = 0; k < c.size(); k++) {
		connections.push_back(c[k]);
	}
}
void person::display(person& per) {
	cout << "ID: " << per.id << endl;
	cout << "Name: " << per.name << endl;
	cout << "Year of Birth: " << per.year_of_birth << endl;
	cout << "University: " << per.university << endl;
	cout << "Major: " << per.major << endl;
	cout << "Job Place: " << per.job_place << endl;
}
void person::set_gr(vector<person*>people) {
	const int INFINITY_INT = std::numeric_limits<int>::max();
	for (vector<person*>::iterator it = people.begin(); it != people.end(); it++) {
		bool neigh = false;
		int GI = (*it)->id;
		if (GI != this->id) {
			for (int h = 0; h < this->connections.size(); h++) {
				if (this->connections[h] == GI) {
					neigh = true;
					this->gr.push_back(make_pair(GI, 1));
					break;
					
				}


			}
			if (neigh == false) {
				this->gr.push_back(make_pair(GI, INFINITY_INT));
			}

		}
	}
	
	
}
void person::set_neigh(vector<person*> people) {
	int myage = 2024 - year_of_birth;
	int neigh_age;
	vector<int> new_connections;

	for (int i = 0; i < connections.size(); i++) {
		bool valid_connection = true;
		for (vector<person*>::iterator it = people.begin(); it != people.end(); ++it) {
			if ((*it)->id == connections[i]) {
				neigh_age = 2024 - ((*it)->year_of_birth);
				if ((myage < 18 && neigh_age >= 18) || (myage >= 18 && neigh_age < 18)) {
					valid_connection = false;

					break;
				}
				if (valid_connection) {
					neighber.push_back(*it);
					new_connections.push_back(connections[i]);
				}
				
			}
			
		}
		
	}
	connections = new_connections;
}

	









void person::connection_graph(vector<person*>people) {
	bool loop = true;
	int number = people.size();
	int finish = 0;
	bool tmp=false;
	const int INFINITY_INT = std::numeric_limits<int>::max();
	while (true) {
		if (finish == number ||loop==false) {
			break;
		}
		for (vector<person*>::iterator it = people.begin(); it != people.end(); it++) {
			
			if ((*it)->time == 0 || (*it)->infin == true) {
				if ((*it)->time > number) {
					loop = false;

					break;
				}

				(*it)->infin = false;
				tmp = false;
				for (auto& pair : (*it)->gr) {
					if (pair.second == INFINITY_INT) {
						tmp = true;

						for (vector<person*>::iterator ne = (*it)->neighber.begin(); ne != (*it)->neighber.end(); ne++) {
							for (auto& pair2 : (*ne)->gr) {
								if (pair2.first == pair.first && pair2.second != INFINITY_INT) {
									pair.second = min(pair2.second, pair.second);
									tmp = false;
								}
							}
						}
						if(tmp==false)
							pair.second++;
					}
					if (tmp == true)
						(*it)->infin = true;

					

				}
				(*it)->time++;
				if ((*it)->infin == false)
					finish++;




			}
		}
	}
	


}
	
void person::display2() {
	for (auto& pair : this->gr) {
		cout << pair.first << ":" << pair.second << endl;
	}
}
void person::suggestion(vector<person*>people) {
	int number = people.size();
	const int INFINITY_INT = std::numeric_limits<int>::max();
	vector<pair<int, int>>suggest;

	int rate;
	for (vector<person*>::iterator it = people.begin(); it != people.end(); it++) {
		rate=0;
		if ((*it)->id != id) {
			if ((*it)->major == major) {
				rate += (number * 10);
			}

			if ((*it)->job_place == job_place) {
				rate += (number * 5);
			}
			if ((*it)->university == university) {
				rate += (number * 5);
			}
			if ((*it)->year_of_birth == year_of_birth) {
				rate += (number * 2);
			}
			int GI = (*it)->id;
			auto iterate = find_if(this->gr.begin(), this->gr.end(), [GI](pair<int, int>& p) {
				return p.first == GI;
				});
			if ((*iterate).second != INFINITY_INT && (*iterate).second!=1) {
				int tmp = number - ((*iterate).second);
				rate += tmp * 3;
				
				suggest.push_back(make_pair((*it)->id, rate));

			}
		}
	}
	cout << "suggestions for ID: " << (id) << endl;
	if (suggest.size ()!= 0) {
		sort(suggest.begin(), suggest.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
			});
		int s = suggest.size();
		int m = min(3, s);
		for (int i = 0; i < m; i++) {
			cout << i + 1 << "-" << suggest[i].first << endl;

		}
		}
	else {
		cout << "there is no suggestion for this user!" << endl;
	}
		cout << endl;
	

	

}