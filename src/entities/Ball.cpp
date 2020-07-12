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


float reverse(float num){
  if(num == 0){
    return num;
  } else if(num > 0){
    return -fabs(num);
  } else {
    return +fabs(num);
  }
}

#include <iostream>
void Ball::Update(){
  Cordinate pos = {_body.x, _body.y};
  if(_isOutOfBounds(pos)){
    if(pos.x >= (WIDTH / 2)){
      _velocity.x = reverse(_velocity.x);
    }
    if(pos.y >= (HEIGHT / 2)){
      _velocity.y = reverse(_velocity.y);
    } else {
    }
  }
  _body.x += _velocity.x;
  _body.y += _velocity.y;
}
