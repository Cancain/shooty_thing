#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string name, const int height, const int width, const Cordinate position): _name(name){
  _body = {
    position.x,
    position.y,
    width,
    height,
  };
}

bool Entity::_isOutOfBounds(const Cordinate pos){
  const bool XOob = pos.x <= 0 || pos.x >= WIDTH - _body.w;
  const bool YOob = pos.y <= 0 || pos.y >= HEIGHT - _body.h;
  return XOob && YOob;
}

void Entity::HandleInput(const SDL_Event& event){
  std::cout << "in entity" << std::endl;
}

void Entity::Update(){}

void Entity::Render(SDL_Renderer* renderer){
  SDL_RenderFillRect(renderer, &_body);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

