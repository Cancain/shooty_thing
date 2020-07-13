#include "Ball.h"
#include <math.h>

Ball::Ball(
    std::string name, 
    const int height,
    const int width,
    const Cordinate position
    ): 
  Entity(name, height, width, position), 
  _velocity({0, 0}),
  _isHeld(true){}

void Ball::Render(SDL_Renderer *renderer){
  SDL_SetRenderDrawColor(renderer, 25, 124, 241, 255);
  SDL_RenderFillRect(renderer, &_body);
}


float reverse(const float num){
  if(num == 0){
    return num;
  } else if(num > 0){
    return -fabs(num);
  } else {
    return +fabs(num);
  }
}

void Ball::HandleInput(const SDL_Keycode key){
   if(key == SDLK_SPACE){
     _velocity.y = -5;
     _isHeld = false;
   }
}

void Ball::_updatePosition(){
  Cordinate pos = {_body.x, _body.y};
  const Bounds bound = _hasReachedBounds(pos);
  if(bound == top || bound == bottom){
    _velocity.y = reverse(_velocity.y);
  }

  if(bound == right || bound == left){
    _velocity.x = reverse(_velocity.x);
  }

  _body.x += _velocity.x;
  _body.y += _velocity.y;
}

void Ball::_serve(){
  _body.x = _cannon->GetPosition().x + (_cannon->GetSize().x / 4);
  _body.y = _cannon->GetPosition().y - _body.h;
}

void Ball::Update(){
  if(_isHeld){
    _serve();
  } else {
    _updatePosition();
  }
}

void Ball::SetCannon(Cannon* cannon){
  _cannon = cannon;
}
void Ball::SetIsHeld(bool isHeld){
  _isHeld = isHeld;
}
bool Ball::GetIsHeld(){
  return _isHeld;
}
