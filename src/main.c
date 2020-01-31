#include "main.h"

bool on, off;

int appMain(gecko_configuration_t *config)
{

  // Initialize stack
  gecko_init(config);
  gpioInit();
  cmuInit();
  letimerInit();
  energyConfig();

  gpioLed0SetOn();

  /* Infinite loop */
  while (1)
  {
	  toggleLed();
	  if (energy_mode != 0)
	  {
		  goToSleep();
	  }

  }
}

void toggleLed(void)
{
	  if (irq_flg == 0)
	  {
		  gpioLed0SetOn();
	  }
	  if (irq_flg == 1)
	  {
		  gpioLed0SetOff();
	  }
}




