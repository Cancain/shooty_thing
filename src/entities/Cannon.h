#ifndef CANNON_H
#define CANNON_H

#include "../Entity.h"
#include "../Constants.h"


class Cannon : public Entity {
  private: 
  using Entity::Entity;
   public: 
    Cannon(
        const std::string name = "Cannon", 
        const int height = DEFAULT_CANNON_HEIGHT,
        const int width = DEFAULT_CANNON_WIDTH,
        const Cordinate position = {
        WIDTH / 2 - DEFAULT_CANNON_WIDTH,
        HEIGHT - DEFAULT_CANNON_HEIGHT
        }): 
      Entity(name, height, width, position){
    }
};


#endif
