#include <rosconsole_bridge/bridge.h>

REGISTER_ROSCONSOLE_BRIDGE;

int main(int argc, char **argv)
{
  logWarn("This warning should be delivered through rosconsole");
  rosconsole_bridge::deactivate();
  logWarn("This warning should be delivered through the original console_bridge output handler");
  return 0;
}
