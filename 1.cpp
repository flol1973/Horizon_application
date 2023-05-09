#include <iostream>
#include <cmath>
using namespace std;

float gravitational(float, float, float);
float gravitational(float m1,float m2,float magr21)
{
	float G = 6.674 * 10e-11;
	float force = (G * m1 * m2)/pow(magr21,3);
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
//-------------------------------------------------------------------------------
	cout << "Enter the mass of body 2 :- ";
	cin >> m2;
	cout << "Enter the coordinate of body 2 in order x , y , z\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the coordinate :- ";
		cin >> r2[i];
	}
//-------------------------------------------------------------------------------
	float r21[3];
	for (int i = 0; i < 3; i++)
	{
		r21[i] = r2[i] - r1[i];
	}
	float magr21 = sqrt(r21[0] * r21[0] + r21[1] * r21[1] + r21[2] * r21[2]);
	float force = gravitational(m1, m2, magr21);
//--------------------------------------------------------------------------------
	cout << "The force between the body are :- ";
	cout << force * r21[0] << "i + ";
	cout << force * r21[1] << "j + ";
	cout << force * r21[2] << "k ";
}