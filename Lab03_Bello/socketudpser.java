/**************************************************************
#                         Pontificia Universidad Javeriana
#     Autor: Juan Bello, Kevin Garay, Arley Bernal
#     Fecha: 11 de Septiembre 2025
#     Materia: Sistemas Distribuidos
#**************************************************************/
import java.net.*;
import java.io.*;
public class socketudpser {
   public static void main(String argv[]) {
      System.out.println("Prueba de sockets UDP (servidor)");
      DatagramSocket socket;
      boolean fin = false;

      try {

         System.out.print("Creando socket... ");
         socket = new DatagramSocket(6000);
         System.out.println("ok");

         System.out.println("Recibiendo mensajes... ");
         do {
           byte[] mensaje_bytes = new byte[256];
           DatagramPacket paquete = new DatagramPacket(mensaje_bytes,256);
           socket.receive(paquete);
           String mensaje ="";
           mensaje = new String(mensaje_bytes);
           System.out.println(mensaje);
           if (mensaje.startsWith("fin")) fin=true;
         } while (!fin);
      }
      catch (Exception e) {
         System.err.println(e.getMessage());
         System.exit(1);
      }
   }
}
