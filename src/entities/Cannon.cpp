#include "Cannon.h"
#include <iostream>

void Cannon::HandleInput (const SDL_Event &event) {
  std::cout << "in Cannon" << std::endl;
}

void Cannon::Render(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &_body);
}

void Cannon::Update(){

}
