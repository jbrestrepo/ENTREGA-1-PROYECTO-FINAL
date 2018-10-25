#include "createobj.hpp"

//namespace Createobj {


Object init_projectile(double mass, double height, double initAng, double initvel, double denair)
{
    Object projectile;

    projectile.height = height;
    projectile.mass = mass;
    projectile.denair = denair;
    projectile.initAng = initAng;
    projectile.initVel = initvel;
    projectile.Fvel = 0;
    projectile.FvelCol = 0;

    projectile.Maximus.maxTemp = 0;
    projectile.Maximus.maxRange = 0;
    projectile.Maximus.finalAng = 0;
    projectile.Maximus.finalVel.velX = 0;
    projectile.Maximus.finalVel.velY = 0;

    projectile.vel.velX = 0;
    projectile.vel.velY = 0;

    projectile.Position.posX = 0;
    projectile.Position.posY = 0;


    return projectile;

};

Object init_target(double mass)
{
    Object target = {mass, 0, 0, 0, 0, 0, 0, {0, 0}, {0, 0, 0, {0, 0}}, {0, 0}};

    return  target;

}
//}




