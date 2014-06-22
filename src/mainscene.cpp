#include "mainscene.h"

#include "player.h"
#include "playerrenderer.h"
#include "inpututils.h"

const int MIN_TICKS_PER_MOVE = 5;

MainScene::MainScene()
{
  player = new Player(1,1);

  playerRenderer = new PlayerRenderer();

  ticksSinceLastMove = MIN_TICKS_PER_MOVE;
}

void MainScene::render(const Graphics* g) const
{
  playerRenderer->render(player, g);
}

void MainScene::tick(const Input& i)
{
  ticksSinceLastMove++;
  if(ticksSinceLastMove > MIN_TICKS_PER_MOVE)
  {
    //hooray!
  }
}

MainScene::~MainScene()
{
}

