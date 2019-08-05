/* cppsrc/main.cpp */
#include <napi.h>

#ifdef _WIN32
# include <windows.h>
#else
include <X11/XKBlib.h>
#endif

using namespace Napi;

Boolean checkCapsLock(const CallbackInfo& info)
{
  // platform dependent method of determining if CAPS LOCK is on
  #ifdef _WIN32 // MS Windows version
  return Boolean::New(info.Env(), GetKeyState(VK_CAPITAL) == 1);
  #else // X11 version (Linux/Unix/Mac OS X/etc...)
  Display * d = XOpenDisplay((char*)0);
  bool caps_state = false;
  if (d)
  {
    unsigned n;
    XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
    caps_state = (n & 0x01) == 1;
  }
  return Boolean::New(info.Env(), caps_state);
  #endif
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  // checks if caplocks is on or off..
  exports.Set("status", Function::New(env, checkCapsLock));
  return exports;
}

NODE_API_MODULE(checkcaps, InitAll)