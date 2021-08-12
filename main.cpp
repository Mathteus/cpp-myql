#include "main.h"

using namespace std;
int qstate;

int main() {


	bool fim = true;
	int resp;
	Conexao* conexao = new Conexao("host", "user", "senha", "database");
	Menu* menu = new Menu();

	if (conexao->conn){
		
		while (fim) {
			menu->topo();
			cout << "[0]Sair\n";
			cout << "[1]Visualizar clientes\n";
			cout << "[2]ADD clientes\n";
			cout << "R:";
			cin >> resp;

			switch (resp) {
				case 0:
					fim = false;
					break;

				case 1:
					menu->topo();
					menu->showdb(qstate, conexao->conn, conexao->resultados);
					break;

				case 2:
					menu->topo();
					menu->criarPerfil(qstate, conexao->conn, conexao->resultados);
					break;
			}
		}
		conexao->terminar();
		
	}
	else {
		puts("Connection to database has failed!");
	}

	return 0;
}
