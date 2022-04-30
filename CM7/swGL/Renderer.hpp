#pragma once

#include "AllocatedVector.hpp"
#include <CountDownLatch.hpp>
#include <DrawSurface.hpp>
//#include <Windows.h>
#include <vector>
#include <memory>
#include "Triangle.hpp"
#include <DrawThread.hpp>

namespace SWGL {

    //
    // Implements the renderer which feeds the drawing threads with commands
    //
    class Renderer {

    public:
        Renderer();
        ~Renderer() = default;

    public:
        void init();
        void clearColorBuffer();
        void clearDepthBuffer();
        void drawTriangles(TriangleList &triangles);
        void finish();
        void swapBuffers();
        void shutdown();

    public:
        DrawSurface &getDrawSurface() { return m_drawSurface; }

    private:
        void synchronize();
        CountDownLatch m_latch;

    private:
        AllocatedVector<DrawThreadPtr> m_drawThreads;
        DrawSurface m_drawSurface;
    };
}
