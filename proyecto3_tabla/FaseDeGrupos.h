#ifndef FASE_DE_GRUPOS_H
#define FASE_DE_GRUPOS_H

#include "GrupoMundial.h"
#include <map>
#include <string>
using namespace std;

class FaseDeGrupos {
private:
    map<string, GrupoMundial> grupos;

public:
    void agregarGrupo(const string& nombre);
    void registrarPartidoEnGrupo(const string& grupo, const string& local, int gLocal,
                                 const string& visitante, int gVisitante);
    void mostrarTodos() const;
    GrupoMundial& operator[](const string& nombre);
};

#endif
