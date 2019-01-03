#include "Data.h"
#include <ctime>
#include <iostream>
#include "Vehicle.h"
#include "Optimizer.h"
#include "MaxOptimizer.h"
#include "MinOptimizer.h"

int main()
{
	srand(time(NULL));

	Data* data = new Data();
	data->LoadData("instanca1.txt");

	data->ArrangeVehiclesToTracks();
	data->print_data(true);

	data->start_optimizing(new MinOptimizer(data));
}
