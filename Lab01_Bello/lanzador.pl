#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Juan Esteban Bello Durango
#     Fecha: 15 de Agosto 2025
#     Materia: Sistemas Distribuidos
#     Tema: Taller de Evaluación de Rendimiento
#     Fichero: script automatización ejecución por lotes 
#****************************************************************/

# Obtiene el directorio actual de trabajo
$Path = `pwd`;
chomp($Path);  # Elimina el salto de línea del comando pwd

# Nombre del ejecutable a probar
$Nombre_Ejecutable = "mmClasicaOpenMP";

# Tamaños de matriz a evaluar
@Size_Matriz = ("200","324","432","578","780","1036","1254","1410","1676","1892","2034","2592");

# Números de hilos OpenMP a probar
@Num_Hilos = (1,2,4,8,16,20);

# Número de repeticiones para cada combinación (tamaño, hilos)
$Repeticiones = 30;

# Bucle anidado para ejecutar todas las combinaciones
foreach $size (@Size_Matriz){        # Para cada tamaño de matriz
	foreach $hilo (@Num_Hilos) {      # Para cada número de hilos
		# Construye el nombre del archivo de resultados
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";
		
		# Ejecuta el programa 30 veces para obtener datos estadísticos
		for ($i=0; $i<$Repeticiones; $i++) {
			# Ejecuta el programa y redirige la salida al archivo
			system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");
			# Muestra progreso en pantalla
			printf("$Nombre_Ejecutable $size $hilo \n");
		}
		close($file);  # Cierra el archivo
	$p=$p+1;  # Contador de progreso (no se usa después)
	}
}
