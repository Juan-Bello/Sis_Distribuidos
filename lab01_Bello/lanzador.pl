#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Juan Esteban Bello Durango
#     Fecha: 15 de Agosto 2024
#     Materia: Sistemas Distribuidos
#     Tema: Taller de Evaluación de Rendimiento
#     Fichero: script automatización ejecución por lotes 
#****************************************************************/

$Path = `pwd`;
chomp($Path);

$Nombre_Ejecutable = "mmClasicaOpenMP";
@Size_Matriz = ("200","320","430","570","780","1030","1250","1410","1670","1890","2030","2260");
@Num_Hilos = (1,2,4,8,16,20);
$Repeticiones = 30;

foreach $size (@Size_Matriz){
	foreach $hilo (@Num_Hilos) {
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";
		for ($i=0; $i<$Repeticiones; $i++) {
			system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");
			printf("$Nombre_Ejecutable $size $hilo \n");
		}
		close($file);
	$p=$p+1;
	}
}
