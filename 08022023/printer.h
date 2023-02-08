#pragma once

namespace Engine {

	class Printer
	{
	public:
		void printerDefault();

	};


};

void funcTR(std::shared_ptr<Moto> MotoPtr) {
	std::cout << "Moto" << std::endl;
	std::cout << MotoPtr->getSpeed() << std::endl;
	std::cout << MotoPtr->getType() << std::endl;
}


