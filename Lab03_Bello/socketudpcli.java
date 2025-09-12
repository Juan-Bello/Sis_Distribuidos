/**************************************************************
#                         Pontificia Universidad Javeriana
#     Autor: Juan Bello, Kevin Garay, Arley Bernal
#     Fecha: 11 de Septiembre 2025
#     Materia: Sistemas Distribuidos
#**************************************************************/
import java.net.*;
import java.io.*;
public class socketudpcli {
   public static void main(String argv[]) {
      if (argv.length == 0) {
         System.err.println("Java socketudpcli servidor");
         System.exit(1);
      }

      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

      System.out.println("Prueba de sockets UDP (cliente)");
      DatagramSocket socket;
      InetAddress address;
      byte[] mensaje_bytes = new byte[256];
      String mensaje="";
      DatagramPacket paquete;

      mensaje_bytes=mensaje.getBytes();
      try {
         System.out.print("Creando socket... ");
         socket = new DatagramSocket();
         System.out.println("ok");

         System.out.print("Capturando direcci�n de host... ");
         address=InetAddress.getByName(argv[0]);
         System.out.println("ok");

         System.out.println("Introduce mensajes a enviar:");

         do {
            mensaje = in.readLine();
            mensaje_bytes = mensaje.getBytes();
            paquete = new DatagramPacket(mensaje_bytes,mensaje.length(),address,6000);
            socket.send(paquete);
         } while (!mensaje.startsWith("fin"));
      }
      catch (Exception e) {
         System.err.println(e.getMessage());
         System.exit(1);
      }
   }
}
