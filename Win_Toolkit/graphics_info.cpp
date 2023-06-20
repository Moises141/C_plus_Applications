#include "graphics_info.h"
#include <dxgi.h>
#include <cmath>
#pragma comment(lib, "dxgi.lib")

std::wstring GraphicsInfo::getGraphicsCardInformation() const {
    DISPLAY_DEVICE displayDevice = { 0 };
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    int deviceIndex = 0;

    while (EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0)) {
        if (displayDevice.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE) {
            return displayDevice.DeviceString;
        }
        deviceIndex++;
    }

    return L"Unknown";
}

int GraphicsInfo::getVRAM() {
    IDXGIFactory* pFactory;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&pFactory));

    if (FAILED(hr)) {
        return -1;
    }

    IDXGIAdapter* pAdapter;
    hr = pFactory->EnumAdapters(0, &pAdapter);

    if (FAILED(hr)) {
        pFactory->Release();
        return -1;
    }

    DXGI_ADAPTER_DESC adapterDesc;
    hr = pAdapter->GetDesc(&adapterDesc);

    if (FAILED(hr)) {
        pAdapter->Release();
        pFactory->Release();
        return -1;
    }

    double vram = static_cast<double>(adapterDesc.DedicatedVideoMemory) / (1024 * 1024 * 1024);
    int roundedVram = static_cast<int>(std::round(vram));
    pAdapter->Release();
    pFactory->Release();
    return roundedVram;
}


