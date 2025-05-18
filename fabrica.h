#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 30

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int tiempo_unitario[MAX_PRODUCTOS];
int recursos_unitarios[MAX_PRODUCTOS];
int cantidades[MAX_PRODUCTOS];
int total_productos = 0;

void limpiar_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void agregar_producto() {
    if (total_productos >= MAX_PRODUCTOS) {
        printf("\nNo se pueden agregar más productos.\n");
        return;
    }

    printf("\nIngrese nombre del producto: ");
    limpiar_entrada();
    fgets(nombres[total_productos], MAX_NOMBRE, stdin);
    nombres[total_productos][strcspn(nombres[total_productos], "\n")] = 0; // Eliminar salto de línea

    printf("Ingrese tiempo de fabricación por unidad: ");
    scanf("%d", &tiempo_unitario[total_productos]);
    printf("Ingrese recursos por unidad: ");
    scanf("%d", &recursos_unitarios[total_productos]);
    printf("Ingrese cantidad demandada: ");
    scanf("%d", &cantidades[total_productos]);

    total_productos++;
}

void editar_producto() {
    char buscar[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a editar: ");
    limpiar_entrada();
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = 0;

    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Producto encontrado. Ingrese nuevos valores.\n");
            printf("Nuevo nombre: ");
            fgets(nombres[i], MAX_NOMBRE, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = 0;

            printf("Nuevo tiempo por unidad: ");
            scanf("%d", &tiempo_unitario[i]);
            printf("Nuevos recursos por unidad: ");
            scanf("%d", &recursos_unitarios[i]);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminar_producto() {
    char buscar[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a eliminar: ");
    limpiar_entrada();
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = 0;

    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            for (int j = i; j < total_productos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempo_unitario[j] = tiempo_unitario[j + 1];
                recursos_unitarios[j] = recursos_unitarios[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            total_productos--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcular_totales(int tiempo_disp, int recursos_disp) {
    int total_tiempo = 0, total_recursos = 0;
    for (int i = 0; i < total_productos; i++) {
        total_tiempo += tiempo_unitario[i] * cantidades[i];
        total_recursos += recursos_unitarios[i] * cantidades[i];
    }

    printf("\nTiempo total requerido: %d\n", total_tiempo);
    printf("Recursos totales requeridos: %d\n", total_recursos);

    if (total_tiempo <= tiempo_disp && total_recursos <= recursos_disp) {
        printf("La fábrica PUEDE cumplir con la demanda.\n");
    } else {
        printf("La fábrica NO PUEDE cumplir con la demanda.\n");
    }
}

void mostrar_menu() {
    printf("\nMenu:\n");
    printf("1. Agregar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Calcular producción\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
}