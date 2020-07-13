#include "Ball.h"
#include <math.h>

Ball::Ball(
    std::string name, 
    const int height,
    const int width,
    const Cordinate position
    ): Entity(name, height, width, position), _velocity({5, 5}){}

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

void Ball::Update(){
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
