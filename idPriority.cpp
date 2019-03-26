#include <iostream>
#include <vector>
#include <queue>

struct idPrioritas {
	int id;
	int prioritas;
};

int main() { 
	std::vector<idPrioritas> antrean;
	std::priority_queue<int> urutanPrioritas;

	while(true) {
		
		idPrioritas pengantre;

		std::cout<<"Id: ";
		std::cin>>pengantre.id;
		std::cout<<std::endl<<"Prioritas: ";
		std::cin>>pengantre.prioritas;
			
		urutanPrioritas.push(pengantre.prioritas);

		int i=0;
		while (!antrean.empty()) {
			if (antrean[i].prioritas == urutanPrioritas.top()){
				std::cout<<antrean[i].id;
				urutanPrioritas.pop();
				i=0;
			}
		i++;
		}
	}
	return 0;
}

