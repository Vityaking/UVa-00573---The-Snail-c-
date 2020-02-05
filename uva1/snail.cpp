#include <iostream>

int main()
{
	float well_height = 0, climb = 0, slide = 0, fatigue = 0, height=0, days=0, climb_loss=0; //temp=current height 
	bool success = false;
	std::cin >> well_height;
	while (well_height != 0)
	{
		std::cin >> climb;
		std::cin >> slide;
		std::cin >> fatigue;
		climb_loss = climb * (fatigue / 100);
		height = 0;
		days = 0;
		while ((height > 0) || (height < well_height))
		{
			days++;
			height += climb;
			if (height > well_height)
			{
				success = true;
				break;
			}
			height -= slide;
			climb -= climb_loss;
			if (climb < 0)
			{
				climb = 0;
			}
			if (height <= 0) 
			{
				success = false;
				break;
			}
		}
		if (success == true) std::cout << "success on day " << days<< std::endl;
		else std::cout << "failure on day " << days<< std::endl;
		std::cin >> well_height;
	}
	return 0;
}