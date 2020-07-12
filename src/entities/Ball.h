#ifndef BALL_H
#define BALL_H

#include "Entity.h"
class Ball : public Entity {
  private:
    float _velocity;
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
    float GetVelocity() const;
    void SetVelocity(const float velocity);
    void Render(SDL_Renderer* renderer);
    void Update();
};

#endif
