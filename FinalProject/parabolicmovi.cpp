#include "parabolicmovi.hpp"

//namespace Parabolicmovi {

double compute_time (Object projectile)
{
    double time;

    time = ((2*(projectile.initVel)*sin(projectile.initAng))/g);

    return time;
}

double compute_Fvel (Object projectile)
{
    double vel;

    vel = sqrt((2*(projectile.mass)*g)/((projectile.denair)*ap*c));

    return  vel;
}

Velocity2d compute_compFvel (Object projectile)
{
    Velocity2d Velocity;
    double velocityX;
    double velocityY;

    velocityX = ((projectile.initVel)*cos(projectile.initAng)*(exp(((-1*g)*(projectile.Maximus.maxTemp))/(projectile.Fvel))));    //Cálculo de la componente de la velocidad en X
    velocityY = (((projectile.initVel)*sin(projectile.initAng)*(exp(((-1*g)*(projectile.Maximus.maxTemp))/(projectile.Fvel))))-((projectile.Fvel)*(1-(exp(((-1*g)*projectile.Maximus.maxTemp)/(projectile.Fvel))))));         //Cálculo de la componente de la velocidad en Y

    Velocity.velX = velocityX;
    Velocity.velY = velocityY;

    return Velocity;

}

Position2d compute_position (Object projectile)
{
    Position2d Position;
    double positionX;
    double positionY;

    positionX = ((((projectile.initVel)*(projectile.Fvel)*cos(projectile.initAng))/g)*(1-(exp(((-1*g)*(projectile.Maximus.maxTemp))/(projectile.Fvel)))));      //Cálculo de la posición en X
    positionY = (((((projectile.Fvel)/g)*(((projectile.initVel)*sin(projectile.initAng))+(projectile.Fvel))*(1-(exp(((-1*g)*(projectile.Maximus.maxTemp))/(projectile.Fvel)))))-((projectile.Fvel)*(projectile.Maximus.maxTemp)))+(projectile.height));     //Cálculo de la posición en Y

    Position.posX = positionX;
    Position.posY = positionY;

    return  Position;
}

double compute_maxrange (Object projectile)
{
    double range;

    range = (((projectile.initVel)*(projectile.Fvel)*cos(projectile.initAng))/g);  //Cálculo del alcance máximo horizontal (distanciarecorrida en X)

    return  range;
}

double compute_finalang (Object projectile)
{
    double ang;

    ang = asin(((projectile.Maximus.maxTemp)*g)/(2*(projectile.initVel)));

    return  ang;

}

void print (Object projectile)
{
    cout << "LAS CONDICIONES FINALES PARA EL MOVIMIENTO PARABOLICO DEL PROYECTIL SON:" << endl;
    cout << endl;
    cout << endl;
    cout << "Velocidad Final Del Proyectil : " << projectile.Fvel << " m/s " << endl;
    cout << endl;
    cout << "Componente X De La Velocidad Final Del Proyectil : " << projectile.vel.velX << " m/s " << endl;
    cout << endl;
    cout << "Componente Y De La Velocidad Final Del Proyectil : " << projectile.vel.velY << " m/s " << endl;
    cout << endl;
    cout << "Tiempo De Vuelo Del Proyectil : " << projectile.Maximus.maxTemp << " s " << endl;
    cout << endl;
    cout << "Alcance Maximo Del Proyectil : " << projectile.Maximus.maxRange << " m " << endl;
    cout << endl;
    cout << "Angulo De Caida Del Proyectil : " << projectile.Maximus.finalAng << " grados " << endl;
    cout << endl;
}

//}
