#include <console_bridge/console.h>
#include <rosconsole_bridge/bridge.h>
#include <string>

struct A {
  A(const char* hint) :  hint_(hint) {
    logWarn("initializing class: %s", hint);
  }
  ~A() {
    if(hint_ == "static"){ // mimic original behavior
      rosconsole_bridge::deactivate();
    }
    logWarn("destroying class: %s", hint_.c_str());
  }
private:
  std::string hint_;
};

// destructor of static instance should use the original output handler
static A a("static");

REGISTER_ROSCONSOLE_BRIDGE;

int main(int argc, char **argv)
{
  A a("local");
  return 0;
}
