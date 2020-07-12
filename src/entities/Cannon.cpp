#include "Cannon.h"
#include <iostream>

Cannon::Cannon(
        const std::string name,
        const int height,
        const int width,
        const Cordinate position
    ): 
  Entity(name, height, width, position), 
  _velocity(DEFAULT_CANNON_VELOCITY)
  {};

void Cannon::HandleInput(const SDL_Keycode key) {
  Cordinate newPosition = {
    _body.x,
    _body.y
  };

  if(key == SDLK_RIGHT){
    newPosition.x += _velocity;
    _body.x = _isOutOfBounds(newPosition) ? 
      WIDTH - DEFAULT_CANNON_WIDTH : 
      newPosition.x;
  }

  if(key == SDLK_LEFT){
    newPosition.x -= _velocity;
    _body.x = _isOutOfBounds(newPosition) ? 
      0 : 
      newPosition.x;
  }
}


void Cannon::Render(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &_body);
}

void Cannon::Update(){

}

void Cannon::SetVelocity(const float velocity){
  _velocity = velocity;
}

float Cannon::GetVelocity()const {
  return _velocity;
}
