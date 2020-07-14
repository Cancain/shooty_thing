#include "Cannon.h"

Cannon::Cannon(
        const std::string name,
        const int height,
        const int width,
        const Cordinate position
    ): 
  Entity(name, height, width, position), 
  _velocity(5)
  {};

void Cannon::HandleInput(const Uint8* keyState) {
  Cordinate newPosition = {
    _body.x,
    _body.y
  };

  if(keyState[SDL_SCANCODE_RIGHT]){
    newPosition.x += _velocity;
    _body.x = _isOutOfBounds(newPosition) ? 
      WIDTH - _body.w : 
      newPosition.x;
  }

  if(keyState[SDL_SCANCODE_LEFT]){
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

void Cannon::SetMainBall(Ball* ball){
  _mainBall = ball;
}

void Cannon::SetHoldsBall(bool holdsBall){
  _holdsBall = holdsBall;
}

bool Cannon::GetHoldsBall(){
  return _holdsBall;
}

Cordinate Cannon::GetSize(){
  return {_body.w, _body.h};
}
