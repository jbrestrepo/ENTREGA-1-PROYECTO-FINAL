#ifndef PARABOLICMOVI_HPP
#define PARABOLICMOVI_HPP

#include <iostream>
#include <cmath>

using namespace std;

const double PI = atan(1.0)*4;      //PI = 3.14 como constante
const double g = 9.80665;          //Aceleración de la gravedad
const double c = 0.5;                 //constante de friccion del aire
const double ap = 5026.5;              //La bala tiene un radio de 20 cm, por la tanto tiene un area= 4 π (r*r) = 5026,5 cm(2)

struct Position2d
{
    double posX;
    double posY;
};

struct Velocity2d
{
    double velX;
    double velY;

};

struct Maxvalues
{
    double maxRange;
    double maxTemp;
    double finalAng;
    Velocity2d finalVel;
};

struct Object
{
    double mass;
    double height;
    double denair;                 //densidad del aire
    double initAng;
    double initVel;
    double Fvel;
    double FvelCol;
    Velocity2d vel;
    Maxvalues Maximus;
    Position2d Position;


};

double compute_time (Object projectile);

double compute_Fvel (Object projectile);

Velocity2d compute_compFvel (Object projectile);

Position2d compute_position (Object projectile);

double compute_maxrange (Object projectile);

double compute_finalang (Object projectile);

void print (Object projectile);

#endif // PARABOLICMOVI_HPP
