/*PROYECTO FINAL LENGUAJES DE PROGRAMACIÓN
                MOTOR DE FÍSICA


 UNIDADES A UTILIZAR:

 MASA = KILOGRAMOS = Kg
 TIEMPO = SEGUNDOS = s
 DISTANCIA = METROS = m
 VELOCIDAD  = METROS / SEGUNDOS = m/s
 ACELERACIÓN = METROS / SEGUNDOOS AL CUADRADO = m/s^2
 ACELERACIÓN DE LA GRAVEDAD = 9.8  m/s^2
 ANGULOS = GRADOS °
 CONSTANTE DE FRICCION DEL AIRE = 0.5
 RADIO DEL PROYECTIL = 20 cm = 0.2 m
 AREA DEL PROYECTIL = 5026.5 cm^2 = 50.26 m^2;
 DENSIDAD DEL AIRE = KILOGRAMOS / METROS CUBICOS = Kg/m^3
*/

#include "collisions.hpp"
#include "createobj.hpp"
#include "results.hpp"
#include "parabolicmovi.hpp"

using namespace std;

int main()
{
    Object Projectile, Target;

    double mass1, mass2;
    double height1;
    double initAng1, initVel1, denair;

    cout << "                 MOTOR DE FISICA" << endl;
    cout << endl;
    cout << endl;
    cout << "Ingrese La Masa Del Proyectil En Kilogramos" << endl;
    cin >> mass1;
    cout << endl;
    cout << "Ingrese La Altura Del Proyectil En Metros" << endl;
    cin >> height1;
    cout << endl;
    cout << "Ingrese El Angulo De Disparo De El Proyectil" << endl;
    cin >> initAng1;
    cout << endl;
    cout << "Ingrese La Velocidad De Disparo De El Proyectil" << endl;
    cin >> initVel1;
    cout << endl;
    cout << "Ingrese La Densidad Del Aire" << endl;
    cout << "Ingree Un Valor Entre 1 y 2 Kg/m^3" << endl;
    cin >> denair;
    cout << endl;
    cout << "Ingrese La Masa Del Objetivo En Kilogramos" << endl;
    cin >> mass2;
    cout << endl;
    cout << endl;

    //INICIALIZACIÓN DE PROYECTIL Y OBJETIVO

    Projectile = init_projectile(mass1, height1, initAng1, initVel1, denair);
    Target = init_target(mass2);

    //CÁLCULO DE TIEMPO DE VUELO DEL PROYECTIL

    Projectile.Maximus.maxTemp = compute_time(Projectile);

    //CÁLCULO DE VELOCIDAD FINAL DEL PROYECTIL

    Projectile.Fvel = compute_Fvel(Projectile);
    Projectile.Maximus.finalVel = compute_compFvel(Projectile);

    //CÁLCULO DE LA POSICIÓN FINAL DEL PROYECTIL

    Projectile.Position = compute_position(Projectile);

    //CÁLCULO ALCANCE MÁXIMO HORIZONTAL

    Projectile.Maximus.maxRange = compute_maxrange(Projectile);

    //CÁLCULO DEL ANGULO ANTES DE LA COLISIÓN

    Projectile.Maximus.finalAng = compute_finalang(Projectile);

    print(Projectile);

    //CALCULO DE VELOCIDADES DESPUES DE LA COLISION


    Projectile.FvelCol = compute_fvelProjCol (Projectile.Fvel, mass1, mass2);
    Target.Fvel = compute_fvelTargCol(Projectile.Fvel, mass1, mass2);

    //TODAVIA NO SE IMPRIMEN LOS RESULTADOS DESPUES DE LA COLISION
    return 0;
}
