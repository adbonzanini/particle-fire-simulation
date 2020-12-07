//
//  main.cpp
//  sdlTest
//
//  Created by Angelo Bonzanini on 12/1/20.
//

#include <SDL.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Screen.hpp"
#include <stdlib.h>
#include <time.h>
#include "Particle.hpp"
using namespace std;
using namespace adb;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    Screen screen;
    if(screen.init()==false){
        cout << "Error initializing SDL" << endl;
    }
    
    Swarm swarm;
    
    while (true) {
        //Update particles
        //Draw particles
        int elapsed = SDL_GetTicks();
//        screen.clear(); // No longer clearing the screen, since we are bluring the particles
        swarm.update(elapsed);
        
        unsigned char green = (unsigned char) ((1+sin(elapsed*0.0005))*128);
        unsigned char red = (unsigned char) ((1+sin(elapsed*0.0006))*128);
        unsigned char blue = (unsigned char) ((1+sin(elapsed*0.0007))*128);
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0; i<Swarm::NPARTICLES; i++){
            Particle particle = pParticles[i];
            
            int x = 0.5*Screen::SCREEN_WIDTH*(particle.m_x+1);
            int y = 0.5*Screen::SCREEN_WIDTH*(particle.m_y)+Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();
         
        // Draw the screen
        screen.update();
        
        //Check for messages/events
        if(screen.processEvents()==false){
            break;
        }
    }
    
    screen.close();
    
    
    // COMMENTED OUT EXAMPLES BELOW
    // Example of bit shift operator (commented out)
    /*
    unsigned char alpha = 0xFF;
    unsigned char red = 0x12;
    unsigned char green = 0x34;
    unsigned char blue = 0x56;
    unsigned int color = 0;
    color+=alpha;
    color <<= 8;
    color+=red;
    color <<= 8;
    color+=green;
    color <<= 8;
    color+=blue;
    cout << setfill('0') << setw(8) << hex << color << endl;
    
    int color = 0x123456;
    int red = (color & 0xFF0000) >> 2*8;
    int green = (color & 0x00FF00) >> 1*8;
    int blue = (color & 0x0000FF) >> 0*8;
    
    // Example:
    // color:   10100101 01100101 11110010
    // mask:    11111111 00000000 00000000
    // result:  10100101 00000000 00000000
    
    cout << hex << red << endl;
    cout << hex << green << endl;
    cout << hex << blue << endl;
    
    // ALTERNATIVELY:
    unsigned char red2 = (color & 0xFF0000) >> 2*8;
    unsigned char green2 = (color & 0x00FF00) >> 1*8;
    unsigned char blue2 = (color & 0x0000FF) >> 0*8;
    
    cout << hex << (int)red2 << endl;
    cout << hex << (int)green2 << endl;
    cout << hex << (int)blue2 << endl;
     */
    
    
    
    
    return 0;
}
