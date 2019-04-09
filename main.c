#include <stm8l15x.h> 

uint16_t voltage;
uint8_t level;
uint16_t level_table_mV[7][2] = 
{	
	{0, 1850},
	{1, 2050},
	{2, 2260},
	{3, 2450},
	{4, 2650},
	{5, 2850},
	{6, 3050},
};

void main( void )
{
	CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1); // 16MHz
	PWR_PVDCmd(ENABLE); // запускаем PVD
	//PWR_PVDITConfig(ENABLE);
	//enableInterrupts();

	while (1)
	{
		for(uint8_t n=0; n<=6; n++) // последовательно устанавливаем пороги  PVD 
		{
			//Delay_mks (50); // TODO
			if(PWR_GetFlagStatus(PWR_FLAG_PVDOF) == RESET) // PWR_FLAG_PVDIF
			{
				switch(n)
				{
					case 0:
					PWR_PVDLevelConfig(PWR_PVDLevel_1V85);
					break;

					case 1:
					PWR_PVDLevelConfig(PWR_PVDLevel_2V05);
					break;

					case 2:
					PWR_PVDLevelConfig(PWR_PVDLevel_2V26);
					break;

					case 3:
					PWR_PVDLevelConfig(PWR_PVDLevel_2V45);
					break;

					case 4:
					PWR_PVDLevelConfig(PWR_PVDLevel_2V65);
					break;

					case 5:
					PWR_PVDLevelConfig(PWR_PVDLevel_2V85);
					break;

					case 6:
					PWR_PVDLevelConfig(PWR_PVDLevel_3V05);
					break;

					default:
					break;
				}
			}	
			else
			{
				level = n;
				break;
			}
		}
		
		voltage = level_table_mV[level][1]; // TODO
	}
}
