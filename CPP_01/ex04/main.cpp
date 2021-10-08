#include <iostream>
#include <fstream>
#include <string.h>

int	count_line(std::string file){
	int nbline = 0;
	std::string buf;
	std::ifstream	countfile(file);

	if (countfile.good() == false){
		std::cout << "This filename doesn't exist" << std::endl;
		exit(1);
	}
	while (!countfile.eof()){
		getline(countfile, buf);
		nbline++;
	}
	return (nbline);
}

std::string *read_file(std::string file, int &nblineREF)
{
	nblineREF = count_line(file);
	std::ifstream	ifile(file);
	std::string *line_tab = new std::string[nblineREF];
	for (int i = 0; i < nblineREF; i++){	
		getline(ifile, line_tab[i], '\n');
	}
	ifile.close();
	return (line_tab);
}

void	replace_file(std::string *file_tab, char **av,int &nbline){
	std::string s1 = av[2]; std::string s2 = av[3];

	for (int i = 0; i < nbline; i++){
		for (int j = 0; j < file_tab[i].length(); j++){
			if (file_tab[i].compare(j, s1.length(), s1) == 0){
				file_tab[i].replace(j, s1.length(), s2);
			}
		}
	}
	std::string		replace = av[1];
	replace.append(".replace");
	std::ofstream	ofile(replace);
	for (int i = 0; i < nbline; i++){
		ofile << file_tab[i] << std::endl;
	}
}

int main(int ac, char **av){
	if (ac != 4){
		std::cout << "This program takes 3 arguments" << std::endl;
		std::cout << "A filename and 2 strings" << std::endl;
	}	
	else{
		int nbline = 0;
		int &nblineREF = nbline;
		std::string *file_tab = read_file(av[1], nblineREF);
		replace_file(file_tab, av, nblineREF);
	}
	return (0);
}