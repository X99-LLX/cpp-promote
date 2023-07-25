#include "kRingBuffer.h"
#include "iostream"



int main() {
    std::cout << "Hello KRingBuffer!" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    KRingBuffer<int> ringBuffer(2);

    for (int i = 1; i <= 6; i++) {
        ringBuffer.push(i);
        std::cout << "���: " << i << ", ��С: " << ringBuffer.getSize() << ", ����: " << ringBuffer.getCapacity() << std::endl;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;

    for (int i = 0; i < 6; i++) {
        std::cout << "�Ƴ�: " << ringBuffer.pop() << ", ��С: " << ringBuffer.getSize() << ", ����: " << ringBuffer.getCapacity() << std::endl;
    }

    return 0;
}