#include "application.h"

int main(int argc, char* argv[])
{
  Application app(960, 540, "Teddy", false);
  return app.run();
}
