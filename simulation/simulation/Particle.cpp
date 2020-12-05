//
//  Particle.cpp
//  simulation
//
//  Created by Angelo Bonzanini on 12/4/20.
//

#include "Particle.hpp"

namespace adb{

// Constructors
Particle::Particle(): m_x(0), m_y(0) {
    m_direction = (2*M_PI*rand())/RAND_MAX;
    m_speed = (0.0001*rand())/RAND_MAX;
}
Swarm::Swarm(): lastTime(0){
    m_pParticles = new Particle[NPARTICLES];
}


// Methods
void Particle::update(int interval){
    
    double xspeed = m_speed*cos(m_direction);
    double yspeed = m_speed*sin(m_direction);
    
    m_x += xspeed*interval;
    m_y += yspeed*interval;
}



void Swarm::update(int elapsed){
    
    int interval = elapsed-lastTime;
    
    for(int i=0; i<Swarm::NPARTICLES; i++){
        m_pParticles[i].update(interval);
    }
    lastTime = elapsed;
}


// Destructors
Particle::~Particle(){
}
Swarm::~Swarm(){
    delete [] m_pParticles;
}

}
