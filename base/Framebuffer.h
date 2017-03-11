#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <functional>

class Framebuffer
{
public:
    Framebuffer(short width, short height);
    virtual ~Framebuffer() = default;
    virtual bool show() = 0;
    virtual void set_pixel(short x, short y, float r, float g, float b) = 0;
    virtual void refresh() = 0;
    virtual void handle_events() = 0;
    virtual void on_quit(std::function<void()> callback) = 0;
protected:
    short width;
    short height;
}; 

#endif //ifndef FRAMEBUFFER_H
