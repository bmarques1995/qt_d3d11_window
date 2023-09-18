#include "D3D11Window.hpp"

D3D11Window::D3D11Window()
{
    uint32_t _width = this->width();
    uint32_t _height = this->height();
    HWND windowHandle = reinterpret_cast<HWND>(this->winId());
    m_Context = new D3D11Context(windowHandle, _width, _height);
    m_Context->SetClearColor(.0f, .5f,.25f, 1.0f);
}

D3D11Window::~D3D11Window()
{
    delete m_Context;
}

void D3D11Window::paintEvent(QPaintEvent *event)
{
    m_Context->ClearTarget();
    m_Context->Present();
}

void D3D11Window::resizeEvent(QResizeEvent *event)
{

}
