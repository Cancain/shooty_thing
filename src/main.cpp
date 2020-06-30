#include "Game.h"

int main(int argv, char* args[]){
  Game *game = new Game();

  game->Initialize(800, 600);
  while(game->IsRunning()){
    game->ProcessInput();
    game->Update();
    game->Render();
  }

  game->Destroy();
  return 0;
}
