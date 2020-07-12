#include "Ball.h"

Ball::Ball(
    std::string name, 
    const int height,
    const int width,
    const Cordinate position
    ): Entity(name, height, width, position){}

void Ball::Render(SDL_Renderer *renderer){
  SDL_SetRenderDrawColor(renderer, 25, 124, 241, 255);
  SDL_RenderFillRect(renderer, &_body);
}
