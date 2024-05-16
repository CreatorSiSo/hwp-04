#include <iostream>
#include <vector>
#include <b15f/b15f.h>

double to_floating_voltage(uint16_t int_voltage) {
  return static_cast<double>(int_voltage) / 1023.0 * 5.0;
}

std::tuple<std::vector<uint16_t>, std::vector<uint16_t>> analogSequence(uint8_t channel, uint16_t start, uint16_t end, int16_t delta) {
  uint16_t steps = 1023 / 10;
  std::vector<uint16_t> inputs;
  std::vector<uint16_t> measurements(steps);

  for (uint16_t i = start; i < end; i += delta) {
    inputs.push_back(i);
  }

  B15F::getInstance().analogSequence(
    channel, measurements.data(), 0,
    channel, nullptr, 0,
    start,
    delta,
    steps
  );

  return { inputs, measurements };
}

int main() {
  B15F& drv = B15F::getInstance();

  while (true) {
    auto [inputs, measurements] = analogSequence(0, 0, 1023, 10);
    
    for (size_t i = 0; i < measurements.size(); i += 1) {
      double in = to_floating_voltage(inputs[i]);
      double out = to_floating_voltage(measurements[i]);
      std::cout << "In: " << in << ", Out:" << out << "\n";
    }
  }
}
