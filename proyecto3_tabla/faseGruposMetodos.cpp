#include "FaseDeGrupos.h"

void FaseDeGrupos::agregarGrupo(const string& nombre) {
    grupos.emplace(nombre, GrupoMundial(nombre));
}

GrupoMundial& FaseDeGrupos::operator[](const string& nombre) {
    return grupos.at(nombre);
}

void FaseDeGrupos::registrarPartidoEnGrupo(const string& grupo, const string& local, int gLocal,
                                            const string& visitante, int gVisitante) {
    try {
        grupos.at(grupo).registrarPartido(local, gLocal, visitante, gVisitante);
    } catch (const MundialException& e) {
        throw MundialException("Grupo " + grupo + ": " + e.what());
    }
}

void FaseDeGrupos::mostrarTodos() const {
    for (const auto& par : grupos) {
        par.second.mostrarTabla();
    }
}