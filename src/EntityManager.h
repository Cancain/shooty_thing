#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>
#include <string>
#include "Entity.h"

class EntityManager{
  private:
    std::vector<Entity*> entities;

  public:
    void Update();
    void Render();
    bool HasNoEntities() const;
    Entity& AddEntity(const std::string entityName);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount() const;
};

#endif
