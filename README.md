# hz_timer.hh 2.0
Make sure a code segment is executed under a specified Hertz rate.
It's not the same as polling, but at least this is a way to ensure frequency without interrupting the IP.

## Usage Example

```cpp

#include <iostream>
#include "hz_timer.hh"

int main()
{
  while (1)
  {
    if (timer.test(1,  0x01, 150))  std::cout << "Every 150ms" << std::endl;
    if (timer.test(1,  0x02, 700))  std::cout << "Every 700ms" << std::endl;
    if (timer.test(60, 0x03, 1000)) std::cout << "60 Hz / 16.6ms" << std::endl;
  }

  return 0;
}

```

## Parameters and return value
A unique `uuid` for each segment is necessary for assigning timespans
```cpp
bool test (unsigned int hz, unsigend int uuid = 0, unsigned timespan = 1000)
```
`unsigned int hz` is the frequency at which the timer must be true

`unsigned int uuid` a unique identifier is needed for each timer to store the timelapse value for comparisons

`unsigned int timelapse` time timelapse in millisecond format

`@return bool` Returns true when the timer has triggered
