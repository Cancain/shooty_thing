#include "EntityManager.h"

void EntityManager::Update(){
  for (Entity* entity : _entities){
    entity->Update();
  }
}

void EntityManager::Render(){
  for (Entity* entity : _entities){
    entity->Render();
  }
}

bool EntityManager::HasNoEntities() const {
  return _entities.size() <= 0;
}

Entity& EntityManager::AddEntity(const std::string entityName, const int width, const int height){
  Cordinate position = {
    0,
    0
  };
  Entity* entity = new Entity(entityName, height, width, position);
  _entities.push_back(entity);
  return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const {
  return _entities;
}

unsigned int EntityManager::GetEntityCount() const {
  return _entities.size();
}
