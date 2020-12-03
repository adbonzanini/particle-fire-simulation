//
//  main.cpp
//  sdlTest
//
//  Created by Angelo Bonzanini on 12/1/20.
//

#include <SDL.h>
#include <iostream>
#include "Screen.hpp"
using namespace std;
using namespace adb;

int main(int argc, const char * argv[]) {
    
    Screen screen;
    if(screen.init()==false){
        cout << "Error initializing SDL" << endl;
    }
    
    while (true) {
        //Update particles
        //Draw particles
        //Check for messages/events
        if(screen.processEvents()==false){
            break;
        }
    }
    
    screen.close();
    
    return 0;
}
