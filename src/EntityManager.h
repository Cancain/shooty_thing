#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>
#include <string>
#include "Entity.h"

class EntityManager{
  private:
    std::vector<Entity*> _entities;
    SDL_Renderer* _renderer;

  public:
    EntityManager(SDL_Renderer* renderer);
    void Update();
    void Render();
    bool HasNoEntities() const;
    Entity& AddEntity(const std::string entityName, const int width, const int height);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount() const;
};

#endif
