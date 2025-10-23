 BUTTON_LED_mapping

A bare-metal embedded C project for STM32F407 Discovery board that maps three push buttons to three LEDs using a custom GPIO driver. Each button press lights up its corresponding LED.

---

🔧 Features

- Custom GPIO driver (`gpio_driver_stm32f407disc.c/.h`)
- Register-level configuration (no HAL)
- Modular initialization for buttons and LEDs
- Macros for expressive control (`BUTTON1`, `LED1_ON`, etc.)
- Pull-down logic for button inputs
- Clean and readable `main.c` with abstraction

---

 🧩 Hardware Connections

| GPIO Pin | Role     | Connects To         |
|----------|----------|---------------------|
| PC4      | Input    | Button 1 → 3.3V when pressed |
| PC5      | Input    | Button 2 → 3.3V when pressed |
| PC6      | Input    | Button 3 → 3.3V when pressed |
| PB12     | Output   | LED 1 (Anode) → Cathode to GND via 330Ω |
| PB13     | Output   | LED 2 |
| PB14     | Output   | LED 3 |

Note: Internal pull-down resistors are enabled in firmware. External 10kΩ resistors to GND are optional.


