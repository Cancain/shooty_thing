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

bool Cannon::_isOutOfBounds(int pos){
  return _body.x <= 0 || _body.x >= WIDTH;
};

void Cannon::HandleInput(const SDL_Keycode key) {
  std::cout << _body.x << std::endl;
  if(key == SDLK_RIGHT){
    int newPosition = _body.x += _velocity;
    _body.x = _isOutOfBounds(newPosition) ? 
      WIDTH - DEFAULT_CANNON_WIDTH : 
      newPosition;
  }
  if(key == SDLK_LEFT){
    int newPosition = _body.x -= _velocity;
    _body.x = _isOutOfBounds(newPosition) ? 
      0 : 
      newPosition;
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
