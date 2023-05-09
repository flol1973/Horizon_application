#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<double> gravitational(float m1, float m2, vector<double>post1 , vector<double> post2)
{
	vector<double> r21(3), force(3);
	for (int i = 0; i < 3; i++) 
	{
		r21[i] = post2[i] - post1[i];  // Position vector from object 1 to object 2
	}
	float magr21 = sqrt(pow(r21[0],2) + pow(r21[1], 2) + pow(r21[2], 2));
	float G = 6.674 * 10e-11;
	float force_mag = (G * m1 * m2) / pow(magr21, 3);
	for (int i = 0; i < 3; i++) 
	{
		force[i] = force_mag * r21[i];  // Gravitational force vector
	}
	return force;
}

int main()
{
	float m1, m2, r1[3], r2[3];
	//-------------------------------------------------------------------------------
	cout << "Enter the mass of body 1 :- ";
	cin >> m1;
	cout << "Enter the coordinate of body 1 in order x , y , z\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the coordinate :- ";
		cin >> r1[i];
	}
	vector<double>post1 = { r1[0],r1[1],r1[2] };
//-------------------------------------------------------------------------------
	cout << "Enter the mass of body 2 :- ";
	cin >> m2;
	cout << "Enter the coordinate of body 2 in order x , y , z\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the coordinate :- ";
		cin >> r2[i];
	}
	vector<double>post2 = { r2[0],r2[1],r2[2] };
	//-------------------------------------------------------------------------------
	
	vector<double> force = gravitational(m1, m2, post1, post2);
	//--------------------------------------------------------------------------------
	cout << "The force between the body are :- ";
	cout << force[0] << "i + ";
	cout << force[1] << "j + ";
	cout << force[2] << "k ";
}