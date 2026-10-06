#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
class Atom {
public:
	double x, y, z;
	Atom(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}	
};
int main() {
	vector<Atom> atoms;
	ifstream file("atoms.txt");
	if (!file.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	};
	int n;
	file >> n;
	double x, y, z;
	for(int i = 0; i < n; i++) {
		file >> x >> y >> z;
		atoms.push_back(Atom(x, y, z));
	}
	file.close();
double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
for (int i = 0; i < atoms.size(); i++) {
	sumX += atoms[i].x;
	sumY += atoms[i].y;
	sumZ += atoms[i].z;
}
double sumcx = sumX / atoms.size();	
double sumcy = sumY / atoms.size();
double sumcz = sumZ / atoms.size();
printf("%.3f %.3f %.3f\n", sumcx, sumcy, sumcz);
return 0;}

