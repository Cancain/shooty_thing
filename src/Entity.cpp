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

void Entity::HandleInput(const SDL_Event& event){
  std::cout << "in entity" << std::endl;
}

void Entity::Update(){}

void Entity::Render(SDL_Renderer* renderer){
  SDL_RenderFillRect(renderer, &_body);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

