#include "iostream"
#include <bits/stdint-intn.h>
#include <bits/stdint-uintn.h>
#include <sys/types.h>
#include <vector>

using namespace std;

class Block {

public:
  Block(unsigned width, unsigned height, unsigned depth, uint16_t density)
      : width(width), height(height), depth(depth), density(density) {}

  uint64_t Mass() {
    int64_t volume = width * depth * height;

    uint64_t mass = volume * density;

    return mass;
  };

private:
  unsigned width;
  unsigned height;
  unsigned depth;
  uint16_t density;
};

int main() {

  size_t size;
  uint16_t density;

  cin >> size >> density;

  uint64_t sum = 0;
  for (unsigned i = 0; i < size; i++) {

    unsigned width, height, depth;
    cin >> width >> height >> depth;

    Block new_block = Block(width, depth, height, density);

    sum = sum + new_block.Mass();
  }

  cout << sum << endl;

  return 0;
}