#include "kRingBuffer.h"
#include "iostream"



int main() {
    std::cout << "Hello KRingBuffer!" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    KRingBuffer<int> ringBuffer(2);

    for (int i = 1; i <= 6; i++) {
        ringBuffer.push(i);
        std::cout << "添加: " << i << ", 大小: " << ringBuffer.getSize() << ", 容量: " << ringBuffer.getCapacity() << std::endl;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;

    for (int i = 0; i < 6; i++) {
        std::cout << "移除: " << ringBuffer.pop() << ", 大小: " << ringBuffer.getSize() << ", 容量: " << ringBuffer.getCapacity() << std::endl;
    }

    return 0;
}