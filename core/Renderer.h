#ifndef RENDERER_H
#define RENDERER_H

class Color;
class Framebuffer;
class Scene;


class Renderer
{
public:
    explicit Renderer(const Scene& scene);

    void render(Framebuffer &target);
    void abort();

private:
    void render_iterative(Framebuffer &target) const;
    void render_progressive(Framebuffer &target) const;
    Color calculate_pixel(int x, int y) const;

private:
    const Scene &scene;
    bool _abort;
};

#endif // ifndef RENDERER_H
