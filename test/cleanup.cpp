#include <console_bridge/console.h>
#include <rosconsole_bridge/bridge.h>

struct A {
  A(const char* hint) {
    logWarn("initializing class: %s", hint);
  }
  ~A() {
    logWarn("destroying class");
  }
};

// destructor of static instance should use the original output handler
static A a("static");

REGISTER_ROSCONSOLE_BRIDGE;

int main(int argc, char **argv)
{
  A a("local");
  return 0;
}
