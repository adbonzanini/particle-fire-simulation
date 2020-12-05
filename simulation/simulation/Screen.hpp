//
//  Screen.hpp
//  simulation
//
//  Created by Angelo Bonzanini on 12/3/20.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <SDL.h>
#include <iostream>
using namespace std;

namespace adb {

class Screen{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
private:
    //m_ prefix indicates member variables
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
public:
    //Constructors
    Screen();
    
    //Methods
    bool init();
    bool processEvents();
    void close();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void clear();
};

} /* namespace adb */

#endif /* Screen_hpp */
