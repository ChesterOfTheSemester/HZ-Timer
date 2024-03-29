# hz_timer.hh 2.0
Make sure a code segment is executed under a specified Hertz rate.
It's not the same as polling, but at least this is a way to ensure frequency without interrupting the IP.

## Usage Example

```cpp

#include <iostream>
#include "hz_timer.hh"

int main()
{
  while (1) {
    if (hz_timer.test(1,  0x01, 150))  std::cout << "Every 150ms" << std::endl;
    if (hz_timer.test(1,  0x02, 700))  std::cout << "Every 700ms" << std::endl;
    if (hz_timer.test(60, 0x03, 1000)) std::cout << "60 Hz / 16.6ms" << std::endl;

    if (hz_timer.test(1, 0x04, 1000*15)) break; // End after 15 seconds
  }

  return 0;
}

```

## Parameters and return value
A unique `uuid` for each segment is necessary for assigning timespans
```cpp
bool test (int hz, int uuid = 0, int timespan = 1000)
```
`unsigned int hz` Is the frequency at which the timer must be true

`int uuid` A unique identifier is needed for each timer to store the timelapse value for comparisons

`long long timelapse` Time timelapse in millisecond format

`@return bool` Returns TRUE when the timer has triggered
