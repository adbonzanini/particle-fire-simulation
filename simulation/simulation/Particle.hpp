//
//  Particle.hpp
//  simulation
//
//  Created by Angelo Bonzanini on 12/4/20.
//

#ifndef Particle_hpp
#define Particle_hpp
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

namespace adb {

struct Particle{ // Difference b/w class and struct is that struct variables are public by default
    double m_x;
    double m_y;
    double m_speed;
    double m_direction;
    
public:
    Particle();
    virtual ~Particle();
    void update(int interval);
};



class Swarm{
public:
    const static int NPARTICLES = 5000;
private:
    Particle * m_pParticles;
    int lastTime;
public:
    Swarm();
    virtual ~Swarm();
    const Particle * const getParticles(){return m_pParticles;};
    void update(int elapsed);
};

}

#endif /* Particle_hpp */
