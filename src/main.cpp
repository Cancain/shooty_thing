#include "Game.h"
#include "Constants.h"

int main(int argv, char* args[]){
  Game *game = new Game();

  game->Initialize(WIDTH, HEIGHT);
  while(game->IsRunning()){
    game->ProcessInput();
    game->Update();
    game->Render();
  }

  delete game;
  return 0;
}
