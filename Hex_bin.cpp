#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cassert>
 
char nibble_to_hex(uint8_t i) {
  assert(0x0 <= i && i <= 0xf);
  if (0 <= i && i < 10) {
    return '0' + i;
  } else {
    return 'A' + i - 10;
  }
}
 
void print_in_hex(uint8_t byte) {
  std::cout << nibble_to_hex(byte >> 4);
  std::cout << nibble_to_hex((byte & 0xF));
}
 
void print_in_binary(uint8_t byte) {
  uint8_t mask = 1u << 7;
  while (mask != 0) {
    std::cout << ((byte & mask) == mask);
    mask >>= 1;
  }
 
}
 
void print_in_hex(const void* data, size_t size) {
  const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
  for (size_t i = 0; i < size; ++i) {
    if (i % 16 == 0) {
      std::cout << std::endl;
    }
    print_in_hex(bytes[i]);
    std::cout << " ";
  }
}
 
void print_in_binary(const void* data, size_t size) {
  const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
  for (size_t i = 0; i < size; ++i) {
    if (i % 4 == 0) {
      std::cout << std::endl;
    }
    print_in_binary(bytes[i]);
    std::cout << " ";
  }
}
 
void test() {
  assert(nibble_to_hex(0x0) == '0');
  assert(nibble_to_hex(0x1) == '1');
  assert(nibble_to_hex(0x2) == '2');
  assert(nibble_to_hex(0x3) == '3');
  assert(nibble_to_hex(0x4) == '4');
  assert(nibble_to_hex(0x5) == '5');
  assert(nibble_to_hex(0x6) == '6');
  assert(nibble_to_hex(0x7) == '7');
  assert(nibble_to_hex(0x8) == '8');
  assert(nibble_to_hex(0x9) == '9');
  assert(nibble_to_hex(0xA) == 'A');
  assert(nibble_to_hex(0xB) == 'B');
  assert(nibble_to_hex(0xC) == 'C');
  assert(nibble_to_hex(0xD) == 'D');
  assert(nibble_to_hex(0xE) == 'E');
  assert(nibble_to_hex(0xF) == 'F');
}
int main() {
  test();
 
  print_in_hex(0x0);
  std::cout << std::endl;
  print_in_hex(0xAB);
  std::cout << std::endl;
  print_in_hex(0xFF);
  std::cout << std::endl;
 
 
}
}
