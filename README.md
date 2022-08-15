# hz_timer.hh
Make sure a code segment is executed under a specified Hertz rate

## Usage Example

```cpp

#include <iostream>
#include "hz_timer.hh"

int main()
{
  while (1)
  {
    if (timer.test(1,  0x01, 150))  std::cout << "Every 150ms";
    if (timer.test(1,  0x02, 700))  std::cout << "Every 700ms";
    if (timer.test(60, 0x03, 1000)) std::cout << "60 Hz / 16.6ms";
  }

  return 0;
}

```

## Parameters and return value
A unique `uuid` for each segment is necessary for assigning timespans
```cpp
bool test(unsigned hz, unsigned uuid=0, unsigned timespan=1000);
```
