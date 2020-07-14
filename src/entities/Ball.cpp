#include "Ball.h"
#include <math.h>


/*
 * Constructors
 */
Ball::Ball(
    std::string name, 
    const int height,
    const int width,
    const Cordinate position
    ): 
  Entity(name, height, width, position), 
  _currentVelocity(5.0f),
  _velocity({0, 0}),
  _isHeld(true){}

void Ball::Render(SDL_Renderer *renderer){
  SDL_SetRenderDrawColor(renderer, 25, 124, 241, 255);
  SDL_RenderFillRect(renderer, &_body);
}


/*
 * Getters and setters
 */
Cordinate Ball::GetPosition()const {
  return {_body.x, _body.y};
}

void Ball::SetCannon(Cannon* cannon){
  _cannon = cannon;
}

void Ball::SetIsHeld(bool isHeld){
  _isHeld = isHeld;
}

bool Ball::GetIsHeld()const {
  return _isHeld;
}

float Ball::GetCurrentVelocity()const {
  return _currentVelocity;
}


/*
 * Methods and functions
 */
float reverse(const float num){
  if(num == 0){
    return num;
  } else if(num > 0){
    return -fabs(num);
  } else {
    return +fabs(num);
  }
}

void Ball::HandleInput(const Uint8* keyCode){
   if(keyCode[SDL_SCANCODE_SPACE]){
     _velocity.y = -5;
     _isHeld = false;
   }
}

bool Ball::_cannonCollision(){
  Cordinate pos = GetPosition();
  const Cordinate cannonPos = _cannon->GetPosition();
  const int cannonRight = cannonPos.x + _cannon->GetSize().x;

  if(
    pos.y >= cannonPos.y - (_cannon->GetSize().y / 4) && 
    pos.x >= cannonPos.x && pos.x <= cannonRight
    ){
    _velocity.y = -_currentVelocity;
    return true;
  }

  return false;
}

void Ball::_updatePosition(){
  if(!_cannonCollision()){
    Cordinate pos = GetPosition();

    const Bounds bound = _hasReachedBounds(pos);

    if(bound == top || bound == bottom){
      _velocity.y = reverse(_velocity.y);
    }

    if(bound == right || bound == left){
      _velocity.x = reverse(_velocity.x);
    }
  }

  _body.x += _velocity.x;
  _body.y += _velocity.y;
}

void Ball::_serve(){
  _body.x = _cannon->GetPosition().x + ((_cannon->GetSize().x / 2) - (_body.w / 2));
  _body.y = _cannon->GetPosition().y - _body.h;
}

void Ball::Update(){
  if(_isHeld){
    _serve();
  } else {
    _updatePosition();
  }
}

