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
 
const uint8_t* as_bytes(const void* data) {
  return reinterpret_cast<const uint8_t*>(data);
}
 
void print_in_hex(const void* data, size_t size) {
  const uint8_t* bytes = as_bytes(data);
  for (size_t i = 0; i < size; ++i) {
    print_in_hex(bytes[i]);
    if ((i + 1) % 16 == 0) {
      std::cout << std::endl;
    } else {
      std::cout << " ";
    }
  }
}
 
void print_in_binary(const void* data, size_t size) {
  const uint8_t* bytes = as_bytes(data);
  for (size_t i = 0; i < size; ++i) {
    print_in_binary(bytes[i]);
    if ((i + 1) % 4 == 0) {
      std::cout << std::endl;
    } else {
      std::cout << " ";
    }
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
  std::cout << '\n';
  print_in_hex(0xAB);
  std::cout << '\n';
  print_in_hex(0xFF);
  std::cout << '\n';
  uint32_t u32 = 0x42;
  std::cout << "u32 bytes: ";
  print_in_hex(&u32, sizeof(u32));
  std::cout << '\n';
  uint16_t u16 = 0x42;
  std::cout << "u16 bytes: ";
  print_in_hex(&u16, sizeof(u16));
  std::cout << '\n';
  uint8_t u8 = 0x42;
  std::cout << "u8 bytes: ";
  print_in_hex(&u8, sizeof(u8));
  std::cout << '\n';
 
  uint32_t bu32 = 42;
  std::cout << "u32 bytes: ";
  print_in_binary(&bu32, sizeof(u32));
  std::cout << '\n';
  uint16_t bu16 = 42;
  std::cout << "u16 bytes: ";
  print_in_binary(&bu16, sizeof(u16));
  std::cout << '\n';
  uint8_t bu8 = 42;
  std::cout << "u8 bytes: ";
  print_in_binary(&bu8, sizeof(u8));
  std::cout << '\n';
}
