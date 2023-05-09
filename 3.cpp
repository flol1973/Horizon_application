#include <iostream>
#include <cmath>
#include <string>

using namespace std;

float pi = 3.14;
class CelestialBody {
public:
    CelestialBody(string n, double r, double m, double d) : name(n), radius(r), mass(m), density(d) {}
    double radius;
    double mass;
    double density;
    string name;
    double volume(){
        return 4 / 3 * pi * pow(radius, 3);
    }
    double surfaceArea() { 
        return 4 * pi * pow(radius, 2); 
    }
};

class Star : public CelestialBody {
private:
    double luminosity;
    double surfaceT;
public:
    Star(string n, double r, double m, double d, double l , double t) : CelestialBody(n,r,m,d), luminosity(l), surfaceT(t){}
    double getluminosity(){
        return luminosity;
    }
    double getdurfaceT(){
        return surfaceT;
    }
};

class Planet : public CelestialBody{
private:
    int noofmoons;
    double orbitalRadius;
public:
    Planet(string n, double r, double m, double d, double o, int m_) : CelestialBody(n, r, m, d), orbitalRadius(o), noofmoons(m_){}
    // calculate the orbital speed of the planet based on its mass and orbital radius, using the gravitational constant
    double getOrbitalSpeed() { 
        return sqrt(CelestialBody::mass * 6.6743e-11 / orbitalRadius); 
    }
    int getnoofmoons(){
        return noofmoons;
    }
};

int main(){
    Star sun("Sun", 6.96e8, 1.989e30, 1408, 3.828e26, 5778); // initialize the sun with its properties
    Planet earth("Earth", 6.371e6, 5.972e24, 5515, 1.496e11, 1); // initialize the earth with its properties

    cout << earth.volume() << endl; //Volume of earth
    cout << earth.surfaceArea() << endl; //Surface area of the earth
    cout << sun.volume() << endl; //Volume of sun
    cout << sun.surfaceArea() << endl; //Surface area of the sun
    cout << earth.getOrbitalSpeed() << " " << earth.getnoofmoons() << endl;// output some properties of the earth
    cout << sun.getluminosity() << " " << sun.getdurfaceT() << endl;// output some properties of the sun

    return 0;
}