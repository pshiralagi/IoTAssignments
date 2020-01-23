Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

**1. How much current does a single LED draw when the output drive is set to "Strong" with the original code?**

**0.50 mA** - correct based on voltage drops accross 3k resistor and yellow LED

**2. After commenting out the standard output drive and uncommenting "Weak" drive, how much current does a single LED draw?**

**0.50 mA** - correct based on voltage drops accross 3k resistor and yellow LED

**3. Is there a meaningful difference in current between the answers for question 1 and 2? Please explain your answer, 
referencing the [Mainboard Schematic](https://www.silabs.com/documents/public/schematic-files/WSTK-Main-BRD4001A-A01-schematic.pdf) and [AEM Accuracy](https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf) section of the user's guide where appropriate.**

No, although more current can be driven in strong mode when required, for the given application the current required is low (0.5 mA) and can be driven in both weak and strong output drive modes.

**4. Using the Energy Profiler with "weak" drive LEDs, what is the average current and energy measured with only LED1 turning on in the main loop?**

The average current utilized by the board when only one LED is on is **4.67 mA**, average power is **15.49 mW**, which gives indication of energy used else **total energy over 1s is 4.31 uWh**

**5. Using the Energy Profiler with "weak" drive LEDs, what is the average current and energy measured with both LED1 and LED0 turning on in the main loop?**

The average current utilized by the board when both LEDs are on is **5.16 mA**, average power is **17.13 mW**, which gives indication of energy used else total energy over **1s is 4.76 uWh**
