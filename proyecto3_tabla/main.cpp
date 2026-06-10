#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "FaseDeGrupos.h"
#include "MundialException.h"

using namespace std;

int main() {
    FaseDeGrupos fase;

    // Generador de goles aleatorios entre 0 y 5
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> goles(0, 5);

    try {
        // Crear dos grupos
        fase.agregarGrupo("A");
        fase.agregarGrupo("B");

        // Equipos Grupo A
        vector<string> grupoA = {"Argentina", "Polonia", "Mexico", "Arabia Saudita"};

        // Equipos Grupo B
        vector<string> grupoB = {"Francia", "Dinamarca", "Australia", "Tunez"};

        // Agregar equipos a cada grupo
        for (const auto& equipo : grupoA) fase["A"].agregarEquipo(equipo);
        for (const auto& equipo : grupoB) fase["B"].agregarEquipo(equipo);

        // Registrar partidos aleatorios Grupo A
        for (int i = 0; i < (int)grupoA.size(); i++) {
            for (int j = i + 1; j < (int)grupoA.size(); j++) {
                int golesLocal = goles(gen);
                int golesVisitante = goles(gen);
                fase.registrarPartidoEnGrupo("A", grupoA[i], golesLocal, grupoA[j], golesVisitante);
            }
        }

        // Registrar partidos aleatorios Grupo B
        for (int i = 0; i < (int)grupoB.size(); i++) {
            for (int j = i + 1; j < (int)grupoB.size(); j++) {
                int golesLocal = goles(gen);
                int golesVisitante = goles(gen);
                fase.registrarPartidoEnGrupo("B", grupoB[i], golesLocal, grupoB[j], golesVisitante);
            }
        }

        // Mostrar todas las tablas
        cout << "\n===== TABLAS DE POSICIONES =====\n";
        fase.mostrarTodos();

        // Prueba de partido duplicado
        cout << "\nProbando excepcion de partido duplicado...\n";
        // Intencionalmente se registra un partido ya jugado en orden inverso
        fase.registrarPartidoEnGrupo("A", grupoA[1], goles(gen), grupoA[0], goles(gen));
    }
    catch (const MundialException& e) {
        cout << "[ERROR MUNDIAL] " << e.what() << endl;
    }

    /*
    Se usa catch(const MundialException& e) porque es la clase base de las
    excepciones. Gracias al polimorfismo, captura cualquier excepción derivada,
    como PartidoDuplicadoException, EquipoNoEncontradoException, etc.
    Se usa const & para no copiar la excepción y mantener eficiencia.
    */

    return 0;
}
