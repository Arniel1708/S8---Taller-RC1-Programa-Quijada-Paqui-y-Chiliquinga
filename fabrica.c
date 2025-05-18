#include <stdio.h>
#include <string.h>
#include "fabrica.h"

int main() {
    int opcion;
    int tiempo_disp, recursos_disp;

    printf("Ingrese tiempo total disponible: ");
    scanf("%d", &tiempo_disp);
    printf("Ingrese recursos totales disponibles: ");
    scanf("%d", &recursos_disp);

    do {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregar_producto(); break;
            case 2: editar_producto(); break;
            case 3: eliminar_producto(); break;
            case 4: calcular_totales(tiempo_disp, recursos_disp); break;
            case 5: printf("Saliendo del programa.\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}