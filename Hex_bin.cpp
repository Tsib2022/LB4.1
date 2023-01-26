#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cassert>
 
char nibble_to_hex(uint8_t x) {
  if (0 <= x && x < 10) {
    return '0' + x;
  } else {
    return 'A' + x - 10;
  }
}
 
void print_in_hex(uint8_t byte) {
  std::string hex_byte = "";
  int cnt = 0;
  while (byte != 0) {
    uint8_t x = byte % 16;
    hex_byte += nibble_to_hex(x);
    byte /= 16;
    ++cnt;
  }
  while (cnt < 2) {
    hex_byte += '0';
    ++cnt;
  }
  std::reverse(hex_byte.begin(), hex_byte.end());
  std::cout << hex_byte;
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
 
int main() {
}
