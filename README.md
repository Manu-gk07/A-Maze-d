# A-Maze-d - Solucionador de Laberintos Multi-Robot

## Descripción

Simulación de flujo de grafos que coordina múltiples robots para resolver laberintos de forma óptima. El programa calcula múltiples caminos paralelos desde entrada a salida y distribuye robots para minimizar tiempo total.

---

## Algoritmos Clave

### 1. **BFS (Breadth-First Search)**
- **Uso**: Calcular distancia mínima desde cada sala a la salida
- **Complejidad**: O(V + E) donde V=salas, E=túneles
- **Impacto**: Permite saber qué camino es más corto

### 2. **Extracción de Caminos Disjuntos**
- **Uso**: Encontrar múltiples rutas paralelas sala_inicio → sala_salida
- **Complejidad**: O(V + E)
- **Impacto**: Permite paralelismo entre robots

### 3. **Optimización Greedy de Distribución**
- **Uso**: Asignar robots a caminos minimizando `longitud_camino + robots_asignados`
- **Complejidad**: O(K × P × log P) donde K=robots, P=caminos
- **Impacto**: Minimiza tiempo total de ejecución

---

## Módulos

| Archivo | Responsabilidad |
|---------|-----------------|
| `parsing.c` | Leer input, construir grafo |
| `algo.c` | Calcular caminos y distribuir robots |
| `calcul_distance.c` | BFS desde salida |
| `move_robots.c` | Simular movimiento |
| `graphical.c` | Renderizado CSFML |

---

## Compilación y Ejecución

```bash
make              # Compilar
./amazed < input  # Ejecutar con archivo de entrada
make clean        # Limpiar objetos
make fclean       # Limpiar todo
```

### Formato Input

```
3
#rooms
room1 0 0
room2 5 5
#tunnels
room1-room2
##start
room1
##end
room2
```

### Salida

```
#number_of_robots
3
#rooms
...
1-0 1-1 2-0    # turno1: robot1 paso0→1, robot1 paso1, robot2 paso0
1-1 1-2 2-1    # turno2: ...
```

---

## Complejidad

| Operación | Complejidad |
|-----------|------------|
| Parseo | O(V + E) |
| BFS | O(V + E) |
| Extracción caminos | O(V + E) |
| Distribución | O(K × P × log P) |
| Simulación | O(S × K) |

---

## Habilidades Demostradas

✓ Teoría de grafos (BFS, caminos paralelos)
✓ Algoritmos de optimización (greedy)
✓ Gestión de memoria (malloc/free)
✓ Estructuras de datos complejas
✓ Renderizado gráfico 2D (CSFML)
✓ Programación modular

