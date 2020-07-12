#ifndef BALL_H
#define BALL_H

#include "Entity.h"
class Ball : public Entity {
  public:
    Ball(
        const std::string name = "Ball",
        const int height = 10,
        const int width = 10,
        const Cordinate position = {
        100,
        200
        }
    );
    void Render(SDL_Renderer* renderer);
};

#endif
